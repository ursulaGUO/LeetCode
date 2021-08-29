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
        while (j >= 0) { //This while loop finds the last element != val
            if (nums[j] != val || j == i) {
                rightPointer = j;
                break;
            }
            j--;
        }
        if (j == -1) { //If every element is traversed, return result
            return count;
        }
        if (nums[i] == val) { //If current element == val, swap with the last 
                              //the last element != val
            pointerSwap(&nums[i],&nums[rightPointer]);
        } 
        if (j != i || (j == i && nums[j] != val)) {
            count++; //This is to prevent swaping same pair multiple times
        }
    }
    return count;
}

int removeElementBetter(int* nums, int numsSize, int val){
    int i = -1, j = 0;
    
    if(!numsSize) return 0; 
    
    while(j < numsSize){
        if(nums[j] == val){ //If the later num == val
            while(j < numsSize && nums[j] == val) j++; //find the first num     
                                                       //that != val
            if(j < numsSize){
                nums[++i] = nums[j]; //Let the current num be the num that != 
                                     //val
            } 
        }
        else if(i != j-1){//If a "gap" was created by skiping more then 1 val
            nums[++i] = nums[j];
        }
        else{
            i++;
        }
        j++;
    }
    return i+1; //i+1 happens to be the length of arranged array
}

void testRemoveElement() {
    int a[] = {0,1,2,2,3,0,4,2};
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

void testRemoveElementBetter() {
    int a[] = {0,1,2,2,3,0,4,2};
    int aSize = 8;
    int val = 2;
    printf("%d numbers remain\n",removeElementBetter(a, aSize, val));
    printf("a becomes:");
    printArray(a, aSize);
    printf("\n");
    printf("\n");
    printf("\n");

    int b[] = {2};
    int bSize = 1;
    int bVal = 3;
    printf("%d numbers remain\n", removeElementBetter(b,bSize,bVal));
    printf("b becomes:");
    printArray(b,bSize);
    printf("\n");
    printf("\n");
    printf("\n"); 

    int c[] = {4,5};
    int cSize = 2;
    int cVal = 4;
    printf("%d numbers remain\n", removeElementBetter(c,cSize,cVal));
    printf("c becomes:");
    printArray(c,cSize);
    printf("\n");
    printf("\n");
    printf("\n");
}

int main() {
    printf("Testing my removeELement:\n");
    testRemoveElement();
    printf("Testing better and faster removeElement:\n");
    testRemoveElementBetter();
}
