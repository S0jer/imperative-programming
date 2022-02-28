#include <stdio.h>
#include <malloc.h>


int main() {
    int n, k, suma, r = 1, i, j, z, ile = 0, y, x;
    scanf("%d %d", &n, &k);
    int **T;
    int T_idx[100][100] = {0};


    T = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { T[i] = malloc(n * sizeof(int)); }

    for (x = 0; x < n; ++x) {
        for (y = 0; y < n; ++y) {
            scanf("%d", &T[x][y]);
        }
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            r = 1;
            while (i + r < n && j + r < n && i - r >= 0 && j - r >= 0) {
                suma = 0;
                if ((2 * r + 1) % 2 != 0) {
                    z = i + r;
                    for (y = j + r; y >= j - r; y--) {
                        suma += T[z][y];
                    }
                    z = i - r;
                    for (y = j + r; y >= j - r; y--) {
                        suma += T[z][y];
                    }
                    z = i + r - 1;
                    while (z > i - r) {
                        suma += T[z][j - r];
                        suma += T[z][j + r];
                        z -= 1;

                    }
                    if (suma == k) {
                        T_idx[i][j] = 1;
                        ile += 1;
                    }
                }
                r += 1;
            }
        }
    }
    printf("%d\n", ile);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (T_idx[i][j] == 1) {
                printf("%d %d", i, j);
                printf("\n");
            }
        }

    }

    for (i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);
}

