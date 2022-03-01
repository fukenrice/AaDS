//
// Created by rhy on 11.10.2021.
//

#include <iostream>
#include <string>

struct Node {
    int data;
    Node *next;
};

class LinedList {
private:
    Node *head_, *tail_;

public:
    LinedList() {
        head_ = nullptr;
        tail_ = nullptr;
    }

    void add(int element) {
        Node *node = new Node;
        node->data = element;
        node->next = nullptr;
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            tail_ = node;
        }
    }

    Node *getHead() {
        return head_;
    }

    void insert(int index, int element) {
        int cnt = 0;
        Node *prev = head_;
        while (cnt != index) {
            prev = prev->next;
            cnt++;
        }
        Node *next = prev->next;
        if (next != nullptr) {
            Node *current = new Node;
            current->data = element;
            current->next = next;
            prev->next = current;
        } else {
            Node *current = new Node;
            current->data = element;
            current->next = next;
            prev->next = current;
            tail_ = current;
        }
    }

    void remove(int index) {
        int cnt = 0;
        Node *prev = head_;
        while (cnt != index) {
            prev = prev->next;
            cnt++;
        }
        Node *next = prev->next->next;
        delete prev->next;
        prev->next = next;
    }

    Node *getTail() {
        return tail_;
    }

    void print() {
        Node *tmp = head_;
        while (tmp != nullptr) {
            std::cout << tmp->data << ' ';
            Node *del = tmp;
            tmp = tmp->next;
            delete del;
        }
    }
};

int main() {
    LinedList list = LinedList();
    int cnt, commands_num, element;
    std::cin >> cnt;
    std::cin >> commands_num;
    std::string command;
    for (int i = 0; i < cnt; ++i) {
        std::cin >> element;
        list.add(element);
    }

    for (int i = 0; i < commands_num; ++i) {
        std::cin >> command;
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
    return 0;
}
