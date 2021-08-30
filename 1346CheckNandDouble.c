#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


bool checkIfExist(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if ((arr[i] == arr[j] * 2) || (arr[j] == arr[i] * 2)) {
                printf("arr[i] = %d, arr[j] = %d", arr[i], arr[j]);
                return true;
            }
        }
    }
    return false;
}

void testing() {
    int a[] = {7,1,13,11};
    int aSize = 4;
    printf("%s",checkIfExist(a, aSize) ? "true" : "false");
}

int main() {
    testing();
}
