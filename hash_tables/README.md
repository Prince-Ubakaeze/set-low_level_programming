# C - Hash Tables

An implementation of a custom Hash Table data structure in C (C89/GNU89 standard). This project uses chained linked lists (separate chaining) to cleanly resolve key conflicts and hash collisions.

## Data Structures

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## Functions Implemented

### 0. Create Hash Table
* **File:** `0-hash_table_create.c`
* **Prototype:** `hash_table_t *hash_table_create(unsigned long int size);`
* Allocates space for the wrapper structure and initializes its inner pointer arrays using `calloc` to prevent garbage values and ensure empty arrays point to `NULL`.

## Compilation
Compile files with standard strict flags:
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-hash_table_create.c -o a
```
