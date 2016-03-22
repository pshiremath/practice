#include <bits/stdc++.h>

std::queue<int> q1, q2, temp;

void push(int data) { q1.push(data); }

int pop() {
  int result;
  if (q1.empty()) {
    return INT_MIN;
  }
  while (q1.size() > 1) {
    q2.push(q1.front());
    q1.pop();
  }
  int data = q1.front();
  q1.pop();
  temp = q1;
  q1 = q2;
  q2 = q1;
  return data;
}

int main(int argc, char const *argv[]) {
  push(10);
  push(20);
  push(30);
  push(40);

  std::cout << pop() << std::endl;
  std::cout << pop() << std::endl;
  return 0;
}