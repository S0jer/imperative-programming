#include <stdio.h>



int main() {
    int n, i, j;
    scanf("%d", &n);
    int Tab[201][201] = {0};
    int black = 0;
    int T[n][4];



    for (i = 0; i < n; ++i) {
        for (j = 0; j < 4; ++j) {
            scanf("%d", &T[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        int s_x, s_y, e_x, e_y;
        if (T[i][0] < T[i][2]) {
            s_x = T[i][0] + 100;
            e_x = T[i][2] + 100;
        }
        else{
            s_x = T[i][2] + 100;
            e_x = T[i][0] + 100;
        }
        if (T[i][1] < T[i][3]) {
            s_y = T[i][1] + 100;
            e_y = T[i][3] + 100;
        }
        else{
            s_y = T[i][3] + 100;
            e_y = T[i][1] + 100;
        }

        for (int k = s_x; k < e_x; ++k) {
            for (int l = s_y; l < e_y; ++l) {
                if (Tab[k][l] == 0) {
                    Tab[k][l] = 1;
                    black += 1;
                } else {
                    Tab[k][l] = 0;
                    black -= 1;
                }
            }
        }
    }

    printf("%d", black);


}


