#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int frequency;
} Element;

int compare(const void *a, const void *b) {
    Element *elem1 = (Element *)a;
    Element *elem2 = (Element *)b;
    return elem2->frequency - elem1->frequency;
}

void printDescendingFrequency(int arr[], int n) {
    Element elements[n];
    for (int i = 0; i < n; i++) {
        elements[i].value = arr[i];
        elements[i].frequency = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (elements[i].value == elements[j].value) {
                elements[i].frequency++;
                elements[j].frequency = 0;
            }
        }
    }

    qsort(elements, n, sizeof(Element), compare);

    for (int i = 0; i < n; i++) {
        if (elements[i].frequency != 0) {
            printf("%d occurs %d times\n", elements[i].value, elements[i].frequency);
        }
    }
}

int main() {
    int arr[] = {4, 6, 2, 4, 3, 6, 4, 2, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printDescendingFrequency(arr, n);
    return 0;
}
