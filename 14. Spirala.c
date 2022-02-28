#include <stdio.h>
#include <malloc.h>

int main() {
    int n, i, j, number = 0, z = 0;
    int a, b, c;
    scanf("%d", &n);
    int **T;

    T = malloc(n * sizeof(int*));

    for(i = 0; i < n; i++) {
        T[i] = malloc(n * sizeof(int));
    }

    i = 0; j = 0;

    while (z <= n / 2) {
        for (a = j; a < n - z; ++a) {
            number += 1;
            T[i][a] = number;
        }
        a -= 1;
        for (b = i; b < n - z; ++b) {
            T[b][a] = number;
            number += 1;
        }
        b -= 1;
        number -= 1;
        for (c = a; c > z; --c) {
            T[b][c] = number;
            number += 1;
        }
        for (int d = b; d > z; --d) {
            T[d][c] = number;
            number += 1;
        }
        number -= 1;
        i += 1;
        j += 1;
        z += 1;
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            printf("%d ", T[x][y]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);

}

