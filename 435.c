#include <stdlib.h>

static int cmpEndAsc(const void *a, const void *b) {
    int *const ia = *(int *const *)a;
    int *const ib = *(int *const *)b;
    if (ia[1] != ib[1]) return ia[1] - ib[1];
    return ia[0] - ib[0]; // desempate por início (opcional)
}

int eraseOverlapIntervals(int** intervals, int n, int* intervalsColSize) {
    (void)intervalsColSize;
    if (n <= 1) return 0;

    qsort(intervals, n, sizeof(int*), cmpEndAsc);

    int kept = 1;                 // escolhe o que termina primeiro
    int lastEnd = intervals[0][1];

    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] >= lastEnd) { // tocar é ok
            ++kept;
            lastEnd = intervals[i][1];
        }
    }
    return n - kept;
}