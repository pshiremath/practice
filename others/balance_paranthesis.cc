#include <iostream>
#include <stack>

bool isParanthesisMatched(char* paranthesis) {
  int i = 0;
  std::stack<char> mStack;

  while (paranthesis[i] != '\0') {
    if (paranthesis[i] == '{' || paranthesis[i] == '(' ||
        paranthesis[i] == '[') {
      mStack.push(paranthesis[i]);
    } else if (paranthesis[i] == '}' || paranthesis[i] == ')' ||
               paranthesis[i] == ']') {
      if (!mStack.empty()) {
        char para = mStack.top();
        if (paranthesis[i] == '}' && para == '{') {
          mStack.pop();
        } else if (paranthesis[i] == ')' && para == '(') {
          mStack.pop();
        } else if (paranthesis[i] == ']' && para == '[') {
          mStack.pop();
        }
      } else {
        return false;
      }
    }
    i++;
  }

  return true;
}

int main(int argc, char const* argv[]) {
  char paranthesis[] = "{[()]}";
  std::cout << isParanthesisMatched(paranthesis) << std::endl;
  return 0;
}