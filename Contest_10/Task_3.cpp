#include <iostream>

struct Node {
    int value;
    Node *next;
    explicit Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *tail;
    Node *head;

    void clear(Node *nd) {
        if (nd == nullptr) {
            return;
        }
        clear(nd->next);
        delete nd;
    }

    explicit LinkedList(int key) {
        Node *root = new Node(key);
        head = root;
        tail = root;
    }
};

struct UnionFind {
    int *parent;
    int *size;
    LinkedList **arr;
    int max_size;
    explicit UnionFind(int max_size) {
        parent = new int[max_size];
        size = new int[max_size];
        arr = new LinkedList *[max_size];
        for (int i = 1; i < max_size; ++i) {
            arr[i] = new LinkedList(i);
        }
        arr[0] = nullptr;
        this->max_size = max_size;
    }

    ~UnionFind() {
        delete[] parent;
        delete[] size;
        for (int i = 0; i < max_size; ++i) {
            delete arr[i];
        }
        delete[] arr;
    }

    void makeSet(int element) {
        parent[element] = element;
        size[element] = 1;
    }

    int findSet(int element) {
        if (parent[element] == element) {
            return element;
        }
        // Переназначаем родителя(сжатие путей), чтобы поиск не занимал много времени.
        return parent[element] = findSet(parent[element]);
    }

    int unionSets(int l_element, int r_element) {
        l_element = findSet(l_element);
        r_element = findSet(r_element);
        if (l_element == r_element) {
            return size[l_element];
        }
        parent[l_element] = r_element;
        size[r_element] += size[l_element];
        arr[r_element]->head->next = arr[l_element]->tail;
        arr[r_element]->head = arr[l_element]->head;
        return size[r_element];
    }
};

int main() {
    int number;
    int first_cell, second_cell;
    std::cin >> number;
    auto *sets = new UnionFind(number + 1);
    for (int i = 1; i < number + 1; ++i) {
        sets->makeSet(i);
    }

    for (int index = 0; index < number - 1; ++index) {
        std::cin >> first_cell >> second_cell;
        if (sets->unionSets(first_cell, second_cell) == number) {
            Node *curr = sets->arr[sets->findSet(first_cell)]->tail;
            while (curr) {
                std::cout << curr->value << " ";
                curr = curr->next;
            }
            break;
        }
    }
    // Удаляем все ноды.
    sets->arr[sets->findSet(first_cell)]->clear(sets->arr[sets->findSet(first_cell)]->tail);
    delete sets;
}
