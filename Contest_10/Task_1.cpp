#include <iostream>

// Элемент хеш-таблицы - список объектов с одним хешем
template <class KeyType, class ValueType>
struct Node {
    KeyType key_;
    ValueType value_;
    Node *next_;

    Node(KeyType key, ValueType value) {
        key_ = key;
        value_ = value;
        next_ = nullptr;
    }
};

// Хеш-таблица
template <class KeyType, class ValueType, class Func = std::hash<KeyType>>
class HashTable {
    double fill_factor_;
    size_t capacity_;
    size_t size_;
    Func hasher_;

    Node<KeyType, ValueType> **arr_;

public:
    HashTable() {
        fill_factor_ = 0.5;
        capacity_ = 100;
        size_ = 0;
        arr_ = new Node<KeyType, ValueType> *[capacity_];
        for (int i = 0; i < capacity_; ++i) {
            arr_[i] = nullptr;
        }
        hasher_ = Func();
    }
    explicit HashTable(Func hasher) {
        fill_factor_ = 0.5;
        capacity_ = 100;
        size_ = 0;
        arr_ = new Node<KeyType, ValueType> *[capacity_];
        for (int i = 0; i < capacity_; ++i) {
            arr_[i] = nullptr;
        }
        hasher_ = hasher;
    }
    HashTable(size_t cap, double fill_fact, Func hasher = std::hash<KeyType>()) {
        fill_factor_ = fill_fact > 0 && fill_fact <= 1 ? fill_fact : 0.5;
        capacity_ = cap;
        size_ = 0;
        hasher_ = hasher;
        arr_ = new Node<KeyType, ValueType> *[capacity_];
        for (int i = 0; i < capacity_; ++i) {
            arr_[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < capacity_; ++i) {
            clear(arr_[i]);
        }
        delete[] arr_;
    }

    void clear(Node<KeyType, ValueType> *nd) {
        if (nd == nullptr) {
            return;
        }
        clear(nd->next_);
        delete nd;
    }

    void insert(KeyType key, ValueType value) {
        int index = hasher_(key) % capacity_;
        if (arr_[index] == nullptr) {
            arr_[index] = new Node<KeyType, ValueType>(key, value);
            size_++;
        } else {
            Node<KeyType, ValueType> *curr = arr_[index];
            while (curr->next_) {
                if (curr->key_ == key) {
                    break;
                }
                curr = curr->next_;
            }
            if (curr->key_ == key) {
                curr->value_ = value;
            } else {
                curr->next_ = new Node<KeyType, ValueType>(key, value);
                size_++;
            }
        }
        if (size_ > fill_factor_ * capacity_) {
            rehash();
        }
    }

    void insert(Node<KeyType, ValueType> *node) {
        int index = hasher_(node->key_) % capacity_;
        if (arr_[index] == nullptr) {
            arr_[index] = node;
        } else {
            Node<KeyType, ValueType> *curr = arr_[index];
            while (curr->next_) {
                curr = curr->next_;
            }
            curr->next_ = node;
        }
    }

    void rehash() {
        auto old = arr_;
        capacity_ *= 2;
        arr_ = new Node<KeyType, ValueType> *[capacity_];
        for (int i = 0; i < capacity_; ++i) {
            arr_[i] = nullptr;
        }
        for (int i = 0; i < capacity_ / 2; ++i) {
            if (old[i] != nullptr) {
                Node<KeyType, ValueType> *curr = old[i];
                while (curr) {
                    insert(curr);
                    auto prev = curr;
                    curr = curr->next_;
                    prev->next_ = nullptr;
                }
            }
        }
        delete[] old;
    }

    ValueType *find(KeyType key) {
        int index = hasher_(key) % capacity_;
        if (arr_[index] == nullptr) {
            return nullptr;
        }
        Node<KeyType, ValueType> *curr = arr_[index];
        while (curr->next_) {
            if (curr->key_ == key) {
                break;
            }
            curr = curr->next_;
        }
        if (curr->key_ == key) {
            return &curr->value_;
        }
        return nullptr;
    }
    void erase(KeyType key) {
        int index = hasher_(key) % capacity_;
        // Если нет элемента по индексу.
        if (arr_[index] == nullptr) {
            return;
        }
        Node<KeyType, ValueType> *curr = arr_[index];
        // Если первый элемент нужно удалить.
        if (curr->key_ == key) {
            arr_[index] = curr->next_;
            size_--;
            delete curr;
            return;
        }
        while (curr->next_) {
            if (curr->next_->key_ == key) {
                break;
            }
            curr = curr->next_;
        }
        // Если дошли до конца и последний нужно удалить.
        if (curr->next_ == nullptr && curr->key_ == key) {
            delete curr;
            size_--;
            return;
        }
        // Если дошли до конца и так и не нашли элемент.
        if (curr->next_ == nullptr && curr->key_ != key) {
            return;
        }
        // Если не дошли до конца.
        if (curr->next_->key_ == key) {
            Node<KeyType, ValueType> del = *curr->next_;
            curr->next_ = curr->next_->next_;
            size_--;
            delete &del;
            return;
        }
    }

    Node<KeyType, ValueType> &operator[](uint64_t hash) {
        if (hash >= capacity_) {
            throw std::out_of_range("");
        }
        if (arr_[hash] == nullptr) {
            throw std::runtime_error("");
        }
        return *arr_[hash];
    }
    Node<KeyType, ValueType> at(uint64_t hash) {
        if (hash >= capacity_) {
            throw std::out_of_range("");
        }
        if (arr_[hash] == nullptr) {
            throw std::runtime_error("");
        }
        return *arr_[hash];
    }

    size_t size() const {
        return size_;
    }
    size_t capacity() const {
        return capacity_;
    }
};
