//
// Created by rhy on 25.10.2021.
//

#include <iostream>

class MyBinaryTree {
private:
    struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
    };
    TreeNode *head_;

    void addNode(TreeNode *node, int data) {
        if (node->data > data) {
            if (node->left == nullptr) {
                auto *nd = new TreeNode;
                nd->data = data;
                nd->left = nullptr;
                nd->right = nullptr;
                nd->parent = node;
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
                nd->parent = node;
            } else {
                addNode(node->right, data);
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

    TreeNode *getMax(TreeNode *node) {
        if (node->right != nullptr) {
            TreeNode *max = node->right;
            while (max->right != nullptr) {
                max = max->right;
            }
            return max;
        } else {
            return node;
        }
    }

public:
    explicit MyBinaryTree(int data) {
        auto *node = new TreeNode;
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        head_ = node;
    }

    ~MyBinaryTree() {
        clear(head_);
    }

    void addNode(int data) {
        addNode(head_, data);
    }

    int getSecondMax() {
        TreeNode *max = getMax(head_);
        if (max->left != nullptr) {
            return getMax(max->left)->data;
        } else {
            return max->parent->data;
        }
    }
};

int main() {
    int num;
    std::cin >> num;
    if (num == 0) {
        std::cout << 0;
        return 0;
    }
    auto *tree = new MyBinaryTree(num);
    while (true) {
        std::cin >> num;
        if (num == 0) {
            break;
        }
        tree->addNode(num);
    }
    std::cout << tree->getSecondMax();
    delete tree;
    return 0;
}
