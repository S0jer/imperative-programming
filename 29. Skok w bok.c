#include <stdio.h>
#include <malloc.h>


void left(int J[], int p) {
    J[p] -= 1;
    J[p - 1] += 1;
    J[p - 2] += 1;
}

void right(int J[], int p) {
    J[p] -= 1;
    J[p + 1] -= 1;
    J[p + 2] += 1;
}

void reload(int J[], int c) {
    left(J, c);
    right(J, c - 1);
    right(J, c);
}

int main() {
    int N;
    scanf("%d", &N);

    int **T;
    T = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) { T[i] = malloc(2 * sizeof(int *)); }

    for (int i = 0; i < N; ++i) {
        scanf("%d", &T[i][0]);
        scanf("%d", &T[i][1]);
    }
    int len = 80 + (T[N - 1][0] - T[0][0]);

    int *J;
    J = malloc(len * sizeof(int *));

    for (int i = 0; i < len; ++i) {
        J[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        J[T[i][0] + 40] = T[i][1];
    }


    int bool = 0;
    while (bool == 0) {
        bool = 1;
        for (int j = 0; j < len; ++j) {
            if (J[j] >= 3) {
                bool = 0;
                while (J[j] >= 3) {
                    reload(J, j);
                }
            }
        }
    }


    int pole = len - 1, l = 0;

    while (J[pole] == 0) {
        pole -= 1;
    }

    bool = 0;
    while (bool == 0) {

        for (int i = 0; i < len; ++i) {
            if (J[i] > 0) {
                l = i;
                break;
            }
        }

        if (J[pole] > 0 && J[pole + 1] > 0) {
            right(J, pole);
            pole += 2;
        }
        else if (J[pole] == 2 && J[pole - 1] > 0) { pole -= 1; }
        else if (J[pole] == 2 && J[pole + 1] == 0) {
            left(J, pole);
            right(J, pole - 1);
            pole += 1;
        }
        else if (J[pole] == 3) {
            reload(J, pole);
            pole += 2;
        }
        else if (pole == l) { bool = 1; }
        else {
            pole -= 1;
            while (J[pole] == 0) {
                pole -= 1;
            }
        }
    }

    for (int i = 0; i < len; ++i) {
        if (J[i] != 0) {
            printf("%d ", i - 40);
        }
    }


    for (int i = 0; i < N; i++) {
        free(T[i]);
    }
    free(T);

}



