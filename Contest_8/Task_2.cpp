//
// Created by rhy on 05.11.2021.
//
#include <iostream>

class MyBinaryTree {
private:
    struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *head_;

    void addNode(TreeNode *node, int data) {
        if (node->data > data) {
            if (node->left == nullptr) {
                auto *nd = new TreeNode;
                nd->data = data;
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
                nd->left = nullptr;
                nd->right = nullptr;
                node->right = nd;
            } else {
                addNode(node->right, data);
            }
        }
    }

    int getHeight(TreeNode *node) {
        if (node == nullptr) {
            return -1;
        }
        int left = getHeight(node->left);
        int right = getHeight(node->right);

        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }

    void clear(TreeNode *node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    bool isBalanced(TreeNode *node) {
        if (node == nullptr) {
            return true;
        }
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return std::abs(left - right) <= 1 && isBalanced(node->right) && isBalanced(node->left);
    }

public:
    explicit MyBinaryTree(int data) {
        auto *node = new TreeNode;
        node->data = data;
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

    bool isBalanced() {
        return isBalanced(head_);
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
    if (tree->isBalanced()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    delete tree;
    return 0;
}
