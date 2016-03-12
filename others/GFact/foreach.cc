#include <iostream>

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  for (int x : arr) {
    std::cout << x << std::endl;
  }
  return 0;
}