#include <stdio.h>
#include <malloc.h>


int abss(int a) {
    if (a >= 0) {
        return a;
    } else {
        a *= -1;
        return a;
    }
}

int main() {
    int n, k, l, i, j;
    scanf("%d %d", &n, &k);
    int **T;

    T = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { T[i] = malloc(n * sizeof(int)); }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &T[i][j]);
        }
    }

    int suma_max = 0, n_l = n - 1;
    for (int m = 0; m < n; ++m) {
        for (int i1 = 0; i1 < n; ++i1) {
            int suma_wl = 0, suma_kd = 0, suma_kg = 0, suma_wp = 0, suma_sd = 0, suma_sg = 0, suma_sgp = 0, suma_sdl = 0;
            int i_sq = 0, i_sd = 0, i_sdl = 0, i_sqp = 0;
            for (int j1 = 0; j1 < k; ++j1) {

                if (i1 + j1 < n) {
                    suma_wp += T[m][i1 + j1];
                } else { suma_wp += T[m][i1 + j1 - n]; }

                if (i1 - j1 > -1) {
                    suma_wl += T[m][i1 - j1];
                } else { suma_wl += T[m][n + (i1 - j1)]; }

                if (m + j1 < n) {
                    suma_kd += T[m + j1][i1];
                } else { suma_kd += T[m + j1 - n][i1]; }

                if (m - j1 > -1) {
                    suma_kg += T[m - j1][i1];
                } else { suma_kg += T[n + (m - j1)][i1]; }


                suma_sd += T[(m + j1)%n][(i1 + j1)%n];
                suma_sgp += T[(n - abss(m - j1))%n][ (i1 + j1)%n];
                suma_sg += T[abss(n + (m - j1))%n][abss(n + (i1 - j1))%n];
                suma_sdl += T[ (m + j1)%n][(n + (i1 - j1))%n];
                //printf("%d %d \n", (m + j1)%n, (n + (i1 - j1))%n);

            }
            if (suma_sd > suma_max) { suma_max = suma_sd; }
            if (suma_sg > suma_max) { suma_max = suma_sg; }
            if (suma_sdl > suma_max) { suma_max = suma_sdl; }
            if (suma_sgp > suma_max) { suma_max = suma_sgp; }
            if (suma_wp > suma_max) { suma_max = suma_wp; }
            if (suma_wl > suma_max) { suma_max = suma_wl; }
            if (suma_kd > suma_max) { suma_max = suma_kd; }
            if (suma_kg > suma_max) { suma_max = suma_kg; }
        }
    }

    printf("%d", suma_max);

    for (i = 0; i < n; i++) {
        free(T[i]);
    }
    free(T);

}



