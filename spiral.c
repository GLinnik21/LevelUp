#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Coordinates {
    int i, j;
} Coordinates;

void swap(int *, int *);

int main() {
    int N, M;

    printf("Введите размерность матрицы: ");
    scanf("%d%d", &N, &M);

    srand(time(0));
    int **array = (int **) malloc(sizeof(int *) * M);
    for (int i = 0; i < M; ++i) {
        array[i] = (int *) malloc(sizeof(int) * N);
        for (int j = 0; j < N; ++j) {
            array[i][j] = rand() % 9 + 1;
        }
    }

    Coordinates *coordinates = (Coordinates *) malloc(sizeof(Coordinates) * N * M);

    int iMin = 0, iMax = M - 1, jMin = 0, jMax = N - 1;

    for (int k = 0; k < M * N;) {
        for (int j = jMin; j <= jMax && k < M * N; ++j, ++k) {
            coordinates[k].i = iMin;
            coordinates[k].j = j;
        }
        iMin++;

        for (int i = iMin; i <= iMax && k < M * N; ++i, ++k) {
            coordinates[k].i = i;
            coordinates[k].j = jMax;
        }
        jMax--;

        for (int j = jMax; j >= jMin && k < M * N; --j, ++k) {
            coordinates[k].i = iMax;
            coordinates[k].j = j;
        }
        iMax--;

        for (int i = iMax; i >= iMin && k < M * N; --i, ++k) {
            coordinates[k].i = i;
            coordinates[k].j = jMin;
        }
        jMin++;
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int n = N * M;
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 1; i <= n - 1; ++i) {
            if (array[coordinates[i - 1].i][coordinates[i - 1].j] > array[coordinates[i].i][coordinates[i].j]) {
                swap(&array[coordinates[i - 1].i][coordinates[i - 1].j], &array[coordinates[i].i][coordinates[i].j]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
