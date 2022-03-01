#include <iostream>
#include <vector>
#include <algorithm>

bool checkTeams(const std::vector<int>& height_diff_variations, int num_of_teams,
                int people_in_team, int diff) {
    int busy = 0, can_create = 0;
    for (int i = 0; i < height_diff_variations.size(); ++i) {
        busy--;
        if (busy < 1 && height_diff_variations.at(i) <= diff) {
            can_create++;
            busy = people_in_team;
        }
    }
    return can_create >= num_of_teams;
}

int main() {
    int num_of_people, num_of_teams, people_in_team, element;
    std::cin >> num_of_people >> num_of_teams >> people_in_team;
    std::vector<int> people, height_diff_variations;
    for (int i = 0; i < num_of_people; ++i) {
        std::cin >> element;
        people.emplace_back(element);
    }
    std::sort(people.begin(), people.end());
    for (int i = 0; i < num_of_people - people_in_team + 1; ++i) {
        height_diff_variations.emplace_back(people.at(i + people_in_team - 1) - people.at(i));
    }
    int size, left = -1, right = people.at(people.size() - 1) - people.at(0);
    while (right - left > 1) {
        size = (left + right) / 2;
        if (checkTeams(height_diff_variations, num_of_teams, people_in_team, size)) {
            right = size;
        } else {
            left = size;
        }
    }
    if (num_of_teams == 1) {
        std::sort(height_diff_variations.begin(), height_diff_variations.end());
        std::cout << height_diff_variations.at(0);
        return 0;
    }
    std::cout << right;
    return 0;
}
