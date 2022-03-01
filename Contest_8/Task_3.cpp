//
// Created by rhy on 05.11.2021.
//

#include <iostream>

class MyBinaryTree {
private:
    struct TreeNode {
        int data;
        int cnt;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *head_;

    void addNode(TreeNode *node, int data) {
        TreeNode *existing_node = containsNode(head_, data);
        if (existing_node != nullptr) {
            existing_node->cnt++;
        } else {
            if (node->data > data) {
                if (node->left == nullptr) {
                    auto *nd = new TreeNode;
                    nd->data = data;
                    nd->cnt = 1;
                    nd->left = nullptr;
                    nd->right = nullptr;
                    node->left = nd;
                } else {
                    addNode(node->left, data);
                }
            } else if (node->data < data) {
                if (node->right == nullptr) {
                    auto *nd = new TreeNode;
                    nd->data = data;
                    nd->cnt = 1;
                    nd->left = nullptr;
                    nd->right = nullptr;
                    node->right = nd;
                } else {
                    addNode(node->right, data);
                }
            }
        }
    }

    void clear(TreeNode *node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    TreeNode *containsNode(TreeNode *node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->data == value) {
            return node;
        }
        if (value < node->data) {
            return containsNode(node->left, value);
        } else {
            return containsNode(node->right, value);
        }
    }

    void print(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        print(node->left);
        std::cout << node->data << " " << node->cnt << std::endl;
        print(node->right);
    }

public:
    explicit MyBinaryTree(int data) {
        auto *node = new TreeNode;
        node->data = data;
        node->cnt = 1;
        node->left = nullptr;
        node->right = nullptr;
        head_ = node;
    }

    ~MyBinaryTree() {
        clear(head_);
    }

    void addNode(int data) {
        addNode(head_, data);
    }

    void print() {
        print(head_);
    }
};

int main() {
    int num;
    std::cin >> num;
    if (num == 0) {
        std::cout << "YES";
        return 0;
    }
    auto *tree = new MyBinaryTree(num);
    while (num != 0) {
        std::cin >> num;
        if (num == 0) {
            break;
        }
        tree->addNode(num);
    }
    tree->print();
    delete tree;
    return 0;
}
