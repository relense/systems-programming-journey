# Level 2: Circular Buffer

This exercise implements a circular buffer in C, used to practice manual memory management, pointer arithmetic, and dynamic allocation with `malloc` and `free`.
The implementation covers both stack and heap allocation patterns, along with the core operations expected from a circular buffer data structure.

## Funcitions

### Functions to store in the stack

- circular_init
- circular_destroy

### Functions to store in the heap

- circular_new
- circular_delete

### Operations

- circular_append
- circular_pop
- circular_element
- circular_resize
- circular_getlength
- circular_getcap

## Compile

```bash
gcc -Wall -Wextra -Werror -std=c17 -fsanitize=address -g -o circular-buffer circular-buffer.c main.c
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

  ## Run

```bash
   ./circular-buffer
```
