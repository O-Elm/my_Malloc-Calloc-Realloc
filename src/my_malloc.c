/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** oelm
*/

#include "../include/my_malloc.h"

block_t *heap_start = NULL;

block_t *new_block(size_t amount)
{
    size_t sbrk_size = power_two(amount + sizeof(block_t), 2 * getpagesize());
    block_t *sbrk_block = (block_t *)sbrk(sbrk_size);
    sbrk_block->data_size = sbrk_size - sizeof(block_t);
    sbrk_block->is_free = false;
    sbrk_block->has_next = false;
    return (sbrk_block);
}

block_t *my_malloc_block(size_t amount)
{
    amount = power_two(amount, 8);
    block_t *last_block = NULL;
    block_t *block = heap_start;
    while (block) {
        last_block = block;
        if (block->is_free && (block->data_size >= amount)) {
            block->is_free = false;
            return block;
        }
        block = get_block_after(block);
    }
    block_t *sbrk_block = new_block(amount);
    sbrk_block->prev = last_block;
    if (last_block) {
        last_block->has_next = true;
    } else {
        last_block = sbrk_block;
        heap_start = sbrk_block;
    }
    my_free_block(sbrk_block);
    return my_malloc_block(amount);
}

void *malloc(size_t size)
{
    if (!size)
        return NULL;
    block_t *allocated_block = my_malloc_block(size);
    allocated_block++;
    return (void *)allocated_block;
}

void free(void *ptr)
{
    if (!ptr)
        return;
    my_free_block(get_block_header(ptr));
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(size * nmemb);
    if (ptr)
        memset(ptr, 0, size * nmemb);
    return ptr;
}
