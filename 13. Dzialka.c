#include <stdio.h>
#include <malloc.h>


int main() {
    int n, i, j, p, h_min, l, h, a, b;
    scanf("%d", &n);
    int **T;

    T = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { T[i] = malloc(n * sizeof(int)); }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            scanf("%d", &T[x][y]);
        }
    }

    int p_max = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (T[i][j] == 0) {
                b = j;
                l = 0;
                h = 1;
                h_min = n;
                while (b < n && T[i][b] == 0) {
                    l += 1;
                    a = i + 1;
                    h = 1;
                    while (a < n && T[a][b] == 0) {
                        h += 1;
                        a += 1;
                    }
                    if (h < h_min) {
                        h_min = h;
                    }
                    p = h_min * l;
                    if (p > p_max) {
                        p_max = p;
                    }
                    b += 1;

                }
                if (h < h_min) {
                    h_min = h;
                }
                p = h_min * l;
                if (p > p_max) {
                    p_max = p;
                }
            }
            p = h_min * l;
            if (p > p_max) {
                p_max = p;
            }
        }
    }

    printf("%d", p_max);

    for (i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);
}


