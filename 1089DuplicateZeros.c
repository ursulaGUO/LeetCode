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

void duplicateZeros(int* arr, int arrSize){
    int arrCopied[arrSize];
    for (int i = 0, c = 0; c < arrSize && i < arrSize;) {
        arrCopied[c] = arr[i];
        if (arr[i] != 0) {
            c++;
        } else {
            if (c + 1 >= arrSize) {
                break;
            } else {
                arrCopied[c + 1] = 0;
                c += 2;
            } 
        }
        i += 1;
    }
    for (int i = 0; i < arrSize; i++) {
        arr[i] = arrCopied[i];
    }
}

int main() {
    int a[] = {1,0,2,3,0,4,5,0};
    int aSize = 8;
    duplicateZeros(a,aSize);
    printArray(a, aSize);

}