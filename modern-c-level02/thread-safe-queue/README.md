# Level 3: Thread Safe Queue

This exercise implements a thread safe FIFO queue in C, protected by a pthread mutex and using a condition variable so that dequeue blocks efficiently until an element becomes available, instead of busy waiting or failing immediately on an empty queue. The queue itself is a singly linked list with head and tail pointers, giving constant time enqueue and dequeue at both ends.

## Funcitions

### Functions to store in the stack

- th_queue_init
- th_queue_destroy

### Functions to store in the heap

- th_queue_new
- th_queue_delete

### Operations

- th_queue_enqueue
- th_queue_dequeue
- th_queue_get_length

## Compile

```bash
gcc -Wall -Wextra -Werror -std=c17 -fsanitize=address -g -o thread-safe-queue.out thread-safe-queue.c main.c -lpthread
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
   ./thread-safe-queue
```
