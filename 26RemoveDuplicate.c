#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int* arr, int size) {
    printf("{ ");
    for (int i = 0; i < size; i ++) {
        printf("%d ",arr[i]);
    }
    printf("}\n");
}

void pointerSwap(int* p1, int* p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 1) {
        return 1;
    }
    if (numsSize == 0) {
        return 0;
    }
    int i = 0; //j visits all the elements
               //i visits unique elements
    int count = 1;
    while (i + 1 < numsSize) {
        if (nums[i + 1] == nums[i]) { //consecutive same
            int curr = nums[i];
            while(i < numsSize) { //find next unique element
                if (nums[i] != curr) {
                    count += 1;
                    break;
                }
                i++;
            }
        } else {
            count += 1;
            i += 1;
        }
        if (i < numsSize) { //Replace element in order with next unique element
            nums[count - 1] = nums[i];
        }
    }
    return count;
}

void testing(){
    int a[] = {0,0,1,1,1,2,2,3,3,4};
    int aSize = 10;
    printf("a contains %d non-duplicate numbers",removeDuplicates(a, aSize));
    printf("\n");
    printArray(a, aSize);
    printf("\n");
    printf("\n");
    printf("\n"); 

    int b[] = {1,1};
    int bSize = 2;
    printf("b contains %d non-duplicate numbers",removeDuplicates(b, bSize));
    printf("\n");
    printArray(b, bSize);

    int c[] = {1,1,3,3,4,5,6,7,7,8};
    int cSize = 10;
    printf("b contains %d non-duplicate numbers",removeDuplicates(c, cSize));
    printf("\n");
    printArray(c, cSize);

    int d[] = {1,2};
    int dSize = 2;
    printf("b contains %d non-duplicate numbers",removeDuplicates(d, dSize));
    printf("\n");
    printArray(d, dSize);
}

int main() {
    testing();
}
