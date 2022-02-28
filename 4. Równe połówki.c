#include <stdio.h>

void half(int tab[], int size){
    int i = 1, suma_i = tab[0], suma_j = 0, a = 0;
    while (i < size) {
        if (suma_i >= suma_j){ suma_j += tab[size]; size -= 1; a = size;}
        if (suma_j > suma_i){ suma_i += tab[i]; i += 1; a = i;}
    }
    printf("%d", a);
}

int main() {
    int size;
    scanf("%d", &size);
    int tab[size];
    for (int i = 0; i < size; ++i) { scanf("%d", &tab[i]); }
    half(tab, size - 1);
}

