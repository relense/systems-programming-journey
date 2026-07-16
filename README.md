# systems-programming-journey

A hands-on path into systems programming, built through C, then Rust, aimed at a Mini Redis capstone and beyond.

## Roadmap

### [Level 1: C Foundations](./modern-c-level01-foundations)

Core C fundamentals, covering basic syntax, sorting algorithms, numerical methods, and foundational data structures:

- Hello World, Getting Started, Clock/Time
- Linear Algebra, Numerical Derivative, Pi Decimals
- Merge Sort, Quick Sort
- Union-Find
- Pointers

**Status:** complete

### [Level 2: Pointers, Memory & Data Structures](./modern-c-level02)

Six portfolio data structures, each with stack and heap allocation patterns, built from scratch:

- **[Circular Buffer](./modern-c-level02/circular)** — fixed-capacity ring buffer with wraparound indexing
- **[Linked List](./modern-c-level02/linked-list)** — singly linked list with append/remove by position
- **[Dynamic Array](./modern-c-level02/dynamic-array)** — auto-growing array with `memmove`-based insert/remove
- **[Hash Map](./modern-c-level02/hash-map)** — separate chaining, djb2 hashing, automatic rehashing on load factor
- **[Binary Search Tree](./modern-c-level02/binary-search-tree)** — recursive insert/remove/destroy, in-order successor deletion
- **[Thread-Safe Queue](./modern-c-level02/thread-safe-queue)** — FIFO queue with `pthread_mutex` protection for concurrent access

**Status:** complete

### Mini Redis (C)

A simplified Redis implementation in C, applying the data structures above to build networking, command parsing, and concurrent client handling.
**Status:** not started

### Level 3: Rust

Learn Rust, then port the C data structures and the Mini Redis implementation, comparing how the language's ownership model replaces the manual discipline C requires.
**Status:** not started

### Mini Redis (Rust)

The same Mini Redis, rebuilt in Rust.
**Status:** not started

---

## Quick Start

Each exercise directory has its own README with compilation instructions and a short explanation of the design decisions behind it.
