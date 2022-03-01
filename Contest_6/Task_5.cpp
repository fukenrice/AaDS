//
// Created by rhy on 11.10.2021.
//

//
// Created by rhy on 11.10.2021.
//

//
// Created by rhy on 11.10.2021.
//

#include <iostream>
#include <string>

struct Node {
    int data;
    Node *next, *prev;
};

class LinkedList {
private:
    Node *head_, *tail_;

public:
    LinkedList() {
        head_ = nullptr;
        tail_ = nullptr;
    }

    void pushBack(int element) {
        Node *node = new Node;
        node->data = element;
        node->next = nullptr;
        node->prev = nullptr;
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            node->prev = tail_;
            tail_->next = node;
            tail_ = node;
        }
    }

    void insert(int index, int element) {
        int cnt = 0;
        Node *next = head_;
        while (cnt != index) {
            next = next->next;
            cnt++;
        }
        Node *current;
        current->data = element;
        current->prev = nullptr;
        current->next = nullptr;

        if (next == nullptr && tail_ == nullptr) {
            tail_ = current;
            head_ = current;
            return;
        }

        if (next == nullptr && tail_ != nullptr) {
            tail_->next = current;
            current->prev = tail_;
            tail_ = current;
            return;
        }

        if (next->prev == nullptr) {
            next->prev = current;
            current->next = next;
            head_ = current;
            return;
        }

        Node *prev = next->prev;
        prev->next = current;
        current->prev = prev;
        next->prev = current;
        current->next = next;

    }

    void remove(int index) {
        int cnt = 0;
        Node *current = head_;
        while (cnt != index) {
            current = current->next;
            cnt++;
        }

        if (current->next == nullptr && current->prev == nullptr) {
            delete current;
            tail_ = nullptr;
            head_ = nullptr;
            return;
        }

        if (current->prev == nullptr) {
            current->next->prev = nullptr;
            head_ = current->next;
            delete current;
            return;
        }

        if (current->next == nullptr) {
            current->prev->next = nullptr;
            tail_ = current->prev;
            delete current;
            return;
        }

        Node *prev = current->prev;
        Node *next = current->next;
        delete current;
        prev->next = next;
        next->prev = prev;
    }

    int at(int index) {
        while ();
    }

    Node *getHead() {
        return head_;
    }

    Node *getTail() {
        return tail_;
    }

    void print() {
        Node *tmp = head_;
        while (tmp != nullptr) {
            std::cout << tmp->data << ' ';
            tmp = tmp->next;
        }
    }

    void printReverse() {
        Node *tmp = tail_;
        while (tmp != nullptr) {
            std::cout << tmp->data << ' ';
            Node *del = tmp;
            tmp = tmp->prev;
            delete del;
        }
    }
};

int main() {
    LinkedList list = LinkedList();
    int cnt, commands_num, element;
    std::cin >> cnt;
    std::cin >> commands_num;
    std::string command;
    for (int i = 0; i < cnt; ++i) {
        std::cin >> element;
        list.pushBack(element);
    }

    for (int i = 0; i < commands_num; ++i) {
        std::cin >> command;
        if (command == "push_front") {
            std::cin >> element;
            list.pushFront(element);
        }
        if (command == "push_back") {
            std::cin >> element;
            list.pushBack(element);
        }
        if (command == "insert") {
            int index;
            std::cin >> element >> index;
            list.insert(index, element);
        }
        if (command == "remove") {
            int index;
            std::cin >> index;
            list.remove(index);
        }
    }
    list.print();
    std::cout << std::endl;
    list.printReverse();
}
