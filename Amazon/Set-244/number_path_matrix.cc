#include <iostream>

int NumberPaths(int m, int n) {
  if (m == 1 || n == 1) {
    return 1;
  }

  return (NumberPaths(m - 1, n) + NumberPaths(m, n - 1));
}

int main(int argc, char const *argv[]) {
  std::cout << "Number of paths " << NumberPaths(3, 3) << std::endl;
  return 0;
}