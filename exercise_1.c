#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define MAXUINT_32 1073741824   // 2^30
#define MAXINT_32  2147483648   // 2^31

void print32_bool(int32_t x_1, long unsigned int max){
    int i, iteration;
    if (max == MAXUINT_32)
        iteration = 31;
    else 
        iteration = 32;

    for (i = 0; i < iteration; ++i) {
        if (x_1 & max)
            printf("1");
        else
            printf("0");
        x_1 = x_1 << 1;
    }
}
void main() {
    int64_t x = 0;
    int32_t x_1;
    int minus = 0;

    printf("Введите число в десятичной системе (не более 32 бит):\n");
    scanf("%ld", &x);

    if (llabs(x) > MAXUINT_32)
        printf("Произошло переполнение\n");
    
    else {
            x_1 = x;
            printf("\nВаш компьютер хранит число в виде: \n");
            print32_bool(x_1, MAXINT_32);

        if (x_1 < 0) {
            minus = 1; // negative
            x_1 = labs(x_1);
        }

        printf("\nВаше число в прямом коде: \n%d ", minus);
        print32_bool(x_1, MAXUINT_32);

        printf("\nВаше число в дополнительном коде: \n%d ", minus);
        x_1 = ~x_1;
        x_1++;
        print32_bool(x_1, MAXUINT_32);
        printf("\n");
    }
}
