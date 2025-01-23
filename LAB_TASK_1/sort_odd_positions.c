#include <stdio.h>

void sortOddPositions(int arr[], int n) {
    int oddPos[(n+1)/2], oddCount = 0;
    for (int i = 1; i < n; i += 2) {
        oddPos[oddCount++] = arr[i];
    }
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = 0; j < oddCount - i - 1; j++) {
            if (oddPos[j] > oddPos[j + 1]) {
                int temp = oddPos[j];
                oddPos[j] = oddPos[j + 1];
                oddPos[j + 1] = temp;
            }
        }
    }
    for (int i = 1, k = 0; i < n; i += 2) {
        arr[i] = oddPos[k++];
    }
}

int main() {
    int arr[] = {3, 2, 1, 4, 5, 8, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortOddPositions(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
