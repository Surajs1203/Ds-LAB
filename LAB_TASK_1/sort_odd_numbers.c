#include <stdio.h>

void sortOdds(int arr[], int n) {
    int odd[n], oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odd[oddCount++] = arr[i];
        }
    }
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = 0; j < oddCount - i - 1; j++) {
            if (odd[j] > odd[j + 1]) {
                int temp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = temp;
            }
        }
    }
    for (int i = 0, k = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = odd[k++];
        }
    }
}

int main() {
    int arr[] = {3, 2, 1, 4, 5, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortOdds(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
