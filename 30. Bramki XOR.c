#include <stdio.h>
#include <malloc.h>


int main() {
    int n, m, id, **T, down = 0, up = 0, *gates;
    scanf("%d %d %d", &n, &m, &id);

    T = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) { T[i] = malloc(2 * sizeof(int *)); }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &T[i][0], &T[i][1]);
    }

    char n_d[m], n_u[m];
    scanf("%s", n_d);
    scanf("%s", n_u);

    int x = 1;
    for (int i = n - 1; i > -1; --i) {
        if (n_d[i] == '1') { down += x; }
        if (n_u[i] == '1') { up += x; }
        x *= 2;
    }

    gates = malloc(m * sizeof(int *));

    int tmp, cnt = 0, c_0, c_1;
    for (; down <= up; ++down) {
        for (int i = 0; i < m; ++i) { gates[i] = -1; }
        while (gates[id - 1] == -1) {
            for (int j = 0; j < m; ++j) {

                c_0 = -1;
                c_1 = -1;

                if (gates[j] == -1) {
                    if (T[j][0] < 0) {
                        tmp = n + T[j][0];
                        if (down & (1 << tmp)) c_0 = 1;
                        else c_0 = 0;
                    } else c_0 = gates[T[j][0] - 1];

                    if (T[j][1] < 0) {
                        tmp = n + T[j][1];
                        if (down & (1 << tmp)) c_1 = 1;
                        else c_1 = 0;
                    } else c_1 = gates[T[j][1] - 1];

                    if (c_0 != c_1 && c_0 != -1 && c_1 != -1) gates[j] = 1;
                    else if (c_0 == c_1 && c_0 != -1) gates[j] = 0;
                }

            }
        }
        if (gates[id - 1] == 1) cnt += 1;
    }
    printf("%d", cnt);


    free(gates);
    for (int i = 0; i < m; i++) {
        free(T[i]);
    }
    free(T);

}

