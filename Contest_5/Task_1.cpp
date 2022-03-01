#include <iostream>
#include <string>

class MyStack {
 private:
  int size;
  int top;
  int *arr;
  int capacity;

  void Resize() {
    int *new_arr = new int[capacity * 2];
    capacity *= 2;
    for (int i = 0; i < size; ++i) {
      new_arr[i] = arr[i];
    }
    delete arr;
    arr = new_arr;
  }

 public:
  MyStack() {
    size = 0;
    top = -1;
    capacity = 10;
    arr = new int[10];
  }

  ~MyStack() {
      delete[] arr;
  }

  std::string Push(int element) {
    if (size == capacity) {
      Resize();
    }
    arr[size++] = element;
    top = element;
    return "ok";
  }

  int Pop() {
    if (size == 0) {
      throw std::out_of_range("error");
    } else {
      int old = top;
      size--;
      top = arr[size - 1];
      return old;
    }
  }

  int Back() {
    if (size == 0) {
      throw std::out_of_range("error");
    } else {
      return top;
    }
  }

  int Size() {
    return size;
  }

  std::string Clear() {
    delete[] arr;
    size = 0;
    top = -1;
    capacity = 10;
    arr = new int[10];
    return "ok";
  }
};

int main() {
  std::string command;
  int argument;
  MyStack stack = MyStack();
  do {
    std::cin >> command;
    if (command == "push") {
      std::cin >> argument;
      std::cout << stack.Push(argument) << std::endl;
    }
    if (command == "pop") {
      try {
        std::cout << stack.Pop() << std::endl;
      } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
      }
    }
    if (command == "back") {
      try {
        std::cout << stack.Back() << std::endl;
      } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
      }
    }
    if (command == "size") {
      std::cout << stack.Size() << std::endl;
    }
    if (command == "clear") {
      std::cout << stack.Clear() << std::endl;
    }
  } while (command != "exit");
  std::cout << "bye";
  return 0;
}
