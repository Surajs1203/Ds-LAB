#include <stdio.h>

void movingAverage(int arr[], int n, int k) {
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += arr[i + j];
        }
        printf("Moving average for window starting at index %d is %f\n", i, (float)sum / k);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    movingAverage(arr, n, k);
    return 0;
}
