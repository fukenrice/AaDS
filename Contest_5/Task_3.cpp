////
//// Created by rhy on 05.10.2021.
////
//
//#include <iostream>
//#include <string>
//
//class MyDeque {
// private:
//    int size;
//    int *arr;
//    int capacity;
//    int back_index, top_index;
//    void Resize() {
//        int *new_arr = new int[capacity * 2];
//        capacity *= 2;
//        for (int i = 0; i < size; ++i) {
//            new_arr[i] = arr[i];
//        }
//        delete arr;
//        arr = new_arr;
//    }
//
// public:
//    MyDeque() {
//        size = 0;
//        capacity = 10;
//        arr = new int[capacity];
//        back_index = 0;
//        top_index = 0;
//    }
//
//    void PushMiddle(int element) {
//        int* tmp_arr = new int[size + 1];
//
//        if (size % 2 == 1) {
//            for (int i = back_index; i < top_index / 2 + 1; ++i) {
//                tmp_arr[i - back_index] = arr[i];
//            }
//            tmp_arr[size / 2 + 1] = element;
//            int index = size / 2 + 2;
//            for (int i = top_index / 2 + 2; i < top_index; ++i) {
//                tmp_arr[index++] = arr[i];
//            }
//        } else {
//            for (int i = back_index; i < top_index / 2; ++i) {
//                tmp_arr[i - back_index] = arr[i];
//            }
//            tmp_arr[size / 2] = element;
//            int index = size / 2 + 1;
//            for (int i = top_index / 2 + 1; i < top_index; ++i) {
//                tmp_arr[index++] = arr[i];
//            }
//        }
//        delete arr;
//        arr = tmp_arr;
//        size++;
//    }
//
//    std::string PushFront(int element) {
//        if (size == capacity) {
//            Resize();
//        }
//        size++;
//        arr[top_index++] = element;
//        return "ok";
//    }
//
//    int PopBack() {
//        size--;
//        return arr[back_index++];
//    }
//
//};
//
//
//int main() {
//    char command;
//    int count, argument;
//    MyDeque deque = MyDeque();
//    std::cin >> count;
//    for (int i = 0; i < count; ++i) {
//        std::cin >> command;
//        if (command == '+') {
//            std::cin >> argument;
//            deque.PushFront(argument);
//        }
//        if (command == '*') {
//            std::cin >> argument;
//            deque.PushMiddle(argument);
//        }
//        if (command == '-') {
//            std::cout << deque.PopBack() << std::endl;
//        }
//    }
//    return 0;
//}



//
// Created by rhy on 05.10.2021.
//

#include <iostream>
#include <string>

class MyQueue {
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
    MyQueue() {
        size = 0;
        capacity = 10;
        arr = new int[10];
    }

    void PushMiddle(int element) {
        if (size == capacity) {
            Resize();
        }
        int index = size;
        int index1 = index - 1;
        for (int i = 0; i < size / 2; ++i) {
            arr[index--] = arr[index1--];
        }
        arr[size / 2 + (size % 2)] = element;
        size++;
    }

    std::string PushFront(int element) {
        if (size == capacity || size == 0) {
            Resize();
        }
        arr[size++] = element;
        return "ok";
    }

    int Pop() {
        int element = arr[0];
        for (int i = 0; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
        return element;
    }
};


int main() {
    char command;
    int count, argument;
    MyQueue deque = MyQueue();
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::cin >> command;
        if (command == '+') {
            std::cin >> argument;
            deque.PushFront(argument);
        }
        if (command == '*') {
            std::cin >> argument;
            deque.PushMiddle(argument);
        }
        if (command == '-') {
            std::cout << deque.Pop() << std::endl;
        }
    }
    return 0;
}



