#include "array.c"
#include <stdio.h>

int testQuickSort(int arr[], int size);

// Swaps elements arr[a] and arr[b]
void swap(int arr[], int a, int b) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

// Partitions arr[low..high] such that arr[high] is correctly positioned
// For example, [4, 3, 2, 1] => [1, 4, 3, 2]
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i_current = low - 1;
  for (int i = low; i < high; i++) {
    if (arr[i] < pivot) {
      i_current++;
      swap(arr, i, i_current);
    }
  }
  swap(arr, i_current + 1, high);
  return i_current + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

int main(void) {
  int SIZE_INT = sizeof 1;
  int arr1[] = {1, 3, 5, 2, 7};
  int arr2[] = {1, 3, 2, 5};
  int arr3[] = {1, 3, 5, 7};
  int arr4[] = {1, 3, 5, 7, 9};
  int arr5[] = {5, 7, 1, 5};
  int arr6[] = {5, 7, 9, 3, 5};
  int arr7[] = {3};
  int arr8[] = {3, 5};
  int arr9[] = {5, 3};
  int arr10[] = {-3, -1, -5, 0, 5};
  int arr11[] = {9, 7, 6, 5};
  int arr12[] = {9, 7, 6, 5, 3};
  int arr13[] = {9, 7, 11, 3};

  testQuickSort(arr1, sizeof arr1 / SIZE_INT);
  testQuickSort(arr2, sizeof arr2 / SIZE_INT);
  testQuickSort(arr3, sizeof arr3 / SIZE_INT);
  testQuickSort(arr4, sizeof arr4 / SIZE_INT);
  testQuickSort(arr5, sizeof arr5 / SIZE_INT);
  testQuickSort(arr6, sizeof arr6 / SIZE_INT);
  testQuickSort(arr7, sizeof arr7 / SIZE_INT);
  testQuickSort(arr8, sizeof arr8 / SIZE_INT);
  testQuickSort(arr9, sizeof arr9 / SIZE_INT);
  testQuickSort(arr10, sizeof arr10 / SIZE_INT);
  testQuickSort(arr11, sizeof arr11 / SIZE_INT);
  testQuickSort(arr12, sizeof arr12 / SIZE_INT);
  testQuickSort(arr13, sizeof arr13 / SIZE_INT);
}

int testQuickSort(int arr[], int size) {
  int copy[size];
  copyArray(arr, copy, size);
  int left = 0, right = size - 1;
  quickSort(arr, left, right);
  printf("%s\n", isSorted(arr, size) ? "Sorted" : "Not sorted");
  printf("%s\n", areEqual(arr, copy, size, size) ? "Equal" : "Not Equal");
  puts("");
  return 1;
}
