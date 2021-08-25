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

int findNumbers(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        if (digit(nums[i]) % 2 == 0) {
            result += 1;
        }
    }
    return result;
}

int main() {
    int a[] = {3, 23, 1564, 1563, 23224, 981731};
    printf("array a[] has %d items with even number of digits\n", findNumbers(a, 6));
}