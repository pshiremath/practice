#include <iostream>

typedef struct _MinHeap {
  int size;
  int* data;
} MinHeap;

void SwapNodes(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = *a;
}

void MinHeapify(MinHeap* minheap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minheap->size && minheap->data[left] < minheap->data[smallest])
    smallest = left;

  if (right < minheap->size && minheap->data[right] < minheap->data[smallest])
    smallest = right;

  if (smallest != idx) {
    SwapNodes(&minheap->data[idx], &minheap->data[smallest]);
    MinHeapify(minheap, smallest);
  }
}

void InsertMinHeap(MinHeap* minheap, int val) {
  ++minheap->size;
  int i = minheap->size - 1;

  while (i && minheap->data[(i - 1) / 2]) {
    minheap->data[i] = minheap->data[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minheap->data[i] = val;
}

MinHeap* CreateAndBuildHeap(int* array, int size) {
  MinHeap* minheap = new MinHeap;
  minheap->size = size;
  minheap->data = array;

  for (int i = (minheap->size - 2) / 2; i >= 0; --i) {
    MinHeapify(minheap, i);
  }

  return minheap;
}

int ExtractMin(MinHeap* heap) {
  int temp = heap->data[0];
  heap->data[0] = heap->data[heap->size - 1];
  --heap->size;
  MinHeapify(heap, 0);
  return temp;
}

int minCost(int* array, int size) {
  int cost = 0;
  MinHeap* minheap = CreateAndBuildHeap(array, size);

  while (minheap->size > 1) {
    int min = ExtractMin(minheap);
    int sec_min = ExtractMin(minheap);
    cost += min + sec_min;
    InsertMinHeap(minheap, min + sec_min);
  }

  return cost;
}

int main() {
  int len[] = {4, 3, 2, 6};
  int size = sizeof(len) / sizeof(len[0]);
  std::cout << "Total cost for connecting ropes is " << minCost(len, size)
            << std::endl;
  return 0;
}