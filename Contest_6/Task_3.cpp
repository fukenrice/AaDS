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

    void pushFront(int element) {
        Node *node = new Node;
        node->data = element;
        node->next = nullptr;
        node->prev = nullptr;
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            node->next = head_;
            head_->prev = node;
            head_ = node;
        }
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
            current->prev = prev;
            current->next = next;
            prev->next = current;
            next->prev = current;
        } else {
            Node *current = new Node;
            current->data = element;
            current->prev = prev;
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
        if (next != nullptr) {
            next->prev = prev;
        } else {
            tail_ = prev;
        }
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
