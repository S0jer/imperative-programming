#include <stdio.h>
#include <malloc.h>


void bin_search(long int bin[], int T[],long int k,long int n) {
    if (k <= 0) {
        for (long int i = n - 1; i > -1; --i) {
            printf("%d", bin[i]);
        }
        return;
    } else {
        for (long int i = 24; i > -1; --i) {
            if (T[i] <= k) {
                bin[i] = 1;
                if(T[i] == 0){
                    k -= 1;
                }else {
                    k = k - T[i];
                }
                return bin_search(bin, T, k, n);
            }
        }
    }
}


int main() {
    int n, k, check = 0;
    scanf("%d %d", &n, &k);
    int *bin;
    int T[40];
    bin = malloc((n) * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        bin[i] = 0;
    }
    T[0] = 0;
    T[1] = 2;
    T[2] = 3;
    for (int i = 3; i < 40; ++i) {
        T[i] = T[i - 1] + T[i - 2];
    }


    if (T[n] <= k) {
        printf("%d", -1);
    } else {
        if(k == 1){
            for (int i = n - 1; i > -1; --i) {
                printf("%d", bin[i]);
            }
        }
        else {
            bin_search(bin, T, k - 1, n);
        }
    }
}


