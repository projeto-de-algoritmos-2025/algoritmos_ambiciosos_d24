#include <stdlib.h>

static int cmpStartAsc(const void *a, const void *b) {
    int *const ia = *(int *const *)a;  // [start, end]
    int *const ib = *(int *const *)b;
    if (ia[0] != ib[0]) return ia[0] - ib[0];
    return ia[1] - ib[1];
}

int eraseOverlapIntervals(int** intervals, int n, int* intervalsColSize) {
    (void)intervalsColSize;
    if (n <= 1) return 0;

    qsort(intervals, n, sizeof(int*), cmpStartAsc);

    int removals = 0;
    int prevEnd = intervals[0][1];

    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] < prevEnd) {
            // conflito: removemos UM e ficamos com o que termina antes
            ++removals;
            if (intervals[i][1] < prevEnd) prevEnd = intervals[i][1];
        } else {
            // sem sobreposição (tocar é permitido: start >= prevEnd)
            prevEnd = intervals[i][1];
        }
    }
    return removals;
}