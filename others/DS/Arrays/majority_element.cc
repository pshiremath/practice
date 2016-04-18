#include <iostream>

class Solution {
 public:
  Solution() {}
  ~Solution() {}

  void FindMajorityElement(int array[], int length) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < length; i++) {
      if (count == 0) {
        candidate = array[i];
        count++;
        continue;
      } else {
        if (candidate == array[i]) {
          count++;
        } else {
          count--;
        }
      }
    }

    if (count == 0) {
      std::cout << "No Majority Element Find \n";
    }

    count = 0;
    for (int i = 0; i < length; i++) {
      if (candidate == array[i]) {
        count++;
      }
    }

    if (count > (length / 2))
      std::cout << "Majority Element is " << candidate << std::endl;
    else
      std::cout << "No Majority Element Found \n";
  }
};

int main(int argc, char const* argv[]) {
  int array[] = {2, 6, 2, 2, 6, 2, 2, 8, 2, 1};
  int length = sizeof(array) / sizeof(array[0]);

  Solution soln;
  soln.FindMajorityElement(array, length);
  return 0;
}