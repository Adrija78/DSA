#include <stdio.h>

int binarysearch(int arr[], int n, int key) {
    int mid = n / 2;
    if (arr[mid] == key)
        return 1;
    else if (arr[mid] > key) {
        for (int i = 0; i < mid; i++) {
            if (arr[i] == key)
                return 1;
        }
    } else {
        for (int i = mid + 1; i < n; i++) {
            if (arr[i] == key)
                return 1;
        }
    }
    return 0;
}

int main() {
    int arr[8], key;
    printf("Enter the elements in a sorted way: ");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    if (binarysearch(arr, 8, key) == 1)
        printf("Number is found.");
    else
        printf("Number not found.");
    return 0;
}