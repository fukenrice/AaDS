#include <iostream>
#include <cstdint>


class BTree {
private:
    struct TreeNode {
        int *keys_;
        int power_;
        TreeNode **children_;
        int size_;
        bool leaf_;
        int children_size_;
        ~TreeNode() {
            delete[] keys_;
            delete[] children_;
        }

        TreeNode(int node_power, bool is_leaf) {
            power_ = node_power;
            leaf_ = is_leaf;
            keys_ = new int[2 * power_ - 1];
            children_ = new TreeNode *[2 * power_];
            size_ = 0;
            children_size_ = 0;
            for (int i = 0; i < power_ * 2; ++i) {
                children_[i] = nullptr;
            }
        }

        TreeNode *search(int key) {
            int index = 0;
            // Находим индекс подходящего элемента или доходим до конца.
            while (index < size_ && key > keys_[index]) {
                index++;
            }
            // Если дошли до конца, проверяем последний элемент.
            if (index == 2 * power_ - 1) {
                if (keys_[index - 1] == key) {
                    return this;
                }
            } else {
                if (keys_[index] == key) {
                    return this;
                }
            }
            // Если потомков нет, то элемента не существует.
            if (leaf_) {
                return nullptr;
            }
            // Ищем элемент в соответствующем потомке.
            return children_[index]->search(key);
        }

        // Метод для разделения полного нода.
        void splitChild(int index, TreeNode *node_to_split) {
            // Создаем нод, в котором будут содержаться элементы большие, чем i-й ключ.
            auto *right = new TreeNode(node_to_split->power_, node_to_split->leaf_);
            right->size_ = power_ - 1;
            right->children_size_ = power_;
            // Переносим элементы из второй половины в наш нод.
            for (int j = 0; j < power_ - 1; ++j) {
                right->keys_[j] = node_to_split->keys_[j + power_];
            }
            if (!node_to_split->leaf_) {
                for (int j = 0; j < power_; ++j) {
                    right->children_[j] = node_to_split->children_[j + power_];
                }
            }
            // Оставляем только первую половину.
            node_to_split->size_ = power_ - 1;
            node_to_split->children_size_ = power_;
            for (int j = size_; j >= index + 1; --j) {
                children_[j + 1] = children_[j];
            }
            // Добавляем потомков, котоыре больше i-го ключа, ставим на их место.
            children_[index + 1] = right;
            for (int j = size_ - 1; j >= index; --j) {
                keys_[j + 1] = keys_[j];
            }
            // Ставим на i-е место середину прежнего потомка.
            keys_[index] = node_to_split->keys_[power_ - 1];
            size_ = size_ + 1;
            children_size_++;
        }

        // Метод для вставки ключа в неполный нод.
        void insertNonFull(int key) {
            // Инлекс последнего элемента.
            int index = size_ - 1;
            if (leaf_) {
                // Ищем подходящее место для вставки ключа.
                while (index >= 0 && keys_[index] > key) {
                    keys_[index + 1] = keys_[index];
                    index--;
                }
                keys_[index + 1] = key;
                size_ = size_ + 1;
            } else {
                // Ищем подходящего ребенка для вставки ключа.
                while (index >= 0 && keys_[index] > key) {
                    index--;
                }
                // Если ребенок полон, тогда сплитим его.
                if (children_[index + 1]->size_ == 2 * power_ - 1) {
                    splitChild(index + 1, children_[index + 1]);
                    if (keys_[index + 1] < key) {
                        index++;
                    }
                }
                // Вставляем ключ в неполного ребенка.
                children_[index + 1]->insertNonFull(key);
            }
        }
    };

    TreeNode *root_;

public:
    static int power_;

    explicit BTree(int power) {
        root_ = nullptr;
        power_ = power;
    }

    void clear(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        if (!root->leaf_) {
            for (int i = 0; i < root->children_size_; ++i) {
                clear(root->children_[i]);
            }
        }
        delete root;
    }

    ~BTree() {
        clear(root_);
    }

    int64_t getSum(TreeNode *root) const {
        int64_t res = 0;
        // Если дерево пустое.
        if (root == nullptr) {
            return 0;
        }
        // Если потомков нет, суммируем ключи.
        if (root->leaf_) {
            for (int i = 0; i < root->size_; ++i) {
                res += root->keys_[i];
            }
            return res;
        }
        for (int i = 0; i < root->children_size_; ++i) {
            res += getSum(root->children_[i]);
        }
        return res;
    }

    size_t getSize(TreeNode *root) const {
        size_t res = 1;
        if (root->leaf_) {
            return 1;
        }
        for (int i = 0; i < root->children_size_; ++i) {
            res += getSize(root->children_[i]);
        }
        return res;
    }

    size_t size() const {
        if (root_) {
            return getSize(root_);
        }
        return 0;
    }

    int64_t sum() const {
        return getSum(root_);
    }

    // Метод для вставки.
    void insert(int key) {
        if (root_ == nullptr) {
            root_ = new TreeNode(power_, true);
            root_->keys_[0] = key;
            root_->size_ = 1;
        } else {
            // Проверяем, есть ли элемент в дереве.
            if (root_->search(key) != nullptr) {
                return;
            }
            // Если корень дерева полон, поделим его и встамим элемент.
            if (root_->size_ == 2 * power_ - 1) {
                // Создаем новый корень, который будет содержать середину старого.
                auto *new_root = new TreeNode(power_, false);
                // Старый корень превратим в левового потомка.
                new_root->children_[0] = root_;
                new_root->children_size_ = 1;
                // Делим левого потомка на 2 нода, чтобы расположить их относительно середины.
                new_root->splitChild(0, root_);
                // Смотрим, в какого потомка нового корня добавить новый ключ.
                int index = 0;
                if (new_root->keys_[0] < key) {
                    index++;
                }
                // Добавляем ключ не неполного потомка.
                new_root->children_[index]->insertNonFull(key);
                // Меняем указатель на корень
                root_ = new_root;
            } else {
                root_->insertNonFull(key);
            }
        }
    }
};

int main() {
    auto *tree = new BTree(2);
    int num, data;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        std::cin >> data;
        tree->insert(data);
    }
    std::cout << tree->size() << " - size, " << tree->sum() << " - sum";
}


