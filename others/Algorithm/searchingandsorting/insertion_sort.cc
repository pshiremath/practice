#include <stdio.h>

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int j = i - 1;
    int key = arr[i];

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}
int main(int argc, char const *argv[]) {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);
  printArray(arr, n);
  return 0;
}