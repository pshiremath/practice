#include <iostream>
#define R 4
#define C 4

int First(bool array[], int start, int end) {
  if (start > end) {
    return -1;
  }

  int mid = (start + end) / 2;
  if (array[mid] == 1 && (array[mid - 1] == 0 || mid == 0)) {
    return mid;
  } else if (array[mid] == 0) {
    return First(array, mid + 1, end);
  } else {
    return First(array, start, mid - 1);
  }

  return -1;
}

int RowWithMax1s(bool mat[R][C]) {
  int max_row_index = 0, max = -1;
  for (int i = 0; i < R; i++) {
    int index = First(mat[i], 0, C - 1);

    if (index != -1 && C - index > max) {
      max_row_index = i;
      max = C - index;
    }
  }
  return max_row_index;
}

int main(int argc, char const *argv[]) {
  bool mat[R][C] = {{0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};

  std::cout << "Index of row with maximum 1s is \n" << RowWithMax1s(mat)
            << std::endl;
  return 0;
}