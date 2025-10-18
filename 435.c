#include <stdlib.h>

/* Ordena por fim crescente; em empate, por início crescente. */
static int cmpEndAsc(const void *a, const void *b) {
    int *const ia = *(int *const *)a;
    int *const ib = *(int *const *)b;
    if (ia[1] != ib[1]) return ia[1] - ib[1];
    return ia[0] - ib[0];
}

int eraseOverlapIntervals(int** intervals, int n, int* intervalsColSize) {
    (void)intervalsColSize;          // cada linha tem 2 colunas (start,end)
    if (n <= 1) return 0;

    // 1) Ordena por fim (greedy de Interval Scheduling)
    qsort(intervals, n, sizeof(int*), cmpEndAsc);
    

    // 2) Seleciona o máximo de intervalos compatíveis
    int kept = 1;
    int lastEnd = intervals[0][1];

    for (int i = 1; i < n; ++i) {
        // tocar é permitido: start >= lastEnd
        if (intervals[i][0] >= lastEnd) {
            ++kept;
            lastEnd = intervals[i][1];
        }
    }

    // 3) Remoções mínimas
    return n - kept;                 // O(n log n) tempo, O(1) espaço extra
}