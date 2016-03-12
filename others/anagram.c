#include <stdio.h>
#include <string.h>

void merge(char* str, int start, int mid, int high) {
  int n1 = mid - start + 1;
  int n2 = high - mid;
  int L[n1], R[n2];
  int i, j, k;

  for (i = 0; i < n1; i++) {
    L[i] = str[start + i];
  }

  for (i = 0; i < n2; i++) {
    R[i] = str[mid + i + 1];
  }

  i = 0, j = 0, k = start;

  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      str[k] = L[i];
      k++;
      i++;
    } else {
      str[k] = R[j];
      k++;
      j++;
    }
  }

  while (i < n1) {
    str[k] = L[i];
    k++;
    i++;
  }

  while (j < n2) {
    str[k] = R[j];
    k++;
    j++;
  }
}

void mergeSort(char* str, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergeSort(str, start, mid);
    mergeSort(str, mid + 1, end);
    merge(str, start, mid, end);
  }
}

int isAnagram(char str1[], char str2[]) {
  int length1 = strlen(str1);
  int length2 = strlen(str2);

  if (length1 != length2) {
    return 0;
  }

  mergeSort(str1, 0, length1 - 1);
  mergeSort(str2, 0, length2 - 1);

  for (int i = 0; i < length1; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
  }

  return 1;
}

int main(int argc, char const* argv[]) {
  char str1[] = "test";
  char str2[] = "ttes";

  if (isAnagram(str1, str2)) {
    printf("Both the strings are anagram of each other\n");
  } else {
    printf("Not an anagram \n");
  }
  return 0;
}