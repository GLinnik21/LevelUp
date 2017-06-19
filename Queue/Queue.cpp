//
// Created by Глеб Линник on 09.12.16.
//

#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

Queqe *init() {
    Queqe *temp = (Queqe*)malloc(sizeof(Queqe));
    temp->value = 0;
    temp->start = temp;
    temp->next = NULL;
    return temp;
}

bool add(Queqe **queqe, int value) {
    bool res = true;

    Queqe *newElement = (Queqe*)malloc(sizeof(Queqe));

    if (newElement == NULL) {
        res = false;
    } else {
        newElement->value = value;
        newElement->start = (*queqe)->start;
        newElement->next = NULL;
        (*queqe)->next = newElement;
        *queqe = newElement;
    }

    return res;
}

int take(Queqe **queqe) {
    assert(*queqe != (*queqe)->start);

    int value = (((*queqe)->start)->next)->value;
    (*queqe)->start = ((*queqe)->start)->next;
    free((*queqe)->start);

    return value;
}

int watch(Queqe *queqe) {
    return ((queqe->start)->next)->value;;
}

void printQueqe(Queqe *queqe) {
    if (queqe->next == NULL)
        return;
    queqe = (queqe->start)->next;
    while (1) {
        printf("%d\n", queqe->value);
        if (queqe->next == NULL) break;
        queqe = queqe->next;
    }
}

void clearQueqe(Queqe **queqe) {
    while (1) {
        take(queqe);
        if ((*queqe) == (*queqe)->start) break;
    }
}

