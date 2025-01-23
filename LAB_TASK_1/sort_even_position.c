#include <stdio.h>

void sortEvenPositions(int arr[], int n) {
    int evenPos[n/2 + 1], evenCount = 0;
    for (int i = 0; i < n; i += 2) {
        evenPos[evenCount++] = arr[i];
    }
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = 0; j < evenCount - i - 1; j++) {
            if (evenPos[j] > evenPos[j + 1]) {
                int temp = evenPos[j];
                evenPos[j] = evenPos[j + 1];
                evenPos[j + 1] = temp;
            }
        }
    }
    for (int i = 0, k = 0; i < n; i += 2) {
        arr[i] = evenPos[k++];
    }
}

int main() {
    int arr[] = {3, 2, 1, 4, 5, 8, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortEvenPositions(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
