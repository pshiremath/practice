#include <iostream>

#define ROW 3
#define COL 5

class Solution {
 public:
  Solution() : offset_{-1, 0, 1} {}
  ~Solution() {}

  int NumberOfIsland(bool matrix[ROW][COL]) {
    bool visited[ROW][COL] = {{0}};

    int cluster_count = 0;

    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
        if (matrix[i][j] && !visited[i][j]) {
          cluster_count++;
          DoDFS(matrix, i, j, visited);
        }
      }
    }

    return cluster_count;
  }

 private:
  void DoDFS(bool matrix[ROW][COL], int i, int j, bool visited[ROW][COL]) {
    if (visited[i][j]) {
      return;
    }

    visited[i][j] = true;
    int x_offset, y_offset;

    for (int k = 0; k < 3; k++) {
      x_offset = offset_[k];

      for (int l = 0; l < 3; l++) {
        y_offset = offset_[l];

        if (x_offset == 0 && y_offset == 0) {
          continue;
        }

        if (IsNeighbourPresent(matrix, i + x_offset, j + y_offset)) {
          DoDFS(matrix, i + x_offset, j + y_offset, visited);
        }
      }
    }
  }

  bool IsNeighbourPresent(bool matrix[ROW][COL], int i, int j) {
    if (i >= 0 && i < ROW && j >= 0 && j < COL) {
      if (matrix[i][j] == 1) {
        return true;
      }
    }

    return false;
  }

  int offset_[3];
};

int main(int argc, char const* argv[]) {
  bool matrix[ROW][COL] = {
      {1, 0, 1, 0, 1}, {1, 1, 0, 0, 0}, {0, 1, 0, 1, 1},
  };

  Solution soln;
  std::cout << "Number of islands : " << soln.NumberOfIsland(matrix)
            << std::endl;
  return 0;
}