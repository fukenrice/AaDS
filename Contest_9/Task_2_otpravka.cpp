#include <climits>
#include <iostream>

class Node {
public:
    bool leaf_;
    int *key_, size_, power_;
    Node **children_;
    explicit Node(int power) {
        this->power_ = power;
        key_ = new int[power * 2 - 1];
        children_ = new Node *[2 * power];
        for (int i = 0; i < 2 * power; ++i) {
            children_[i] = nullptr;
        }
    }

    ~Node() {
        delete[] key_;
        delete[] children_;
    }
};

class BPlusTree {
    int power_;

    Node *root_;

    void printLeaves(Node *curr) {
        while (!curr->leaf_) {
            curr = curr->children_[0];
        }
        while (curr != nullptr) {
            for (int i = 0; i < curr->size_; ++i) {
                std::cout << curr->key_[i] << " ";
            }
            std::cout << std::endl;
            curr = curr->children_[curr->size_];
        }
    }

    void split(Node *node) {
        Node *new_node = new Node(power_);
        new_node->children_[power_] = node->children_[node->size_];
        new_node->size_ = power_;
        node->children_[node->size_] = nullptr;
        node->size_ = power_ - 1;
        node->children_[node->size_] = new_node;
        new_node->leaf_ = true;
        for (int i = 0; i < power_; ++i) {
            new_node->key_[i] = node->key_[node->size_ + i];
        }
        if (node == root_) {
            Node *new_root = new Node(power_);
            new_root->key_[0] = new_node->key_[0];
            new_root->size_ = 1;
            new_root->children_[0] = node;
            new_root->children_[1] = new_node;
            new_root->leaf_ = false;
            root_ = new_root;
        } else {
            insertNotLeaf(new_node->key_[0], findParent(root_, node), new_node);
        }
    }

    // curr - текущий нод, child - новый нод, key - индекс(меньший элемент ребенка).
    void insertNotLeaf(int key, Node *curr, Node *child) {
        // Если текущий не полон.
        if (curr->size_ < 2 * power_ - 1) {
            int index = 0;
            // Находим место, на которое поставим индекс.
            while (key > curr->key_[index] && index < curr->size_) {
                index++;
            }
            // Сдвигаем остальне ключи.
            for (int j = curr->size_; j > index; --j) {
                curr->key_[j] = curr->key_[j - 1];
            }
            // Сдвигаем детей.
            for (int j = curr->size_ + 1; j > index + 1; --j) {
                curr->children_[j] = curr->children_[j - 1];
            }
            // Добавляем новый индекс и соответствующего ребенка по индексу.
            curr->key_[index] = key;
            curr->size_++;
            curr->children_[index + 1] = child;
        } else {
            // Если текущий полон(надо сплитануть).
            // Создаем новый нод.
            Node *new_internal = new Node(power_);
            // Создаем массив ключей, в который добавим новый индекс и сплитанем его.
            int *virtual_key = new int[2 * power_];
            // Создаем массив детей, в который добавим новый нод и сплитанем его.
            Node **virtual_ptr = new Node *[2 * power_ + 1];
            // Переносим в массив значения заполненного родителя.
            for (int i = 0; i < 2 * power_ - 1; ++i) {
                virtual_key[i] = curr->key_[i];
            }
            // Переносим в массив детей заполненного родителя.
            for (int i = 0; i < 2 * power_; ++i) {
                virtual_ptr[i] = curr->children_[i];
            }
            int index = 0, virtual_index;
            // Находим место для ключа.
            while (key > virtual_key[index] && index < 2 * power_ - 1) {
                index++;
            }
            // Двигаем ключи, чтобы вставить элемент.
            for (int j = 2 * power_ - 1; j > index; --j) {
                virtual_key[j] = virtual_key[j - 1];
            }
            // Вставляем элемент.
            virtual_key[index] = key;
            // Двигаем детей, чтобы вставить новго.
            for (int j = 2 * power_; j > index + 1; --j) {
                virtual_ptr[j] = virtual_ptr[j - 1];
            }
            // Вставляем нового ребенка.
            virtual_ptr[index + 1] = child;

            for (int i = 0; i < 2 * power_ - 1; ++i) {
                curr->key_[i] = virtual_key[i];
            }
            for (int i = 0; i < 2 * power_; ++i) {
                curr->children_[i] = virtual_ptr[i];
            }

            // Новый нод содержит индексы.
            new_internal->leaf_ = false;
            // Размер текущего уменьшаем вдвое.
            curr->size_ = power_;
            // Новый нод содержит вторую половину.
            new_internal->size_ = power_ - 1;
            // Переносим ключи в новый нод.
            for (index = 0, virtual_index = curr->size_ + 1; index < new_internal->size_;
                 ++index, ++virtual_index) {
                new_internal->key_[index] = virtual_key[virtual_index];
            }
            delete[] virtual_key;
            // Переносим детей в новый нод.
            for (index = 0, virtual_index = curr->size_ + 1; index < new_internal->size_ + 1;
                 ++index, ++virtual_index) {
                new_internal->children_[index] = virtual_ptr[virtual_index];
            }
            delete[] virtual_ptr;
            // Остановка рекурсии
            if (curr == root_) {
                // curr->children_size_ = 0;
                Node *new_root = new Node(power_);
                new_root->key_[0] = curr->key_[curr->size_];
                new_root->children_[0] = curr;
                new_root->children_[1] = new_internal;
                new_root->leaf_ = false;
                new_root->size_ = 1;
                root_ = new_root;
            } else {
                // Вставляем новый нод(в котором элементы правые в родителя текущего)
                insertNotLeaf(curr->key_[curr->size_], findParent(root_, curr), new_internal);
            }
        }
    }

    Node *findParent(Node *curr, Node *child) {
        Node *parent = nullptr;
        // Если текущий лист или уровнем выше листа, то возвращаем ничего.
        if (curr->leaf_) {
            return nullptr;
        }
        // Проходим по всем потомкам и ищем родителя.
        for (int i = 0; i < curr->size_ + 1; ++i) {
            if (curr->children_[i] == child) {
                return curr;
            }
            if (parent != nullptr) {
                return parent;
            }
            parent = findParent(curr->children_[i], child);
        }
        return parent;
    }

public:
    explicit BPlusTree(int power) {
        root_ = nullptr;
        this->power_ = power;
    }

    void clear(Node *root) {
        if (root == nullptr) {
            return;
        }
        if (!root->leaf_) {
            for (int i = 0; i < root->size_ + 1; ++i) {
                clear(root->children_[i]);
            }
        }
        delete root;
    }

    ~BPlusTree() {
        clear(root_);
    }

    bool search(int key) {
        if (root_ == nullptr) {
            return false;
        } else {
            Node *curr = root_;
            while (!curr->leaf_) {
                for (int i = 0; i < curr->size_; ++i) {
                    if (key < curr->key_[i]) {
                        curr = curr->children_[i];
                        break;
                    }
                    if (i == curr->size_ - 1) {
                        curr = curr->children_[i + 1];
                        break;
                    }
                }
            }
            for (int i = 0; i < curr->size_; ++i) {
                if (curr->key_[i] == key) {
                    return true;
                }
            }
            return false;
        }
    }

    void insert(int key) {
        if (root_ == nullptr) {
            root_ = new Node(power_);
            root_->key_[0] = key;
            root_->leaf_ = true;
            root_->size_ = 1;
        } else {
            if (search(key)) {
                return;
            }
            Node *curr = root_;
            Node *parent;
            // Ищем лист, в который добавим новое значение
            while (!curr->leaf_) {
                parent = curr;
                for (int i = 0; i < curr->size_; ++i) {
                    if (key < curr->key_[i]) {
                        curr = curr->children_[i];
                        break;
                    }
                    if (i == curr->size_ - 1) {
                        curr = curr->children_[i + 1];
                        break;
                    }
                }
            }
            // Если лист не полный.
            if (curr->size_ < 2 * power_ - 1) {
                int index = 0;
                while (key > curr->key_[index] && index < curr->size_) {
                    index++;
                }
                // Сдвигаем элементы вправо, чтобы освободить место под новый.
                for (int j = curr->size_; j > index; --j) {
                    curr->key_[j] = curr->key_[j - 1];
                }
                // Вставляем значение.
                curr->key_[index] = key;
                curr->size_++;
                curr->children_[curr->size_] = curr->children_[curr->size_ - 1];
                curr->children_[curr->size_ - 1] = nullptr;
            } else {
                // Если лист полный.
                split(curr);
                curr = root_;
                // Ищем лист, в который добавим новое значение
                while (!curr->leaf_) {
                    parent = curr;
                    for (int i = 0; i < curr->size_; ++i) {
                        if (key < curr->key_[i]) {
                            curr = curr->children_[i];
                            break;
                        }
                        if (i == curr->size_ - 1) {
                            curr = curr->children_[i + 1];
                            break;
                        }
                    }
                }
                int index = 0;
                while (key > curr->key_[index] && index < curr->size_) {
                    index++;
                }
                // Сдвигаем элементы вправо, чтобы освободить место под новый.
                for (int j = curr->size_; j > index; --j) {
                    curr->key_[j] = curr->key_[j - 1];
                }
                // Вставляем значение.
                curr->key_[index] = key;
                curr->size_++;
                curr->children_[curr->size_] = curr->children_[curr->size_ - 1];
                curr->children_[curr->size_ - 1] = nullptr;
            }
        }
    }

    void printLeaves() {
        if (root_) {
            printLeaves(root_);
        }
    }
};
