/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** oelm
*/

#include "../include/my_malloc.h"

size_t total_block_size(block_t *block)
{
    return sizeof(block_t) + block->data_size;
}

block_t *get_block_after(block_t *block)
{
    if (!block->has_next)
        return NULL;
    char *block_as_char = (char *)block;
    block_as_char += total_block_size(block);
    return (block_t *)block_as_char;
}

void fix_prev_pointer(block_t *first_block)
{
    if (first_block->has_next)
        get_block_after(first_block)->prev = first_block;
}

void my_free_block(block_t *freed_block)
{
    freed_block->is_free = true;
    if (freed_block->prev) {
        block_t *prev_block = freed_block->prev;
        if (prev_block->is_free) {
            prev_block->data_size += total_block_size(freed_block);
            prev_block->has_next = freed_block->has_next;
            fix_prev_pointer(prev_block);
            freed_block = prev_block;
        }
    }
}

block_t *get_block_header(void *ptr)
{
    block_t *block = (block_t *)ptr;
    block--;
    return block;
}