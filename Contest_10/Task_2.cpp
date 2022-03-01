#include <iostream>

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

    void makeSet(int element) {
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

int main() {
    int islands_num, roads_num;
    std::cin >> islands_num >> roads_num;
    auto *sets = new UnionFind(islands_num);
    for (int i = 0; i < islands_num; ++i) {
        sets->makeSet(i);
    }
    int island_a, island_b;
    for (int i = 0; i < roads_num; ++i) {
        std::cin >> island_a >> island_b;
        sets->unionSets(island_a, island_b);
        if (sets->size[sets->findSet(island_b)] == islands_num) {
            std::cout << i + 1;
            delete sets;
            return 0;
        }
    }
    std::cout << roads_num;
    delete sets;
    return 0;
}
