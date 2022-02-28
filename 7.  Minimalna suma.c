#include <stdio.h>



void sum_min(int n, int k, int A[], int sum) {
    int j_max = 0;
    for (int i = 0; i < k; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] > x){
                x = A[j];
                j_max = j;
            }}
        sum -= x; x = A[j_max]/2; sum += x; A[j_max] = x;
    }
    printf("%d", sum);
}


int main() {
    int n, k, sum = 0;
    scanf("%d%d", &n, &k);
    int A[n];
    for (int i = 0; i < n; ++i) { scanf("%d", &A[i]); sum += A[i];}
    sum_min(n, k, &A, sum);
}
