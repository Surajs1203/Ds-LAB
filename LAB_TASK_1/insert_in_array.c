#include <stdio.h>

int main() {
    int arr[100], n, pos, elem;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to insert the element: ");
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &elem);
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    n++;
    printf("Final Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
