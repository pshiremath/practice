#include <iostream>

int maxOnesIndex(int arr[], int n) {
  int max_count = 0;
  int max_index = 0;
  int prev_zero = -1;
  int prev_prev_zero = -1;

  for (int current = 0; current < n; current++) {
    if (arr[current] == 0) {
      if (current - prev_prev_zero > max_count) {
        max_index = prev_zero;
        max_count = current - prev_prev_zero;
      }
      prev_prev_zero = prev_zero;
      prev_zero = current;
    }
  }

  if (n - prev_prev_zero > max_count)
    max_index = prev_zero;

  return max_index;
}

// Driver program
int main() {
  int arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Index of 0 to be replaced is " << maxOnesIndex(arr, n);
  return 0;
}
