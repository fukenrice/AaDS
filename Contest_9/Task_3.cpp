#include <iostream>
struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;
    explicit Node(int value) {
        left = nullptr;
        right = nullptr;
        key = value;
        parent = nullptr;
    }
};

class SplayTree {
private:
    Node *head_;

    int getHeight(Node *node) const {
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

    void clear(Node *node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void leftRotate(Node *root) {
        Node *new_root = root->right;
        new_root->parent = root->parent;
        if (new_root->left) {
            new_root->left->parent = root;
        }
        if (root->parent) {
            if (root->parent->left == root) {
                root->parent->left = new_root;
            } else {
                root->parent->right = new_root;
            }
        }
        root->right = new_root->left;
        root->parent = new_root;
        new_root->left = root;
    }

    void rightRotate(Node *root) {
        Node *new_root = root->left;
        new_root->parent = root->parent;
        if (new_root->right) {
            new_root->right->parent = root;
        }
        if (root->parent) {
            if (root->parent->left == root) {
                root->parent->left = new_root;
            } else {
                root->parent->right = new_root;
            }
        }
        root->left = new_root->right;
        root->parent = new_root;
        new_root->right = root;
    }

public:
    SplayTree() {
        head_ = nullptr;
    }

    ~SplayTree() {
        clear(head_);
    }

    Node *find(int key) {
        Node *curr = head_;
        while (curr) {
            if (curr->key == key) {
                return curr;
            }
            if (curr->key < key) {
                curr = curr->right;
                continue;
            }
            if (curr->key > key) {
                curr = curr->left;
                continue;
            }
        }
        return nullptr;
    }

    int splay(Node *node) {
        int cnt = 0;
        while (node->parent) {
            if (node->parent->parent) {
                // zag - left
                // zig - right
                // zig zag/ zag zig/ zig zig/ zag zag
                // zag zag
                if (node->parent->right == node && node->parent->parent->right == node->parent) {
                    leftRotate(node->parent->parent);
                    leftRotate(node->parent);
                    cnt += 2;
                    continue;
                }
                // zig zig
                if (node->parent->left == node && node->parent->parent->left == node->parent) {
                    rightRotate(node->parent->parent);
                    rightRotate(node->parent);
                    cnt += 2;
                    continue;
                }
                // zag zig
                if (node->parent->left == node && node->parent->parent->right == node->parent) {
                    rightRotate(node->parent);
                    leftRotate(node->parent);
                    cnt++;
                    continue;
                }
                // zig zag
                if (node->parent->right == node && node->parent->parent->left == node->parent) {
                    leftRotate(node->parent);
                    rightRotate(node->parent);
                    cnt++;
                    continue;
                }
            } else {
                if (node->parent->left == node) {
                    rightRotate(node->parent);
                    cnt++;
                } else {
                    leftRotate(node->parent);
                    cnt++;
                }
            }
        }
        head_ = node;
        return cnt;
    }

    void insert(int key) {
        if (!head_) {
            head_ = new Node(key);
            return;
        }
        Node *parent = nullptr;
        Node *curr = head_;
        while (curr) {
            parent = curr;
            if (curr->key > key) {
                curr = curr->left;
            } else if (curr->key < key) {
                curr = curr->right;
            } else {
                return;
            }
        }
        Node *new_node = new Node(key);
        if (parent->key < key) {
            parent->right = new_node;
            new_node->parent = parent;
        } else {
            parent->left = new_node;
            new_node->parent = parent;
        }
    }

    int getHeight() const {
        if (head_) {
            return getHeight(head_);
        } else {
            return 0;
        }
    }
};
