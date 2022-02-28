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

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int *) calloc(n, sizeof(int));
    int i = 0;
    for (; i < n; i++) { scanf("%d", &arr[i]);}
    qsort(arr, n, sizeof(int), my_compare);
    int counter = 0;
    for (i = 0; i < n;) {
        int zlicz = 0;
        int j = i;
        while (j != n && arr[j] == arr[i]) {
            j++;
            zlicz++;
        }
        if (i != 0 && arr[i - 1] + k >= arr[i]) {
            counter += zlicz;
        } else if (j != n && arr[j] - k <= arr[j - 1]) {
            counter += zlicz;
        }

        i = j;

    }
    printf("%d", counter);
}

