#include <stdio.h>
#include <math.h>


int main() {
    int M, N, ile = 0, x;

    scanf("%d %d", &N, &M);

    x = pow(2, N);

    for (int i = 1; i < x; ++i) {
        if (i % M != 0) {
            for (int j = 0; j < N; ++j) {

                if (i & (1 << j)) {
                    i -= 1 << j;
                } else { i += 1 << j; }

                if (i % M == 0) {
                    if (i != 0) {
                        ile += 1;
                        if (i & (1 << j)) {
                            i -= 1 << j;
                        } else { i += 1 << j; }
                        break;

                    }
                }
                if (i & (1 << j)) {
                    i -= 1 << j;
                } else { i += 1 << j; }
            }
        }
    }

    printf("%d", ile);

}




