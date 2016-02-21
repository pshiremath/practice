#include <iostream>

#define R 3
#define C 6

void SpiralPrint(int m, int n, int matrix[R][C]) {
#if 0
	k -> starting row index
	l -> starting column index
	m -> ending row index
	n -> ending column index
#endif
  int i = 0, k = 0, l = 0;

  while (k < m && l < n) {
    for (int i = l; i < n; i++) {
      std::cout << matrix[k][i] << " ";
    }
    k++;

    for (int i = k; i < m; i++) {
      std::cout << matrix[i][n - 1] << " ";
    }
    n--;

    if (k < m) {
      for (int i = n - 1; i >= l; i--) {
        std::cout << matrix[m - 1][i] << " ";
      }
      m--;
    }

    if (l < n) {
      for (int i = m - 1; i >= k; i--) {
        std::cout << matrix[i][l] << " ";
      }
      l++;
    }
  }
}

/* Driver program to test above functions */
int main() {
  int a[R][C] = {
      {1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};

  SpiralPrint(R, C, a);
  return 0;
}
