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
