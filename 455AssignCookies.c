/* Mistake involved:
    1. Selection sort should compare to the max in rest of the array, not just 
    any item larger then array[i]
    2. Traverse greedy factor array if current satisfaction does not satisfy 
    current greed factor. */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* first, int* second) { //swap the content of the two pointers
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int maxPointer = i;
        int tempMax = arr[i];
        if (i + 1 < size) {
            int tempMax = arr[i + 1];
        }
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[i] && arr[j] >= tempMax) {
                tempMax = arr[j];
                maxPointer = j;
            }
        }
        swap(&arr[maxPointer], &arr[i]);
    }
}


int findContentChildren(int* g, int gSize, int* s, int sSize){
    int numContent = 0;
    selectionSort(g, gSize); 
    selectionSort(s, sSize);
    int gi = 0, si = 0;
    while (gi< gSize && si < sSize) {
        if (g[gi] <= s[si]) {
            gi++;
            si++;
            numContent++;
        } else {
            gi++;
        }
    }
    return numContent;

}



void printArray(int* arr, int size) {
    printf("{ ");
    for (int i = 0; i < size; i ++) {
        printf("%d ",arr[i]);
    }
    printf("}\n");
}

void testingSort(int* g, int gSize, int* s, int sSize){
    selectionSort(g, gSize);
    printArray(g,gSize);
    selectionSort(s, sSize);
    printArray(s,sSize);
}

int main() {
    int g[] = {1,2,3,10,11};
    int s[] = {1,1,3,5,9,100};
    testingSort(g,5,s,6); //passes sorting from big to small
    printf("number of kids content: %d\n", findContentChildren(g, 5, s, 6));
    printf("\n");
    printf("\n");
    printf("\n");

    int s2[] = {376,71,228,110,215,410,363,135,508};
    int s2Size = 9;
    selectionSort(s2, s2Size);
    printArray(s2,s2Size);
}

