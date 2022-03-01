#include <iostream>
#include <fstream>
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

    void addNode(Node *node) {
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            tail_ = node;
        }
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

LinedList concat(LinedList list_1, LinedList list_2) {
    LinedList res = LinedList();

    Node *element_from_first = list_1.getHead();
    Node *element_from_second = list_2.getHead();
    while (element_from_first != nullptr || element_from_second != nullptr) {
        if (element_from_first == nullptr) {
            res.addNode(element_from_second);
            element_from_second = element_from_second->next;
        } else if (element_from_second == nullptr) {
            res.addNode(element_from_first);
            element_from_first = element_from_first->next;
        } else {
            if (element_from_first->data < element_from_second->data) {
                res.addNode(element_from_first);
                element_from_first = element_from_first->next;
            } else {
                res.addNode(element_from_second);
                element_from_second = element_from_second->next;
            }
        }
    }
    return res;
}

int main() {
    LinedList l_1 = LinedList();
    LinedList l_2 = LinedList();
    int cnt_1, cnt_2, tmp;
    std::cin >> cnt_1 >> cnt_2;

    for (int i = 0; i < cnt_1; ++i) {
        std::cin >> tmp;
        l_1.add(tmp);
    }
    for (int i = 0; i < cnt_2; ++i) {
        std::cin >> tmp;
        l_2.add(tmp);
    }
    LinedList list = concat(l_1, l_2);
    list.print();
    return 0;
}
