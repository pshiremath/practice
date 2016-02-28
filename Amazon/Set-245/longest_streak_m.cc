#include <iostream>

int LongestSequence(bool array[], int size, int k) {
  int max_length = 0;
  int start = 0;
  int runnning_length = 0;
  int tempK = k;

  for (int i = 0; i < size; i++) {
    if (array[i] == 1) {
      // Increase the count of 1's
      runnning_length++;
    } else if (tempK > 0 && tempK < k) {
      // flipping the 0's to 1's, increase the count of 1's
      tempK--;
      runnning_length++;
    } else if (tempK == k) {
      // 1st zero occured, flip it to 1 and increase the count.
      // also store the start index of zero.
      tempK--;
      runnning_length++;
      start = i;
    } else {
      // Last place when all k flips have been done, calculate max 1's with
      // flips.
      tempK = k;
      max_length = std::max(max_length, runnning_length);
      runnning_length = 0;
      // reset the i to start index, so that we will start again from start
      // index.
      int temp = i;
      i = start;
      start = temp;
    }
  }

  // return max_length after all the array is traversed.
  return std::max(max_length, runnning_length);
}

int main(int argc, char const *argv[]) {
  bool array[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
  int size = sizeof(array) / sizeof(array[0]);

  std::cout << LongestSequence(array, size, 2) << "\n";

  return 0;
}