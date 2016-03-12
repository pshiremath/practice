#include <stdio.h>

void bubbleSort(int array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}