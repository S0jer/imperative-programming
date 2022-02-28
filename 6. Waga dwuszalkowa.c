#include <stdio.h>

int weight(int tab[], int size, int masa){
    if (masa == 0){return 1;}
    if (size < 0){return 0;}
    return  weight(tab, size - 1, masa - tab[size]) || weight(tab, size - 1, masa + tab[size]) || weight(tab, size - 1, masa);
}


int main() {
    int size, masa, masa_max;
    scanf("%d%d", &size, &masa);
    int tab[size];
    for (int i = 0; i < size; ++i) { scanf("%d", &tab[i]); masa_max += tab[i]; }
    if (masa_max < masa){printf("NO");}
    else if( masa_max == masa){printf("YES");}
    else {
        if (weight(tab, size - 1, masa) == 1){
            printf("YES");}
        else {printf("NO");}
    }}