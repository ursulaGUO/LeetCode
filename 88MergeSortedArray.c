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

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int arrCopied[m+n];
    int i = 0, j = 0, count = 0;
    while (i < m && j < n) {
        if(nums1[i] > nums2[j]) {
            arrCopied[count] = nums2[j];
            j++;
        } else {
            arrCopied[count] = nums1[i];
            i++;
        }
        count++;
    }
    if (i == m) {
        for (;j < n; j++) {
            arrCopied[count] = nums2[j];
            count++;
        }
    } else {
        for (;i < m; i++) {
            arrCopied[count] = nums1[i];
            count++;
        }
    }
    for (int k = 0; k < m + n; k++) {
        nums1[k] = arrCopied[k];
    }
}

int main() {
    int a[] = {1,2,3,0,0,0};
    int aSize = 6;
    int am = 3;
    int b[] = {2,5,6};
    int bSize = 3;
    int bn = 3;
    merge(a, aSize, am, b, bSize, bn);
    printArray(a, aSize);
}
