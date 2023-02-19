
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// BP node
class Node {
public:
    bool leaf_;
    int *key_, size_, power_;
    int children_size_;
    Node **children_;
    explicit Node(int t) {
        this->power_ = t;
        key_ = new int[t * 2 - 1];
        children_ = new Node *[2 * t];
        children_size_ = 0;
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
        if (curr->leaf_) {
            for (int i = 0; i < curr->size_; ++i) {
                std::cout << curr->key_[i] << " ";
            }
            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < curr->children_size_; ++i) {
            printLeaves(curr->children_[i]);
        }
    }

    // Insert Operation
    // cursor - текущий нод, child - новый нод, x - индекс(меньший элемент ребенка).
    void insertNotLeaf(int x, Node *cursor, Node *child) {
        // Если текущий не полон.
        if (cursor->size_ < 2 * power_ - 1) {
            int i = 0;
            // Находим место, на которое поставим индекс.
            while (x > cursor->key_[i] && i < cursor->size_) {
                i++;
            }
            // Сдвигаем остальне ключи.
            for (int j = cursor->size_; j > i; j--) {
                cursor->key_[j] = cursor->key_[j - 1];
            }
            // Сдвигаем детей.
            for (int j = cursor->size_ + 1; j > i + 1; j--) {
                cursor->children_[j] = cursor->children_[j - 1];
            }
            // Добавляем новый индекс и соответствующего ребенка по индексу.
            cursor->key_[i] = x;
            cursor->size_++;
            cursor->children_size_++;
            cursor->children_[i + 1] = child;
        } else {
            // Если текущий полон(надо сплитануть).
            // Создаем новый нод.
            Node *newInternal = new Node(power_);
            // Создаем массив ключей, в который добавим новый индекс и сплитанем его.
            int virtualKey[2 * power_];
            // Создаем массив детей, в который добавим новый нод и сплитанем его.
            Node *virtualPtr[2 * power_ + 1];
            // Переносим в массив значения заполненного родителя.
            for (int i = 0; i < 2 * power_ - 1; i++) {
                virtualKey[i] = cursor->key_[i];
            }
            // Переносим в массив детей заполненного родителя.
            for (int i = 0; i < 2 * power_; i++) {
                virtualPtr[i] = cursor->children_[i];
            }
            int i = 0, j;
            // Находим место для ключа.
            while (x > virtualKey[i] && i < 2 * power_ - 1) {
                i++;
            }
            // Двигаем ключи, чтобы вставить элемент.
            for (int j = 2 * power_ - 1; j > i; j--) {
                virtualKey[j] = virtualKey[j - 1];
            }
            // Вставляем элемент.
            virtualKey[i] = x;
            // Двигаем детей, чтобы вставить новго.
            for (int j = 2 * power_; j > i + 1; j--) {
                virtualPtr[j] = virtualPtr[j - 1];
            }
            // Вставляем нового ребенка.
            virtualPtr[i + 1] = child;
            // Новый нод содержит индексы.
            newInternal->leaf_ = false;
            // Размер текущего уменьшаем вдвое.
            cursor->size_ = power_;
            cursor->children_size_ = power_ + 1;
            // Новый нод содержит вторую половину.
            newInternal->size_ = power_ - 1;
            // Переносим ключи в новый нод. TODO: Понять какую роль играет новый нод(становится новым родителем или правым ребенком текущего?)
            for (i = 0, j = cursor->size_ + 1; i < newInternal->size_; i++, j++) {
                newInternal->key_[i] = virtualKey[j];
            }
            // Переносим детей в новый нод.
            for (i = 0, j = cursor->size_ + 1; i < newInternal->size_ + 1; i++, j++) {
                newInternal->children_[i] = virtualPtr[j];
                newInternal->children_size_++;
            }
            // Остановка рекурсии TODO: Разрбрать.
            if (cursor == root_) {
                //cursor->children_size_ = 0;
                Node *newRoot = new Node(power_);
                newRoot->key_[0] = cursor->key_[cursor->size_];
                newRoot->children_[0] = cursor;
                newRoot->children_[1] = newInternal;
                newRoot->children_size_ = 2;
                newRoot->leaf_ = false;
                newRoot->size_ = 1;
                root_ = newRoot;
            } else {
                // Вставляем новый нод(в котором элементы правые в родителя текущего)
                insertInternal(cursor->key_[cursor->size_], findParent(root_, cursor), newInternal);
            }
        }
    }
    Node *findParent(Node *cursor, Node *child) {
        Node *parent;
        // Если текущий лист или уровнем выше листа, то возвращаем ничего.
        if (cursor->leaf_ || (cursor->children_[0])->leaf_) {
            return nullptr;
        }
        // Проходим по всем потомкам и ищем родителя.
        for (int i = 0; i < cursor->size_ + 1; i++) {
            if (cursor->children_[i] == child) {
                parent = cursor;
                return parent;
            } else {
                parent = findParent(cursor->children_[i], child);
                if (parent != nullptr)
                    return parent;
            }
        }
        return parent;
    }

public:
    explicit BPlusTree(int t) {
        root_ = nullptr;
        this->power_ = t;
    }

    void clear(Node *root) {
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

    ~BPlusTree() {
        clear(root_);
    }

    void search(int x) {
        if (root_ == nullptr) {
            cout << "Tree is empty\n";
        } else {
            Node *cursor = root_;
            while (!cursor->leaf_) {
                for (int i = 0; i < cursor->size_; i++) {
                    if (x < cursor->key_[i]) {
                        cursor = cursor->children_[i];
                        break;
                    }
                    if (i == cursor->size_ - 1) {
                        cursor = cursor->children_[i + 1];
                        break;
                    }
                }
            }
            for (int i = 0; i < cursor->size_; i++) {
                if (cursor->key_[i] == x) {
                    cout << "Found\n";
                    return;
                }
            }
            cout << "Not found\n";
        }
    }

    void insert(int x) {
        if (root_ == nullptr) {
            root_ = new Node(power_);
            root_->key_[0] = x;
            root_->leaf_ = true;
            root_->size_ = 1;
            root_->children_size_ = 1;
        } else {
            Node *cursor = root_;
            Node *parent;
            // Ищем лист, в который добавим новое значение
            while (!cursor->leaf_) {
                parent = cursor;
                for (int i = 0; i < cursor->size_; i++) {
                    if (x < cursor->key_[i]) {
                        cursor = cursor->children_[i];
                        break;
                    }
                    if (i == cursor->size_ - 1) {
                        cursor = cursor->children_[i + 1];
                        break;
                    }
                }
            }
            // Если лист не полный.
            if (cursor->size_ < 2 * power_ - 1) {
                int i = 0;
                while (x > cursor->key_[i] && i < cursor->size_)
                    i++;
                // Сдвигаем элементы вправо, чтобы освободить место под новый.
                for (int j = cursor->size_; j > i; j--) {
                    cursor->key_[j] = cursor->key_[j - 1];
                }
                // Вставляем значение.
                cursor->key_[i] = x;
                cursor->size_++;
                // TODO: WTF? нахуя это вообще?? - У листов children_ указывает на след элемент связного списка(на след лист)?
                cursor->children_[cursor->size_] = cursor->children_[cursor->size_ - 1];
                cursor->children_[cursor->size_ - 1] = nullptr;
            } else {
                // Если лист полный.
                Node *newLeaf = new Node(power_);
                // Создаем массив, в который переносим все значения полного листа.
                int virtualNode[2 * power_];
                for (int i = 0; i < 2 * power_ - 1; i++) {
                    virtualNode[i] = cursor->key_[i];
                }
                int i = 0, j;
                // Заносим в этот массив новый элемент на его место(отсортированно)
                while (x > virtualNode[i] && i < 2 * power_ - 1) {
                    i++;
                }
                for (int j = 2 * power_ - 1; j > i; j--) {
                    virtualNode[j] = virtualNode[j - 1];
                }
                virtualNode[i] = x;
                // Создаем новый лист
                newLeaf->leaf_ = true;
                // У текущего размер урезаем.
                cursor->size_ = power_;
                // У нового делаем размер, равный остатку TODO: rewrite comment
                newLeaf->size_ = power_;
                // У тукущего делаем ссылку на след нод.
                cursor->children_[cursor->size_] = newLeaf;
                // У след делаем ссылку на последний нод, на который ссылался текущий.
                newLeaf->children_[newLeaf->size_] = cursor->children_[2 * power_ - 1];
                // Зануляем ссылку на последний у текущего.
                cursor->children_[2 * power_ - 1] = nullptr;
                // Заносим значения в текущий нод.
                for (i = 0; i < cursor->size_; i++) {
                    cursor->key_[i] = virtualNode[i];
                }
                // Занисим значения в новый нод.
                for (i = 0, j = cursor->size_; i < newLeaf->size_; i++, j++) {
                    newLeaf->key_[i] = virtualNode[j];
                }
                // Если добаляли в корень.
                if (cursor == root_) {
                    cursor->children_size_ = 0;
                    // Создаем новый рут, в котором будут индексы.
                    Node *newRoot = new Node(power_);
                    // Первый индекс - минимальный элемент из нового нода(в котором большие значения).
                    newRoot->key_[0] = newLeaf->key_[0];
                    // Выставляем детей и остальлные параметры.
                    newRoot->children_[0] = cursor;
                    newRoot->children_[1] = newLeaf;
                    newRoot->children_size_ = 2;
                    newRoot->leaf_ = false;
                    newRoot->size_ = 1;
                    root_ = newRoot;
                } else {
                    // Иначе вызываем пока неразобранный метод. parent - полный лист, newLeaf - правый лист после сплита, x - индекс(меньший элемент правого нода).
                    insertInternal(newLeaf->key_[0], parent, newLeaf);
                }
            }
        }
    }
    void display(Node *cursor) {
        if (cursor != nullptr) {
            for (int i = 0; i < cursor->size_; i++) {
                cout << cursor->key_[i] << " ";
            }
            cout << "\n";
            if (!cursor->leaf_) {
                for (int i = 0; i < cursor->size_ + 1; i++) {
                    display(cursor->children_[i]);
                }
            }
        }
    }

    void myPrint(Node *curr) {
        for (int i = 0; i < curr->size_; ++i) {
            std::cout << curr->key_[i] << " ";
        }
        std::cout << std::endl;
        if (curr->leaf_) {
            return;
        }
        for (int i = 0; i < curr->children_size_; ++i) {
            myPrint(curr->children_[i]);
        }
    }

//    void printLeaves() {
//        Node *curr = root_;
//        while (!curr->leaf_) {
//            curr = curr->children_[0];
//        }
//        while (curr != nullptr) {
//            for (int i = 0; i < curr->size_; ++i) {
//                std::cout << curr->key_[i] << " ";
//            }
//            std::cout << "\n";
//            curr = curr->children_[3];
//        }
//    }



    void printLeaves() {
        if (root_) {
            printLeaves(root_);
        }
    }

    Node *getRoot() {
        return root_;
    }
};

int main() {
    auto *tree = new BPlusTree(2);
    int data;
    std::cin >> data;
    while (data != -1) {
        tree->insert(data);
        std::cin >> data;
    }
    tree->printLeaves();
    delete tree;
}