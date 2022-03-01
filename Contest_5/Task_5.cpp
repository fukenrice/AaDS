//
// Created by rhy on 06.10.2021.
//

#include <iostream>
#include <string>

class MyStack {
 private:
  int size;
  char top;
  char *arr;
  int capacity;

  void Resize() {
    char *new_arr = new char[capacity * 2];
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
    arr = new char[10];
  }

  std::string Push(char element) {
    if (size == capacity) {
      Resize();
    }
    arr[size++] = element;
    top = element;
    return "ok";
  }

  char Pop() {
    if (size == 0) {
      throw std::out_of_range("error");
    } else {
      char old = top;
      size--;
      top = arr[size - 1];
      return old;
    }
  }

  char Back() {
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
    delete arr;
    size = 0;
    top = -1;
    capacity = 10;
    arr = new char[10];
    return "ok";
  }
};

std::string Repeat(std::string str, int n) {
  if (n == 0) {
    return "";
  }
  std::string res = "";
  for (int i = 0; i < n; ++i) {
    res += str;
  }
  return res;
}

std::string GetSubstr(std::string str) {
  int start, end;
  for (int i = 0; i < str.length(); ++i) {
    if (str.at(i) == '[') {
      start = i;
      break;
    }
  }
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str.at(i) == ']') {
      end = i;
      break;
    }
  }
  if (end != 0) {
    return str.substr(start + 1, end - start - 1);
  } else {
    return str;
  }
}

bool Contains(char ch, std::string str) {
  for (int i = 0; i < str.length(); ++i) {
    if (str.at(i) == ch) {
      return true;
    }
  }
  return false;
}

std::string UnzipString(std::string str) {

  MyStack stack = MyStack();

  std::string tmp_str = "";
  std::string res = "";

  char element;

  for (int i = 0; i < str.length(); ++i) {
    if (str.at(i) == ']') {
      element = stack.Pop();
      while (element != '[') {
        tmp_str += element;
        element = stack.Pop();
      }
      char a = stack.Pop();
      std::string s(1, a);
      std::cout << s;
      res += Repeat(tmp_str, std::stoi(s));
      tmp_str = "";
    } else {
      stack.Push(str.at(i));
    }
  }
  std::reverse(res.begin(), res.end());
  return res;
}

int main() {
  std::string str;
  std::cin >> str;
  std::cout << UnzipString(str);
  return 0;
}

