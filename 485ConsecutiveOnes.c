#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxConsec = 0;
    for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 1) {
        int consec = 1;
        for (int j = i + 1; j < numsSize; j++){
            if (nums[j] != 1) {
                break;}
            else {
                consec += 1;}
            }
        if (consec > maxConsec){
            maxConsec = consec;}
    }}
    return maxConsec;
}

int main() {
    int a[] = {1,1,3,1,1,1,1,0,1,1,1,1,1,5,1,1}; //expecting 5
    int aSize = 16;
    printf("array a has %d consecutive ones",findMaxConsecutiveOnes(a, aSize));
}