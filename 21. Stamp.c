#include <stdio.h>
#include <malloc.h>


int main() {
    int n, k, l, i, j;
    scanf("%d %d %d", &n, &k, &l);
    int **T, **P;

    T = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { T[i] = malloc(n * sizeof(int)); }

    P = malloc(k * sizeof(int *));
    for (i = 0; i < k; i++) { P[i] = malloc(l * sizeof(int)); }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &T[i][j]);
        }
    }
    for (int m = 0; m < k; ++m) {
        for (int i1 = 0; i1 < l; ++i1) {
            scanf("%d", &P[m][i1]);
        }
    }
    int suma_max = 0;
    for (int m = 0; m < n - k; ++m) {
        for (int i1 = 0; i1 < n - l; ++i1) {
            int suma = 0;
            for (int j1 = 0; j1 < k; ++j1) {
                for (int k1 = 0; k1 < l; ++k1) {
                    if (P[j1][k1] == 1) {
                        suma += T[m + j1][i1 + k1];
                    }

                }
            }
            if (suma > suma_max) {
                suma_max = suma;
            }

        }

    }

    printf("%d", suma_max);

    for (i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);

    for (i = 0; i < k; i++) {
        free(P[i]);
    }
    free(P);


}

