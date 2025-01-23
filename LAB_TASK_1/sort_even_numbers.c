#include <stdio.h>

void sortEvens(int arr[], int n) {
    int even[n], evenCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
    }
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = 0; j < evenCount - i - 1; j++) {
            if (even[j] > even[j + 1]) {
                int temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }
    for (int i = 0, k = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = even[k++];
        }
    }
}

int main() {
    int arr[] = {3, 2, 1, 4, 5, 8, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortEvens(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
