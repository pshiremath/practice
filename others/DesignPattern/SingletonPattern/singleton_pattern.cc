#include <iostream>

class Singleton {
 public:
  static Singleton* GetInstance() {
    static Singleton* instance = new Singleton();
    return instance;
  }

  void ShowMessage() { std::cout << "Showing Message from Singleton class\n"; }

 private:
  Singleton() {}
};

int main(int argc, char const* argv[]) {
  Singleton* si = Singleton::GetInstance();
  si->ShowMessage();
  return 0;
}