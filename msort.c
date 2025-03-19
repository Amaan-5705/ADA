#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }


    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void Mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        Mergesort(arr, left, mid);
        Mergesort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();

    Mergesort(arr, 0, n - 1);

    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    displayArray(arr, n);

    printf("Time taken to sort the array: %.6f seconds\n", timeTaken);

    return 0;
}


