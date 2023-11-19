//
// Created by Irene on 22/10/2023.
//

#include "indx_list.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct indx_item* indx_create_initial(size_t indx) {
    struct indx_item* res = malloc(sizeof(struct indx_item));
    res->indx = indx;
    res->next = NULL;
    res->prev = NULL;
    return res;
}

struct indx_item* indx_create_next(struct indx_item *current, size_t indx) {
    struct indx_item* res = malloc(sizeof(struct indx_item));
    res->indx = indx;
    res->next = current->next;
    res->prev = current;
    current->next = res;
    return res;
}

void indx_destroy_item(struct indx_item *current) {
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

void indx_destroy_all(struct indx_item *el) {
    while (el->prev != NULL) { el = el->prev; }
    while (el != NULL) {
        struct indx_item* el_next = el->next;
        free(el);
        el = el_next;
    }
}

void indx_print(struct indx_item *el) {
    while (el->prev != NULL) { el = el->prev; }
    while (el != NULL) {
        printf("%zu, ", el->indx);
        el = el->next;
    }
    printf("\n");
}

