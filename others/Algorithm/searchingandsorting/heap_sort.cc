#include <stdio.h>

typedef struct _MINHEAP {
  int size;
  int* array;
} MINHEAP;

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d\n", array[i]);
  }
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void minHeapify(MINHEAP* minheap, int idx) {
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
  int smallest = idx;

  if (left < minheap->size && minheap->array[smallest] < minheap->array[left])
    smallest = left;
  if (right < minheap->size && minheap->array[smallest] < minheap->array[right])
    smallest = right;

  if (idx != smallest) {
    swap(&minheap->array[smallest], &minheap->array[idx]);
    minHeapify(minheap, smallest);
  }
}

void heapSort(int* array, int size) {
  MINHEAP* minheap = new MINHEAP();
  minheap->size = size;
  minheap->array = array;

  for (int i = (minheap->size - 2) / 2; i >= 0; i--) {
    minHeapify(minheap, i);
  }

  while (minheap->size > 1) {
    swap(&minheap->array[minheap->size - 1], &minheap->array[0]);
    --minheap->size;
    minHeapify(minheap, 0);
  }
}

int main(int argc, char const* argv[]) {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given array is \n");
  printArray(arr, size);

  heapSort(arr, size);

  printf("\nSorted array is \n");
  printArray(arr, size);
  return 0;
}
