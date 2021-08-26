#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    if (nums[0] >= 0) { //if all positive, simply square
        for (int i = 0; i < numsSize; i++) {
            result[i] = pow(nums[i],2);
        }
        return result;
    }
    if (nums[numsSize - 1] < 0) { //if all negative, simply square in reverse 
                                  //order
        for (int i = 0; i < numsSize; i++) {
            result[numsSize - i - 1] = pow(nums[i],2);
        }
        return result;
    }

    int negPointer = 0; //use two pointers approach, set left and right pointers
    int posPointer = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (abs(nums[negPointer]) > abs(nums[posPointer])) {
            result[i] = pow(nums[negPointer],2);
            negPointer += 1;
        } else {
            result[i] = pow(nums[posPointer],2);
            posPointer -= 1;
        }
    }
    return result;
}

void printArray(int* arr, int size) {
    printf("{ ");
    for (int i = 0; i < size; i ++) {
        printf("%d ",arr[i]);
    }
    printf("}\n");
}

int main() {
    int a[] = {-4,-1,0,3,10};
    int aSize = 5;
    printf("array a[] becomes:");
    int* aSortedSquares = sortedSquares(a, aSize, &aSize);
    printArray(aSortedSquares,aSize);
}
