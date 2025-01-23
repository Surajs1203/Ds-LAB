#include <stdio.h>

void printFrequency(int arr[], int n) {
    int freq[n];
    for (int i = 0; i < n; i++) {
        freq[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    printf("Element | Frequency\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("  %d    |    %d\n", arr[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {2, 3, 2, 4, 5, 2, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printFrequency(arr, n);
    return 0;
}
