#include <stdio.h>



int main() {
    int n = 0, i, j;
    scanf("%d", &n);
    int tab[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    int T[n * n], idx = 0, x, t = 0, replace, z = -1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++){
            T[idx] = tab[j][i];
            z += 1; x = z;
            if (x > 0){
                while ( T[x-1] >= T[x]  && x > t){
                    if (T[x] == T[x - 1]){replace = T[t]; T[t] = T[x]; T[x] = replace; t += 1;}
                    replace = T[x - 1];
                    T[x - 1] = T[x];
                    T[x] = replace;
                    x -= 1;
                }
            }
            idx += 1;
        }
    }
    for (t; t < n*n; t++) {
        printf("%d ", T[t]);
    }
}

