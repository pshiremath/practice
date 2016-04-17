#include <iostream>

#define ROW 6
#define COL 6

class Solution {
 public:
  Solution() {}
  ~Solution() {}

  int MaxSquareSubMatrix(int matrix[ROW][COL]) {
    int max_size = 0;
    int table[ROW][COL] = {0};
    int row = ROW, col = COL;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (i == 0 || j == 0) {
          table[i][j] = matrix[i][j];
          max_size = table[i][j] > max_size ? table[i][j] : max_size;
        } else if (matrix[i][j] == 0) {
          table[i][j] = 0;
        } else {
          table[i][j] = std::min(table[i - 1][j], std::min(table[i - 1][j - 1],
                                                           table[i][j - 1])) +
                        1;
          max_size = table[i][j] > max_size ? table[i][j] : max_size;
        }
      }
    }
    return max_size;
  }
};

int main(int argc, char const* argv[]) {
  int matrix[ROW][COL] = {{0, 1, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1},
                          {0, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 0, 0},
                          {1, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1}};
  Solution soln;
  std::cout << "Max square sub matrix : " << soln.MaxSquareSubMatrix(matrix)
            << "\n";

  return 0;
}