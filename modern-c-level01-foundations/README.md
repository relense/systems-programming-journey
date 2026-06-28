# Level 1: Foundations (Modern C Chapters 1-8)

## Projects

✅ **Completed:**

- Hello World, Getting Started
- Merge Sort
- Numerical Derivative
- Pi Decimals
- Union-Find
- Complex Numbers
- Linear Algebra

🔄 **Work in Progress:**

- Quick Sort (range-based)

⏳ **Not Started:**

## Compile

```bash
gcc -Wall -Wextra -Werror -std=c17 -fsanitize=address -g hello.c -o hello
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
   ./hello
```
