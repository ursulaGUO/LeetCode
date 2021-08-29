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


/*Below is my version, but it does not perform well and the logic
is a bit redundant and unclear */
int removeElement(int* nums, int numsSize, int val){
    int rightPointer = numsSize - 1, count = 0; 
    int j = numsSize - 1;
    for (int i = 0; i <= rightPointer; i++) {
        while (j >= 0) {
            if (nums[j] != val || j == i) {
                rightPointer = j;
                break;
            }
            j--;
        }
        if (j == -1) {
            return count;
        }
        if (nums[i] == val) {
            pointerSwap(&nums[i],&nums[rightPointer]);
        } 
        if (j != i || (j == i && nums[j] != val)) {
            count++;
        }
    }
    return count;
}

int main() {
    int a[] = {0,1,2,2,3,0,4,2};
    //pointerSwap(&a[0],&a[1]);
    int aSize = 8;
    int val = 2;
    printf("%d numbers remain\n",removeElement(a, aSize, val));
    printf("a becomes:");
    printArray(a, aSize);
    printf("\n");
    printf("\n");
    printf("\n");

    int b[] = {2};
    int bSize = 1;
    int bVal = 3;
    printf("%d numbers remain\n", removeElement(b,bSize,bVal));
    printf("b becomes:");
    printArray(b,bSize);
    printf("\n");
    printf("\n");
    printf("\n"); 

    int c[] = {4,5};
    int cSize = 2;
    int cVal = 4;
    printf("%d numbers remain\n", removeElement(c,cSize,cVal));
    printf("c becomes:");
    printArray(c,cSize);
    printf("\n");
    printf("\n");
    printf("\n");
}
