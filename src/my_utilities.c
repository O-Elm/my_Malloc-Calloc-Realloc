/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** oelm
*/

#include "../include/my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    return NULL;
}

void *reallocarray( void *ptr, size_t nmemb, size_t size)
{
    return NULL;
}

size_t power_two(size_t amount, size_t multiple_of)
{
    size_t modulus = amount % multiple_of;
    if (modulus == 0) {
        return amount;
    } else {
        return amount + multiple_of - modulus;
    }
}