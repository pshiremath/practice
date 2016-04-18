#include <iostream>

class Solution {
 public:
  Solution() {}
  ~Solution() {}

  int FindPivotElement(int array[], int length) {
    int start = 0;
    int end = length - 1;

    if (array[start] < array[end]) {
      return array[start];
    }

    while (start <= end) {
      int mid = (start + end) / 2;

      if (mid < length - 1 && array[mid] > array[mid + 1]) {
        return array[mid + 1];
      } else if (array[start] < array[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return -1;
  }
};

int main(int argc, char const* argv[]) {
  int array[] = {78, 82, 99, 10, 23, 35, 49, 51, 60};
  int length = sizeof(array) / sizeof(array[0]);

  Solution soln;
  std::cout << "Pivot element : " << soln.FindPivotElement(array, length)
            << std::endl;
  return 0;
}