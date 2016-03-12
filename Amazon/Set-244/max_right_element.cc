#include <stdio.h>

void PrintNextGreatest(int arr[], int size) {
  int temp[size];
  int max = -1;

  temp[size - 1] = max;
  for (int count = size - 2; count >= 0; count--) {
    if (arr[count] > max) {
      max = arr[count];
    }
    temp[count] = max;
  }
  printf("Original array \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("Right Next Greater array \n");
  for (int i = 0; i < size; i++) {
    printf("%d ", temp[i]);
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {16, 17, 4, 3, 5, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  PrintNextGreatest(arr, size);
  return 0;
}