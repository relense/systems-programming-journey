# Level 2: Echo Server

This exercise implements a multi threaded TCP echo server in C, the first step into networking after finishing the six data structure exercises. It walks through the full socket lifecycle: resolving a local address with getaddrinfo, creating and configuring the socket, binding it to a port, listening for connections, and accepting clients. Each accepted client is handed off to its own detached thread, which reads messages with recv and echoes them straight back with send until that client disconnects, allowing multiple clients to be served concurrently instead of one at a time. This server was built while reading Beej's Guide to Network Programming, and serves as the foundation for the eventual Mini Redis server.

## Compile

```bash
gcc -Wall -Wextra -Werror -std=c17 -fsanitize=address -g -o echo-server.out echo-server.c -lpthread
```

- **gcc** - The compiler. The program that transforms C into an executable.
- **-Wall** - "Warnings ALL"
  - Shows ALL warnings (suspicious code, unused variables, etc)
  - Example: if you have a variable you never use, it warns you
- **-Wextra** - "Warnings EXTRA"
  - More warnings beyond -Wall
  - Even more strict
  - Example: strange comparisons, non-intuitive things
- **-Werror** - "Warnings are ERRORS"
  - If there's a warning, **it won't compile**
  - Forces you to write flawless code from the start
  - Without it, it would compile even with warnings (bad)
- **-std=c17** - "Standard C17"
  - Specifies which version of C to use
  - C17 is the most recent (released in 2018)
  - Guarantees modern features and security
- **-fsanitize=address** - "Address Sanitizer"
  - Detects memory errors **during execution**
  - Like Valgrind, but faster
  - Warns if:
    - You free memory and continue using it (use-after-free)
    - You write outside the bounds of an array
    - Memory leaks (you allocated but never freed)
- **-g** - "Debug symbols"
  - Includes debug information in the executable
  - If the program crashes, you see exactly which line
  - Without it you'd see strange numbers instead of line numbers
- **-lm** - "Link math"
  - If the program needs math functions and includes the math.h
- **-lpthread** - "Link pthread"
  - Links the POSIX threads library
  - Needed whenever the program uses `pthread_create`, `pthread_mutex_t`, `pthread_cond_t`, or any other pthread function
  - Without it, the linker won't find the implementations of these functions and compilation fails

  ## Run

```bash
   ./echo-server.out
```
