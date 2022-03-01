#include <iostream>

class MyBinaryTree {
private:
    struct TreeNode {
        int key;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *head_;

    void addNode(int key) {
        TreeNode *curr = head_;
        while (curr) {
            if (curr->key == key) {
                break;
            }
            if (curr->right && curr->right->key < key) {
                curr = curr->right;
                continue;
            }
            if (curr->left && curr->left->key > key) {
                curr = curr->left;
                continue;
            }
            break;
        }
        // Если правый, то:
        if (curr->key < key) {
            auto *input = new TreeNode();
            input->right = curr->right;
            input->key = key;
            curr->right = input;
        }
        if cu

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

public:
    explicit MyBinaryTree(int data) {
        auto *node = new TreeNode;
        node->key = data;
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

    int getHeight() {
        return getHeight(head_);
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
    std::cout << tree->getHeight() + 1;
    delete tree;
    return 0;
}
