/* Mistake involved:
    1. [INT32_MIN,INT32_MAX - 1] range also applies to reversed integer*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digit(int x) {
    int i = 0;
    while (x > 0) {
        x = x / 10;
        i++;
    }
    return i;
}

int reverse(int x){
    if (x >= INT32_MAX - 1 || x <= INT32_MIN) {
        return 0;
    }
    int sign = 1;
    if (x < 0) {
        x = -x;
        sign = -1;
    }
    int temp = 0;
    int i = digit(x);
    long result = 0;
    while (x > 0) {
        result += x % 10 * pow(10, i - 1);
        if (result * sign > INT32_MAX - 1 || result * sign < INT32_MIN) {
            return 0;
        }
        x = x / 10;
        i -= 1;
    }
    return (int)result * sign;
}



int main() {
    printf("5170 has %d digits", digit(5170));
    printf("\n");
    printf("\n");
    printf("\n");
    printf("reversed result of 5170 is %d\n", reverse(5170));
    printf("\n");
    printf("\n");
    printf("\n");
    //printf("reversed result of -5170 is %d\n", reverse(-5170));
    printf("%d", reverse(-2147483648));
    //printf("%f", pow(2,31) - 1);
}