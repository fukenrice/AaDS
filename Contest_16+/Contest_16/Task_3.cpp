#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template <class ValueType>
class Heap {
public:
    Heap() = default;

    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        for (Iterator i = begin; i != end; ++i) {
            heap_.template emplace_back(*i);
        }
        for (int i = size() / 2; i >= 0; --i) {
            heapify(&heap_, i, size());
        }
    }

    Heap(std::initializer_list<ValueType> source) {
        heap_ = source;
        for (int i = size() / 2; i >= 0; --i) {
            heapify(&heap_, i, size());
        }
    }

    // Копирование
    Heap(const Heap &other) {
        heap_.clear();
        for (int i = 0; i < other.size(); ++i) {
            this->heap_.template emplace_back(other.heap_.at(i));
        }
    }
    Heap &operator=(const Heap &other) {
        heap_.clear();
        for (int i = 0; i < other.size(); ++i) {
            this->heap_.template emplace_back(other.heap_.at(i));
        }
        return *this;
    }

    // Пермещение
    Heap(Heap &&other) {
        this->heap_ = other.heap_;
        if (&other == this) {
            return;
        }
        other.heap_.clear();
    }
    Heap &operator=(Heap &&other) {
        this->heap_ = other.heap_;
        if (&other == this) {
            return *this;
        }
        other.heap_.clear();
        return *this;
    }

    ~Heap() = default;

    size_t size() const {
        return heap_.size();
    }

    bool empty() const {
        return heap_.empty();
    }

    void insert(const ValueType &value) {
        heap_.template emplace_back(value);
        int index = size() - 1;
        int parent = (index - 1) / 2;
        while (index > 0 && heap_.at(parent) < heap_.at(index)) {
            std::swap(heap_.at(parent), heap_.at(index));
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    ValueType extract() {
        ValueType res = heap_.at(0);
        heap_.at(0) = heap_.at(size() - 1);
        heap_.pop_back();
        heapify(&heap_, 0, size());
        return res;
    }

private:
    std::vector<ValueType> heap_;

    void heapify(std::vector<ValueType> *heap_arg, int index, int size) {
        int left, right, largest = -1;
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;
        if (left < size && heap_arg->at(largest) < heap_arg->at(left)) {
            largest = left;
        }
        if (right < size && heap_arg->at(largest) < heap_arg->at(right)) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap_arg->at(index), heap_arg->at(largest));
            heapify(heap_arg, largest, size);
        }
    }
};
