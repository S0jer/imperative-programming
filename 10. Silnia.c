#include <stdio.h>


int main() {
    int n = 0, tab[500] = {0}, t, i = 499, j, iloczyn, x, add, res_size, check;
    scanf("%d", &n);
    tab[499] = 1;
    x = n;
    while (x > 1) {
        for (j = 499; j >= i; j--) {
            iloczyn = tab[j] * x;
            tab[j] = iloczyn;
        }
        check = iloczyn; res_size = 1;
        while (check != 0) { check /= 10; res_size += 1; }
        i -= res_size;
        for (j = 499; j >= i; j--) {
            if (tab[j] > 9) {
                add = tab[j];
                tab[j] = add % 10;
                add /= 10;
                tab[j - 1] += add;
            }
        }
        x -= 1;
    }
    while (tab[i] == 0) { i += 1; }
    for (i = i; i <= 499; i++) { printf("%d", tab[i]); }
    }


