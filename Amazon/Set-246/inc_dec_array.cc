#include <iostream>

int indexOfBrokenSqUtil(int arr[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
      return mid + 1;
    if (arr[mid] < arr[mid + 1])
      return indexOfBrokenSqUtil(arr, mid + 1, high);
    else
      return indexOfBrokenSqUtil(arr, low, mid - 1);
  }

  return -1;
}

int indexOfBrokenSq(int arr[], int size) {
  return indexOfBrokenSqUtil(arr, 0, size - 1);
}

int main(int argc, char const* argv[]) {
  int arr[] = {2, 3, 4, 5, 6, 9, 8, 6, 4, 3, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << "increasing sequence breaked at : " << indexOfBrokenSq(arr, size)
            << std::endl;
  return 0;
}