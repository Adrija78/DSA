#include <stdio.h>
void heapify(int arr[], int n) {
    int p, c;
    for (int i = n/2-1; i >= 0; i--) {
        p = i;
        do {
            c = 2 * p + 1;
            if(c >= n)
                break;
            if(c < (n-1) && (arr[c] < arr[c+1]))
                c = c+1;
            if(arr[p] < arr[c]) {
                int t = arr[p];
                arr[p] = arr[c];
                arr[c] = t;
                p = c;
            }else
                break;
        } while (c < n);
    }
}
void heapsort(int arr[], int n) {
    heapify(arr, n);
    for (int i = n-1; i >= 1; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i);
    }
}
int main() {
    int arr[] = {6, 4, 2, 1, 5, 3, 7, 8};
    heapsort(arr, 8);
    printf("%d\n", arr[0]);
    return 0;
}
