#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int my_compare(const void *a, const void *b) {
    int _a = *(int *) a;
    int _b = *(int *) b;
    if (_a < _b) return -1;
    else if (_a == _b) return 0;
    else return 1;
}


void pair(int n, int k, int A[]) {
    int ile = 0;
    for (int i = 0; i < n;) {
        int count = 0, j = i;
        while (j != n && A[j] == A[i]) {
            j += 1;
            count += 1;
        }
        if (i != 0 && A[i - 1] >= A[i] - k) {
            ile += count;
        } else if (j != n && A[j] <= A[j - 1] + k) {
            ile += count;
        }
        i = j;
    }
    printf("%d", ile);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *A = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) { scanf("%d", &A[i]); }
    qsort(A, n, sizeof(int), my_compare);
    pair(n, k, A);
}


//int find(int A[], int a, int k, int start, int end) {
//    int half = (start + end) / 2;
//    if (a - k <= A[half] && A[half] <= a + k && A[half] != a) { return 1; }
//    if (start - end != 0) {
//        if (A[half] < a - k) { return find(A, a, k, half, end); }
//        else if (a + k < A[half]) { return find(A, a, k, start, half); }
//        else {
//            for (int j = start; j < end; ++j) {
//                if (a - k <= A[j] && A[j] <= a + k && A[j] != a) { return 1; }
//            }
//            return 0;
//        }
//    }
//    return 0;
//}

