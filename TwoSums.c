/* Previous Mistake Summary:
Forget to initialize a pointer to int for returnSize variable when calling twoSum function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int *twoSum(int *nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *returnValues = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnValues[0] = i;
                returnValues[1] = j;
                return returnValues;
            }
        }
    }
    
    return returnValues;
}

int main(){
    int nums[] = {0,1,2,3,4,5};
    int size = 6;
    int resultSize = 2;
    int *pSize = &resultSize;
    printf("First index:%d  \n", (twoSum(nums, size, 9, pSize))[0]);
    printf("Second index:%d  \n", (twoSum(nums, size, 9, pSize))[1]);
  return 0;
}