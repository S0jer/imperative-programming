#include <stdio.h>
#include <string.h>

int main() {
    int n, i_last;
    char napis[51], res[51], w_max;

    scanf("%s", &napis);
    n = strlen(napis);

    int x = 0, idx = 0;
    while (x < n) {
        w_max = "a";
        for (int i = x; i < n; ++i) {
            if(napis[i] > w_max ){
                w_max = napis[i];
                i_last = i;
            }

        }
        res[idx] = w_max;
        idx += 1;
        x = i_last + 1;
    }

    for (int i = 0; i < idx; ++i) {
        printf("%c", res[i]);
    }

}
