#include <stdio.h>


long long int check_if(long long a){

    long long int result = a, x = 10;
    while (a > 0){
        a = a/x;
        result += a;
    }
    return result;
}

int main(){
    long long int s, check, jest = 0;
    scanf("%lld", &s);

    check = s*0.9;


    for (long long int i = check - 100; i <= check + 100; ++i) {
        if (check_if(i) == s){
            jest = 1;
            printf("%lld", i);
            break;
        }
    }

    if (jest == 0){
        printf("%d", -1);
    }

}

//    int c_1 = check;
//    while(check_if(c_1) >= s){
//        if (check_if(c_1) == s){
//            jest = 1;
//            printf("%d", c_1);
//            break;
//        }
//        c_1 -= 1;
//    }
//
//    int c_2 = check + 1;
//    if( jest == 0) {
//        while (check_if(c_2) <= s) {
//            if (check_if(c_2) == s) {
//                jest = 1;
//                printf("%d", c_2);
//                break;
//            }
//            c_2 += 1;
//        }
//    }

