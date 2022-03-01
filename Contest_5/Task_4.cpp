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
        top = 0;
        capacity = 10;
        arr = new char[10];
    }

    void Push(char element) {
        if (size == capacity) {
            Resize();
        }
        arr[size++] = element;
        top = element;
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

    void Clear() {
        delete arr;
        size = 0;
        top = 0;
        capacity = 10;
        arr = new char[10];
    }
};

int main() {
    std::string sequence;
    std::cin >> sequence;
    MyStack stack = MyStack();
    if (sequence.empty()) {
        std::cout << "yes";
        return 0;
    }
    for (int i = 0; i < sequence.length(); ++i) {
        if (stack.Size() == 0) {
            stack.Push(sequence.at(i));
        } else if (stack.Back() == '[' && sequence.at(i) == ']') {
            stack.Pop();
        } else if (stack.Back() == '(' && sequence.at(i) == ')') {
            stack.Pop();
        } else if (stack.Back() == '{' && sequence.at(i) == '}') {
            stack.Pop();
        } else {
            stack.Push(sequence.at(i));
        }
    }
    if (stack.Size() == 0) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}
