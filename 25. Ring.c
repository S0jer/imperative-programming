#include <stdio.h>
#include <string.h>
#include <math.h>


int is_prime(int a) {
    int x = 2;
    if (a == 1 || a == 0) return 0;
    while (x < pow(a, 0.5)) {
        if (a % x == 0) { return 0; }
        x += 1;
    }
    return 1;
}


int main() {
    int n, idx = 0, idx_p = 0, idx_l = 0, primes[51] = {-1}, lowest[51] = {-1};
    char napis[51], min_n = 'z', napis_c[51], napis_min[51];
    scanf("%s", &napis);

    n = strlen(napis);


    for (int i = 0; i < n; ++i) {
        if (is_prime(i) == 1) {
            primes[idx_p] = i;
            idx_p += 1;
        }
        if (napis[i] == min_n) {
            min_n = napis[i];
            lowest[idx_l] = i;
            idx_l += 1;
        } else if (napis[i] < min_n) {
            idx_l = 0;
            min_n = napis[i];
            lowest[idx_l] = i;
            idx_l += 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        napis_min[i] = napis[i];
    }

    for (int i = 0; i < idx_l; ++i) {

        for (int j = 0; j < idx_p; ++j) {
            idx = 0;
            int check = 0, check_prev = 0;

            while (idx < n) {
                napis_c[idx] = napis[((lowest[i] + idx * primes[j]) % n)];
                if (napis_c[idx] > napis_min[idx] && check == 0) {
                    check_prev = 1;
                }
                if (napis_c[idx] < napis_min[idx] && check_prev == 0) {
                    check = 1;
                }
                idx += 1;
            }

            if (check == 1) {
                for (int k = 0; k < n; ++k) {
                    napis_min[k] = napis_c[k];
                }
            }
        }
    }


    for (int k = 0; k < n; ++k) {
        printf("%c", napis_min[k]);
    }

}

