#include <stdio.h>


int main() {
    int n = 0, i, j, r, suma, z, y;
    scanf("%d %d", &n, &r);
    int tab[n][n], T[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            suma = 0;
            for (z = i + r; z >= i - r; z--) {
                for (y = j + r; y >= j - r; y--) {
                    if (0 <= z && z < n && 0 <= y && y < n) {
                        suma += tab[z][y];
                    }
                }
            }
            T[i][j] = suma;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
}