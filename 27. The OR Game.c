#include <stdio.h>
#include <malloc.h>


int bin_len(int a) {
    int length = 0, ones = 0;
    while (a != 0) {
        if (a % 2 == 1) { ones += 1; }
        length += 1;
        a /= 2;
    }
    length += 1;

    return length;
}

int one(int a) {
    int ones = 0;
    while (a != 0) {
        if (a % 2 == 1) { ones += 1; }
        a /= 2;
    }
    return ones;
}


int main() {
    int N, G, *T, length, ones;

    scanf("%d %d", &N, &G);

    T = malloc(N * sizeof(int *));

    for (int i = 0; i < N; ++i) { scanf("%d", &T[i]); }

    length = bin_len(G);
    ones = one(G);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < length; ++j) {
            if ((T[i] & (1 << j)) && !(G & (1 << j))) {
                T[i] = 0;
                break;
            }
        }
    }

    int ile_min = N;
    int ile_w = 0;
    for (int i = 0; i < length; ++i) {
        int ile = 0, c = 0;
        if (G & (1 << i)) {
            for (int j = 0; j < N; ++j) {
                if (T[j] & (1 << i)) {
                    c = 1;
                    ile += 1;
                }
            }
        }
        if (ile < ile_min && ile != 0) {
            ile_min = ile;
        }
        ile_w += c;
    }

    if (ile_w == ones) {
        printf("%d", ile_min);
    } else {
        printf("%d", 0);
    }

}

