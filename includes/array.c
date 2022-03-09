#include <stdbool.h>
#include <stdio.h>

// A few helper functions for arrays

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

// Returns true if arr[] is sorted ascending
bool isSorted(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

// Returns true if arrays are equal (excluding order). No sorting
// necessary, hence the O(n^2) run time.
bool areEqual(int arr_1[], int arr_2[], int size_1, int size_2) {
  if (size_1 != size_2) {
    return false;
  }
  bool visited[size_1];
  for (int i = 0; i < size_1; i++) {
    visited[i] = false;
  }
  int j = 0;
  for (int i = 0; i < size_1; i++) {
    while ((arr_1[i] != arr_2[j] && j < size_1) || visited[j]) {
      j++;
    }
    // problem --> only checks first visited entry?
    if (j == size_1 || visited[j]) {
      return false;
    }
    visited[j] = true;
    j = 0;
  }
  return true;
}
