#include <bits/stdc++.h>

class Stack {
 public:
  Stack();
  ~Stack();
  bool isEmpty();
  bool isFull();
  int pop();
  void push(int x);

 private:
  static const int max = 100;
  int arr[max];
  int top;
};

Stack::Stack() { top = -1; }

Stack::~Stack() {}

bool Stack::isEmpty() {
  if (top == -1) return true;
  return false;
}

bool Stack::isFull() {
  if (top == max - 1) return true;
  return false;
}

int Stack::pop() {
  if (isEmpty()) {
    std::cout << "Stack underflow";
    return -1;
  }

  int x = arr[top];
  top--;
  return x;
}

void Stack::push(int x) {
  if (isFull()) {
    std::cout << "Stack Overflow";
    return;
  }
  top++;
  arr[top] = x;
}

class SpecialStack : public Stack {
 public:
  int pop();
  void push(int x);
  int getMin();

 private:
  Stack sp_st;
};

void SpecialStack::push(int x) {
  if (isEmpty() == true) {
    Stack::push(x);
    sp_st.push(x);
  } else {
    Stack::push(x);
    int y = sp_st.pop();
    sp_st.push(y);
    if (x < y)
      sp_st.push(x);
    else
      sp_st.push(y);
  }
}

int SpecialStack::pop() {
  int x = Stack::pop();
  sp_st.pop();
  return x;
}

int SpecialStack::getMin() {
  int x = sp_st.pop();
  sp_st.push(x);
  return x;
}

int main(int argc, char const *argv[]) {
  SpecialStack s;
  s.push(10);
  s.push(20);
  s.push(30);
  std::cout << s.getMin() << std::endl;
  s.push(5);
  std::cout << s.getMin();
  return 0;
}