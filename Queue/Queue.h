//
// Created by Глеб Линник on 09.12.16.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H



typedef struct Queqe {
    int value;
    Queqe *start;
    Queqe *next;
} Queqe;

Queqe *init();
bool add(Queqe **, int);
int take(Queqe **);
int watch(Queqe *);
void printQueqe(Queqe *);
void clearQueqe(Queqe **);

#endif //QUEUE_QUEUE_H
