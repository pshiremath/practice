#include <iostream>

class Solution {
 public:
  Solution() {}
  ~Solution() {}

  int FindPeakElement(int array[], int length) {
    int start = 0;
    int end = length - 1;

    while (start <= end) {
      int mid = (start + end) / 2;

      if ((mid == 0 || array[mid - 1] <= array[mid]) &&
          (mid == length - 1 || array[mid + 1] <= array[mid])) {
        return array[mid];
      } else {
        if (mid > 0 && array[mid - 1] > array[mid]) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  int array[] = {15, 20, 25, 35, 45, 50, 60};
  int length = sizeof(array) / (sizeof(array[0]));

  Solution soln;

  std::cout << "Peak Element is : " << soln.FindPeakElement(array, length)
            << std::endl;
  return 0;
}