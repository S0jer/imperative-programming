#include <stdio.h>
#include <malloc.h>

int main() {
    int n, m, i, p, q;
    scanf("%d %d", &n, &m);
    int *T;

    T = malloc((n + 1) * sizeof(int*));
    for (int j = 0; j < n + 1; ++j) {T[j] = 0;}


    for (i = 0; i < m; ++i) {
        scanf("%d %d", &p, &q);
        T[p] += 1;
        T[q] += 1;
    }

    int triangle = (((n) * (n - 1) * (n - 2)) / 6), traingle_r = 0;

    for (int j = 1; j < n + 1; ++j) {
        traingle_r += (T[j]*(n - 1 - T[j]))/2;

    }
    triangle = triangle - traingle_r;
    printf("%d", triangle);


    free(T);
}