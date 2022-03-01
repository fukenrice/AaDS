#include <iostream>

struct Edge {
    int l_element, r_element, weight;
    Edge(int l_element, int r_element, int weight) {
        this->l_element = l_element;
        this->r_element = r_element;
        this->weight = weight;
    }
};

void quickSort(Edge **arr, int start_index, int end_index) {
    int start = start_index;
    int end = end_index;
    int middle_weight = arr[(start + end) / 2]->weight;

    do {
        while (arr[start]->weight < middle_weight) {
            start++;
        }

        while (arr[end]->weight > middle_weight) {
            end--;
        }
        //Меняем элементы местами
        if (start <= end) {
            Edge *tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;

            start++;
            end--;
        }
    } while (start <= end);
    if (end > start_index) {
        quickSort(arr, start_index, end);
    }
    if (start < end_index) {
        quickSort(arr, start, end_index);
    }
}

class MyStack {
private:
    int size_;
    Edge *top_;
    Edge **arr_;
    int capacity_;

public:
    MyStack() {
        size_ = 0;
        top_ = nullptr;
        capacity_ = 2000;
        arr_ = new Edge *[2000];
        for (int i = 0; i < capacity_; ++i) {
            arr_[i] = nullptr;
        }
    }

    ~MyStack() {
        delete[] arr_;
    }

    void push(Edge *element) {
        arr_[size_++] = element;
        top_ = element;
    }

    Edge *pop() {
        if (size_ == 0) {
            return nullptr;
        } else {
            Edge *old = top_;
            size_--;
            if (size_ != 0) {
                top_ = arr_[size_ - 1];
            } else {
                top_ = nullptr;
            }
            return old;
        }
    }

    int size() const {
        return size_;
    }
};

struct UnionFind {
    int *parent;
    int *size;
    explicit UnionFind(int max_size) {
        parent = new int[max_size];
        size = new int[max_size];
    }

    ~UnionFind() {
        delete[] parent;
        delete[] size;
    }

    void makeSet(int element) const {
        parent[element] = element;
        size[element] = 1;
    }

    int findSet(int element) {
        if (parent[element] == element) {
            return element;
        }
        // Переназначаем родителя(сжатие путей), чтобы поиск не занимал много времени.
        return parent[element] = findSet(parent[element]);
    }

    void unionSets(int l_element, int r_element) {
        l_element = findSet(l_element);
        r_element = findSet(r_element);
        if (l_element == r_element) {
            return;
        }
        if (size[l_element] < size[r_element]) {
            parent[l_element] = r_element;
            size[r_element] += size[l_element];
        } else if (size[r_element] < size[l_element]) {
            parent[r_element] = l_element;
            size[l_element] += size[r_element];
        } else {
            parent[r_element] = l_element;
            size[l_element]++;
        }
    }
};

int findSecondMin(Edge **edges, int num_of_edges, int num_of_nodes, MyStack *ostov_edges) {
    int min_weight = INT32_MAX;
    while (ostov_edges->size() != 0) {
        Edge *ost_edge = ostov_edges->pop();
        auto *sets = new UnionFind(num_of_nodes + 1);
        for (int j = 1; j < num_of_nodes + 1; ++j) {
            sets->makeSet(j);
        }
        int res_size = 1;
        int weight = 0;
        for (int index = 0; index < num_of_edges; ++index) {
            if (edges[index] == ost_edge) {
                continue;
            }
            if (sets->findSet(edges[index]->l_element) != sets->findSet(edges[index]->r_element)) {
                weight += edges[index]->weight;
                sets->unionSets(edges[index]->l_element, edges[index]->r_element);
                res_size++;
            }
            if (res_size == num_of_nodes) {
                break;
            }
        }
        delete sets;
        if (weight < min_weight && res_size == num_of_nodes) {
            min_weight = weight;
        }
    }
    return min_weight;
}

int main() {
    int num_of_nodes, num_of_edges;
    std::cin >> num_of_nodes >> num_of_edges;
    int node_a, node_b, edge_weight;
    Edge **edges = new Edge *[num_of_edges];
    for (int i = 0; i < num_of_edges; ++i) {
        std::cin >> node_a >> node_b >> edge_weight;
        edges[i] = (new Edge(node_a, node_b, edge_weight));
    }
    quickSort(edges, 0, num_of_edges - 1);
    auto *ostov_edges = new MyStack();
    auto *sets = new UnionFind(num_of_nodes + 1);
    for (int i = 1; i < num_of_nodes + 1; ++i) {
        sets->makeSet(i);
    }
    int res_size = 1;
    int weight = 0;
    for (int i = 0; i < num_of_edges; ++i) {
        if (sets->findSet(edges[i]->l_element) != sets->findSet(edges[i]->r_element)) {
            weight += edges[i]->weight;
            sets->unionSets(edges[i]->l_element, edges[i]->r_element);
            res_size++;
            ostov_edges->push(edges[i]);
        }
        if (res_size == num_of_nodes) {
            break;
        }
    }

    std::cout << weight << " ";
    std::cout << findSecondMin(edges, num_of_edges, num_of_nodes, ostov_edges);
    for (int i = 0; i < num_of_edges; ++i) {
        delete edges[i];
    }
    delete[] edges;
    delete sets;
    delete ostov_edges;
    return 0;
}
