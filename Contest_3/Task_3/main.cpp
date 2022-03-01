#include <iostream>
#include <string>

std::string GetName(const std::string &phrase, std::string names) {
    int words_in_phrase = 1;
    for (int i = 0; i < phrase.length(); ++i) {
        if (phrase.at(i) == ' ') {
            words_in_phrase++;
        }
    }

    int names_number = 1;
    for (int i = 0; i < names.length(); ++i) {
        if (names.at(i) == ' ') {
            names_number++;
        }
    }

    int name_index;

    for (int i = 0; i < words_in_phrase; ++i) {
        name_index = i % names_number;
    }

    int names_cnt = 0; // Индекс текущего имени в цикле.
    int name_length = 0; // Длина выбранного имени.
    int first_letter_index; // Индекс первой буквы имени в строке всех имен.

    for (int i = 0; i < names.length(); ++i) {
        if (names_cnt == name_index) {
            first_letter_index = i;
            break;
        }
        if (names.at(i) == ' ') {
            names_cnt++;
        }
    }

    for (int i = first_letter_index; i < names.length(); ++i) {
        if (names.at(i) == ' ') {
            break;
        }
        name_length++;
    }
    return names.substr(first_letter_index, name_length);
}

int main() {
    std::string phrase, names;
    getline(std::cin, phrase);
    getline(std::cin, names);
    std::cout << (GetName(phrase, names));
    return 0;
}
