#include <iostream>

#define ROW 4
#define COL 5

class Solution {
 public:
  Solution() {}
  ~Solution() {}

  void DiagMatrixPrint(int matrix[ROW][COL]) {
    int row, col;
    for (int k = 0; k < ROW; k++) {
      for (row = k, col = 0; row >= 0 && col <= (COL - 1); row--, col++) {
        std::cout << matrix[row][col] << " ";
      }
      std::cout << "\n";
    }

    for (int k = 1; k < COL; k++) {
      for (row = ROW - 1, col = k; row >= 0 && col <= (COL - 1); row--, col++) {
        std::cout << matrix[row][col] << " ";
      }
      std::cout << "\n";
    }
  }
};

int main(int argc, char const* argv[]) {
  int k = 1;
  int matrix[ROW][COL] = {0};

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      matrix[i][j] = k;
      k++;
    }
  }

  Solution soln;
  soln.DiagMatrixPrint(matrix);
  return 0;
}