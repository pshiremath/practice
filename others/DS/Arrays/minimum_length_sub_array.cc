#include <iostream>

class Solution {
 public:
  Solution() {}
  ~Solution() {}

  void MinimumLengthSubArray(int array[], int length, int sum) {
    int start = -1, end = -1;
    int min_length = 9999;
    for (int i = 0; i < length; i++) {
      int current_sum = 0;
      for (int j = i; j < length; j++) {
        current_sum += array[j];
        if (current_sum == sum) {
          int temp = j - i + 1;
          if (temp < min_length) {
            start = i;
            end = j;
            min_length = temp;
          }
          break;
        }
      }
    }

    if (start == -1 || end == -1) {
      std::cout << "No sub array exists \n";
      return;
    }

    while (start <= end) {
      std::cout << array[start] << " ";
      start++;
    }
  }
};

int main(int argc, char const* argv[]) {
  int array[] = {2, 3, 1, 2, 4, 3};
  int sum = 7;
  int length = sizeof(array) / sizeof(array[0]);

  Solution soln;
  soln.MinimumLengthSubArray(array, length, sum);
  return 0;
}