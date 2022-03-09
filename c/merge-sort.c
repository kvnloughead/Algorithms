#include <stdio.h>

void copyArray(int arr[], int copy[], int size);
void displayArray(int arr[], int size);
void testMerge(int arr[], int size);
int testMergeSort(int arr[], int size);

// Merges sorted subarrays A[left..mid] and A[mid..right] into a sorted array.
void merge(int A[], int left, int mid, int right) {
  int sizeLeft = mid - left + 1;
  int sizeRight = right - mid;
  int L[sizeLeft], R[sizeRight];
  for (int i = 0; i < sizeLeft; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < sizeRight; i++) {
    R[i] = A[mid + i + 1];
  }

  int iL = 0, iR = 0, iA = left;
  while (iL < sizeLeft && iR < sizeRight) {
    if (L[iL] <= R[iR]) {
      A[iA] = L[iL];
      iL++;
    } else {
      A[iA] = R[iR];
      iR++;
    }
    iA++;
  }

  while (iL < sizeLeft) {
    A[iA] = L[iL];
    iL++;
    iA++;
  }

  while (iR < sizeRight) {
    A[iA] = R[iR];
    iR++;
    iA++;
  }
}

void mergeSort(int A[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
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
  testMergeSort(arr1, sizeof arr1 / SIZE_INT);
  testMergeSort(arr2, sizeof arr2 / SIZE_INT);
  testMergeSort(arr3, sizeof arr3 / SIZE_INT);
  testMergeSort(arr4, sizeof arr4 / SIZE_INT);
  testMergeSort(arr5, sizeof arr5 / SIZE_INT);
  testMergeSort(arr6, sizeof arr6 / SIZE_INT);
  testMergeSort(arr7, sizeof arr7 / SIZE_INT);
  testMergeSort(arr8, sizeof arr8 / SIZE_INT);
  testMergeSort(arr9, sizeof arr9 / SIZE_INT);
  testMergeSort(arr10, sizeof arr10 / SIZE_INT);
  testMergeSort(arr11, sizeof arr11 / SIZE_INT);
  testMergeSort(arr12, sizeof arr12 / SIZE_INT);
  testMergeSort(arr13, sizeof arr13 / SIZE_INT);
}

void testMerge(int arr[], int size) {
  int left = 0, right = size - 1;
  int mid = left + (right - left) / 2;
  merge(arr, left, mid, right);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

int testMergeSort(int arr[], int size) {
  int copy[size];
  copyArray(arr, copy, size);
  int left = 0, right = size - 1;
  mergeSort(arr, left, right);
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      puts("Bad sort");
      return 0;
    }
  }
  puts("Good sort");
  return 1;
}

// Returns a copy of an array of integers
// copy[] should be an empty array of the same size as arr[]
void copyArray(int arr[], int copy[], int size) {
  for (int i = 0; i < size; i++) {
    copy[i] = arr[i];
  }
}

// Prints an array of integers
void displayArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
