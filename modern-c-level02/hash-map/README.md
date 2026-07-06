# Level 2: Hash Map

This exercise implements a hash map in C using separate chaining to resolve collisions, where each bucket holds a linked list of key-value entries. The implementation includes a djb2-based string hashing function, automatic resizing when the load factor exceeds 0.75 (which involves rehashing all existing entries into a new, larger bucket array), and dynamic key ownership via `strdup` so entries don't depend on the lifetime of the caller's string.

## Funcitions

### Functions to store in the stack

- hash_map_init
- hash_map_destroy

### Functions to store in the heap

- hash_map_new
- hash_map_delete

### Operations

- hash_map_put
- hash_map_remove
- hash_map_get
- hash_map_get_length
- hash_map_get_cap

## Compile

```bash
gcc -Wall -Wextra -Werror -std=c17 -fsanitize=address -g -o hash-map hash-map.c main.c
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
   ./hash-map
```
