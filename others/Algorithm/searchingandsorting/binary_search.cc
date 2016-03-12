#include <stdio.h>

bool binarySearch(int array[], int low, int high, int key) {
  if (low > high) {
    int mid = (low + high) / 2;
    if (array[mid] == key)
      return true;
    else if (array[mid] > key)
      return binarySearch(array, low, mid - 1, key);
    else
      return binarySearch(array, mid + 1, high, key);
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;

  binarySearch(arr, 0, n - 1, x) ? printf("Element is not present in array")
                                 : printf("Element is present\n");
  return 0;
}