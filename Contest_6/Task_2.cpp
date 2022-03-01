//
// Created by rhy on 11.10.2021.
//

#include <iostream>

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

    Node *getTail() {
        return tail_;
    }

    void print() {
        Node *tmp = tail_;
        while (tmp != nullptr) {
            std::cout << tmp->data << ' ';
            Node *del = tmp;
            tmp = tmp->next;
            delete del;
        }
    }

    void reverse() {
        Node *cur, *prev, *next;
        prev = head_;
        cur = prev->next;
        next = cur->next;
        prev->next = nullptr;
        while (next != nullptr) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        prev = cur;
    }
};

int main() {
    LinedList list = LinedList();
    int cnt, element;
    std::cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
        std::cin >> element;
        list.add(element);
    }
    if (cnt > 1) {
        list.reverse();
        list.print();
    } else {
        list.print();
    }
    return 0;
}
