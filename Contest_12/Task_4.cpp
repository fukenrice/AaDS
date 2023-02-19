#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    int num;
    std::vector<std::string> children;
    std::string child, parent;
    std::map<std::string, int> levels;
    // ключ - ребенок, значение - родитель.
    std::map<std::string, std::string> ties;
    std::cin >> num;
    for (int i = 0; i < num - 1; ++i) {
        std::cin >> child >> parent;
        children.emplace_back(child);
        ties.insert(std::make_pair(child, parent));
        levels.insert(std::make_pair(child, 0));
    }

    for (auto it = ties.begin(); it != ties.end(); ++it) {
        if (std::find(children.begin(), children.end(), it->second) == children.end()) {
            levels.insert(std::make_pair(it->second, 0));
            break;
        }
    }

    for (auto it = ties.begin(); it != ties.end(); ++it) {
        auto child_name = it->first;
        while (std::find(children.begin(), children.end(), child_name) != children.end()) {
            levels.at(it->first)++;
            child_name = ties.at(child_name);
        }
    }

    for (auto it = levels.begin(); it != levels.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}
