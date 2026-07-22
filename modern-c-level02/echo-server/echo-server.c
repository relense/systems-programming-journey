#include <sys/types.h> // basic system data types (used by socket-related structs)
#include <sys/socket.h> // socket(), bind(), listen(), accept(), send(), recv()
#include <netinet/in.h> // sockaddr_in, sockaddr_in6, htons(), IPPROTO_* constants
#include <netdb.h>  // getaddrinfo(), freeaddrinfo(), gai_strerror(), struct addrinfo
#include <stdlib.h>  // exit(), EXIT_SUCCESS
#include <stdio.h>  // printf(), fprintf()
#include <string.h> // because of memset
#include <arpa/inet.h> // to use inet_ntop
#include <unistd.h> // to use close()
#include <pthread.h> // to create and manage threads

#define BACKLOG 10 // Max connections waiting
#define MAXDATASIZE 100 // Max number of bytes we can get at once

typedef struct {
    struct sockaddr_storage addr;
    int file_descriptor;
} client_data;

//Get the ip address that can be IPv4 or IPv6
void* get_in_addr(struct sockaddr* socket_addr) {
    if(socket_addr->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)socket_addr)->sin_addr);
    }

    return &(((struct sockaddr_in6*)socket_addr)->sin6_addr);
}
 
void* handle_client(void* args) {
    client_data* data = (client_data*) args;
    struct sockaddr_storage their_addr = data->addr;
    int new_file_descriptor = data->file_descriptor;

    ssize_t recv_bytes;
    char buf[MAXDATASIZE];
    char client_ip_string[INET6_ADDRSTRLEN]; // ip_address with the size of an IPv6

    // convert the ip address, that is in binary, to a string
    inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr*) &their_addr), client_ip_string, sizeof client_ip_string);
    printf("server: got connection from %s\n", client_ip_string);

    // receive the data from the client and echo it back until the connection closes
    while((recv_bytes = recv(new_file_descriptor, buf, MAXDATASIZE - 1, 0)) > 0) {
        if (recv_bytes > 0 && buf[recv_bytes- 1] == '\n') {
            buf[recv_bytes - 1] = '\0';
        } else {
            buf[recv_bytes] = '\0';
        }
        
        printf("server: received '%s'\n", buf);
        
        send(new_file_descriptor, buf, recv_bytes, 0);
    }
    
    // close this client's connection before accepting the next one
    close(new_file_descriptor);
    printf("server: client disconnected, waiting for new connections...\n");

    free(args);

    return NULL;
}

int main(void) {
    int socket_file_descriptor;
    int new_file_descriptor;
    struct addrinfo hints;
    struct addrinfo* server_info;
    struct addrinfo* addr;
    socklen_t sockaddr_in_size; // size of the client addr
    struct sockaddr_storage their_addr; // addr info of whos connecting
    int reuse_addr = 1; // 1 means activate, 0 means deactivate the reuse of the addr
    int get_addr_info_status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // can be either IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream socket
    hints.ai_flags = AI_PASSIVE;

    if((get_addr_info_status = getaddrinfo(NULL, "8080", &hints, &server_info)) != 0) {
        fprintf(stderr, "gai error: %s\n", gai_strerror(get_addr_info_status));
        exit(1);
    }

    // loop to see if there is an available connection
    for(addr = server_info; addr != NULL; addr = addr->ai_next) {
        // create the socket file descriptor
        if((socket_file_descriptor = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }

        // allow reusing the port immediately after the server restarts
        if(setsockopt(socket_file_descriptor, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }


        // associate the socket with a port on my local machine
        if(bind(socket_file_descriptor, addr->ai_addr, addr->ai_addrlen) == -1) {
            close(socket_file_descriptor);
            perror("server: bind");
            continue;
        }

        break;
    }

    // we don't need the linked list anymore so we can free it
    freeaddrinfo(server_info);

    // if we didn't get any element from the linked list then we can't do anything so lets exit
    if(addr == NULL) {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if(listen(socket_file_descriptor, BACKLOG) == -1) {
        perror("server: listen");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    // this while accepts new clients
    while(1) {
        sockaddr_in_size = sizeof their_addr;
        new_file_descriptor = accept(socket_file_descriptor, (struct sockaddr*) &their_addr, &sockaddr_in_size);

        if(new_file_descriptor == -1) {
            perror("accept");
            continue;
        }


        client_data* data = malloc(sizeof(client_data));
        if(!data) {
            perror("malloc failed");
            continue;
        }
        
        *data = (client_data) {
            .file_descriptor = new_file_descriptor,
            .addr = their_addr,
        };

        pthread_t th;
        if(pthread_create(&th, NULL, &handle_client, data) != 0) {
            perror("failed to create thread");
            free(data);
            continue;
        } 
        
        pthread_detach(th);
        
    }

    return EXIT_SUCCESS;
}