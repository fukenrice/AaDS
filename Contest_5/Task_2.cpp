//
// Created by rhy on 05.10.2021.
//

#include <iostream>
#include <string>

class MyDeque {
 private:
    int size;
    int *arr;
    int capacity;

    void Resize() {
        int *new_arr = new int[(capacity + 1) * 2];
        capacity *= 2;
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        delete arr;
        arr = new_arr;
    }


 public:
    MyDeque() {
        size = 0;
        capacity = 10;
        arr = new int[10];
    }

    std::string PushFront(int element) {
        if (size == capacity || size == 0) {
            Resize();
        }
        arr[size++] = element;
        return "ok";
    }

    std::string PushBack(int element) {
        if (size == capacity || size == 0) {
            Resize();
        }
        for (int i = 1; i < size + 1; ++i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        size++;
        return "ok";
    }

    int PopFront() {
        if (size == 0) {
            throw std::out_of_range("error");
        }
        size--;
        return arr[size];
    }

    int PopBack() {
        if (size == 0) {
            throw std::out_of_range("error");
        }
        int element = arr[0];
        for (int i = 0; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
        return element;
    }

    int GetFront() {
        if (size == 0) {
            throw std::out_of_range("error");
        }
        return arr[size - 1];
    }

    int GetBack() {
        if (size == 0) {
            throw std::out_of_range("error");
        }
        return arr[0];
    }

    int Size() {
        return size;
    }

    std::string Clear() {
        arr = new int[10];
        capacity = 10;
        size = 0;
        return "ok";
    }
};


int main() {
    std::string command;
    int argument;
    MyDeque deque = MyDeque();
    do {
        std::cin >> command;
        if (command == "push_front") {
            std::cin >> argument;
            std::cout << deque.PushFront(argument) << std::endl;
        }
        if (command == "push_back") {
            std::cin >> argument;
            std::cout << deque.PushBack(argument) << std::endl;
        }
        if (command == "pop_front") {
            try {
                std::cout << deque.PopFront() << std::endl;
            } catch (std::out_of_range e) {
                std::cout << e.what() << std::endl;
            }
        }
        if (command == "pop_back") {
            try {
                std::cout << deque.PopBack() << std::endl;
            } catch (std::out_of_range e) {
                std::cout << e.what() << std::endl;
            }
        }
        if (command == "front") {
            try {
                std::cout << deque.GetFront() << std::endl;
            } catch (std::out_of_range e) {
                std::cout << e.what() << std::endl;
            }
        }
        if (command == "back") {
            try {
                std::cout << deque.GetBack() << std::endl;
            } catch (std::out_of_range e) {
                std::cout << e.what() << std::endl;
            }
        }
        if (command == "size") {
            std::cout << deque.Size() << std::endl;
        }
        if (command == "clear") {
            std::cout << deque.Clear() << std::endl;
        }
    } while (command != "exit");
    std::cout << "bye";
    return 0;
}
