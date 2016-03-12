#include <stdio.h>

void merge(int array[], int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = array[low + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = array[mid + j + 1];
  }

  int i = 0, j = 0, k = low;

  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }
}

void mergeSort(int array[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
  }
}

int main(int argc, char const* argv[]) {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("Given array is \n");
  printArray(arr, arr_size);

  mergeSort(arr, 0, arr_size - 1);

  printf("\nSorted array is \n");
  printArray(arr, arr_size);
  return 0;
}