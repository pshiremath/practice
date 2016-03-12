#include <bits/stdc++.h>
using namespace std;

void printVector(std::vector<int> v) {
  for_each(v.begin(), v.end(), [](int i) { std::cout << i << " "; });
  std::cout << std::endl;
}

int main(int argc, char const* argv[]) {
  std::vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};
  printVector(v);

  std::vector<int>::iterator p =
      find_if(v.begin(), v.end(), [](int i) { return i > 4; });
  std::cout << "First number greater than 4 is : " << *p << std::endl;

  std::sort(v.begin(), v.end(),
            [](const int& a, const int& b) -> bool { return a > b; });
  printVector(v);
  return 0;
}
