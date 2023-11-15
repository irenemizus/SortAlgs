//
// Created by Irene on 22/10/2023.
//

#ifndef INDX_LIST_H
#define INDX_LIST_H

#include <assert.h>

struct indx_item {
    size_t indx;
    struct indx_item *next, *prev;
};

struct indx_item* indx_alloc_initial(size_t indx) {
    struct indx_item* res = malloc(sizeof(struct indx_item));
    res->indx = indx;
    res->next = NULL;
    res->prev = NULL;
    return res;
}

struct indx_item* indx_alloc_next(struct indx_item *current, size_t indx) {
    struct indx_item* res = malloc(sizeof(struct indx_item));
    res->indx = indx;
    res->next = current->next;
    res->prev = current;
    current->next = res;
    return res;
}

void indx_free_item(struct indx_item *current) {
    if (current->prev != NULL && current->next != NULL) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    } else if (current->next != NULL) {
        assert(current->prev == NULL);
        current->next->prev = NULL;
    } else if (current->prev != NULL) {
        assert(current->next == NULL);
        current->prev->next = NULL;
    } else {
        assert(current->prev == NULL);
        assert(current->next == NULL);
    }

    free(current);
}

void indx_print(struct indx_item *el) {
    while (el->prev != NULL) { el = el->prev; }
    while (el != NULL) {
        printf("%zu, ", el->indx);
        el = el->next;
    }
    printf("\n");
}


#endif //INDX_LIST_H
