// MergeSort(A):
// 1. If the length of A is less than or equal to 1,
//       return A   // already sorted

// 2. Find the middle index of A
//       mid = n / 2

// 3. Divide A into two halves:
//       Left = A[0 ... mid-1]
//       Right = A[mid ... n-1]

// 4. Recursively call:
//       MergeSort(Left)
//       MergeSort(Right)

// 5. Merge the sorted halves:
//       return Merge(Left, Right)

#include <stdio.h>
#include <stdlib.h>

// Merge two subarrays: arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // size of left subarray
    int n2 = r - m;      // size of right subarray

    // create temp arrays
    int L[n1], R[n2];

    // copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // merge temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // copy remaining elements, if any
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // middle index
        mergeSort(arr, l, m);    // sort left half
        mergeSort(arr, m + 1, r);// sort right half
        merge(arr, l, m, r);     // merge the sorted halves
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test merge sort
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}