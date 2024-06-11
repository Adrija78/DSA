#include <stdio.h>
void insertionSort(int arr[], int n) {
    int i, j, current;
    for (i = 1; i < n; i++) {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main() {
    int arr[8];
    printf("Enter the elements: ");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, 8);
    printf("Sorted array is:-\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}