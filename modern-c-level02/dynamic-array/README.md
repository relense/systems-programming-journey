# Level 2: Dynamic Array

This exercise implements a dynamic array in C. A resizable array that grows automatically when full.
The goal was to practice heap allocation, pointer arithmetic, and `memmove` for element shifting on insert and remove operations.
The implementation also introduces an internal helper function (`duplicate_size`) to encapsulate the growth logic, keeping `append` and `insert` clean.

## Funcitions

### Functions to store in the stack

- dynamic_array_init
- dynamic_array_destroy

### Functions to store in the heap

- dynamic_array_new
- dynamic_array_delete

### Operations

- dynamic_array_append
- dynamic_array_insert
- dynamic_array_remove
- dynamic_array_get_element
- dynamic_array_resize
- dynamic_array_get_length
- dynamic_array_get_cap

## Compile

```bash
gcc -Wall -Wextra -Werror -std=c17 -fsanitize=address -g -o dynamic-array dynamic-array.c main.c
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
   ./dynamic-array
```
