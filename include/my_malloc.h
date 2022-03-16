/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** oelm
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

typedef struct block_s block_t;

struct block_s {
    block_t *prev;
    bool has_next;
    bool is_free;
    size_t data_size;
};

void *realloc(void *ptr, size_t size);
void *reallocarray( void *ptr, size_t nmemb, size_t size);
size_t power_two(size_t amount, size_t multiple_of);
size_t total_block_size(block_t *block);
block_t *get_block_after(block_t *block);
void fix_prev_pointer(block_t *first_block);
void my_free_block(block_t *freed_block);
block_t *get_block_header(void *ptr);

#endif /* !MY_H */