//
// Created by Irene on 22/10/2023.
//

#ifndef INDX_LIST_H
#define INDX_LIST_H

#include <assert.h>
#include <stddef.h>

struct indx_item {
    size_t indx;
    struct indx_item *next, *prev;
};

struct indx_item* indx_create_initial(size_t indx);

struct indx_item* indx_create_next(struct indx_item *current, size_t indx);

void indx_destroy_item(struct indx_item *current);

void indx_destroy_all(struct indx_item *el);

void indx_print(struct indx_item *el);

#endif //INDX_LIST_H
