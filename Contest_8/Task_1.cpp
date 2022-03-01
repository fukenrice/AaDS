#include <iostream>
#include <string>

struct Node {
    int number;
    int value;
    int left_index, right_index;
    bool is_red;
    Node *left;
    Node *right;
    Node *parent;
};

class MyRBTree {
private:
    Node *head_;

    bool isValid(Node *node, int blacks_before, int total_blacks) {
        if (node == nullptr) {
            return blacks_before + 1 == total_blacks;
        }

        if (node->parent != nullptr) {
            if (node->is_red && node->parent->is_red) {
                return false;
            }
        }

        if (!node->is_red) {
            blacks_before++;
        }

        return isValid(node->left, blacks_before, total_blacks) &&
               isValid(node->right, blacks_before, total_blacks);
    }

    bool isSearchTree(Node *node, int min_value, int max_value) {
        if (node == nullptr) {
            return true;
        }
        return node->value > min_value && node->value < max_value &&
               isSearchTree(node->left, min_value, node->value) &&
               isSearchTree(node->right, node->value, max_value);
    }

    bool isSearchTree(Node *node) {
        if (node == nullptr) {
            return true;
        }
        if (node->left != nullptr && node->left->value >= node->value ||
            node->left != nullptr && node->right->value <= node->value) {
            return false;
        }
        return isSearchTree(node->left) && isSearchTree(node->right);
    }

    void clear(Node *node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    explicit MyRBTree(Node *node) {
        head_ = node;
    }

    ~MyRBTree() {
        clear(head_);
    }

    bool isValid() {
        if (head_->is_red) {
            return false;
        }

        if (!isSearchTree(head_, INT32_MIN, INT32_MAX)) {
            return false;
        }

        int black_cnt = 1;
        Node *curr = head_;
        while (curr != nullptr) {
            if (!curr->is_red) {
                black_cnt++;
            }
            curr = curr->left;
        }
        return isValid(head_, 0, black_cnt);
    }
};

Node **inputInArray(int num) {
    int index, value;
    Node **arr = new Node *[num];
    for (int i = 0; i < num; ++i) {
        arr[i] = nullptr;
    }
    std::string color, left_index, right_index;
    for (int loop_index = 0; loop_index < num; ++loop_index) {
        Node *nd = new Node;
        std::cin >> index >> value >> left_index >> right_index >> color;
        nd->number = index;
        nd->value = value;
        if (left_index == "null") {
            nd->left_index = -1;
        } else {
            nd->left_index = std::stoi(left_index);
        }
        if (right_index == "null") {
            nd->right_index = -1;
        } else {
            nd->right_index = std::stoi(right_index);
        }
        nd->is_red = color == "R";
        nd->parent = nullptr;
        nd->left = nullptr;
        nd->right = nullptr;
        arr[index - 1] = nd;
    }
    return arr;
}

void makeTree(Node **arr, int num) {
    for (int loop_index = 0; loop_index < num; ++loop_index) {
        if (arr[loop_index]->left_index != -1) {
            arr[loop_index]->left = arr[arr[loop_index]->left_index - 1];
            arr[arr[loop_index]->left_index - 1]->parent = arr[loop_index];
        } else {
            arr[loop_index]->left = nullptr;
        }
        if (arr[loop_index]->right_index != -1) {
            arr[loop_index]->right = arr[arr[loop_index]->right_index - 1];
            arr[arr[loop_index]->right_index - 1]->parent = arr[loop_index];
        } else {
            arr[loop_index]->right = nullptr;
        }
    }
}

int main() {
    int num, root_index;
    std::cin >> num;
    if (num == 0) {
        std::cout << "YES";
        return 0;
    }
    std::cin >> root_index;
    Node **arr = inputInArray(num);
    makeTree(arr, num);
    auto *tree = new MyRBTree(arr[root_index - 1]);
    if (tree->isValid()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    delete tree;
    delete[] arr;
    return 0;
}
