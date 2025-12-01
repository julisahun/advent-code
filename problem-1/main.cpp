#include <iostream>
#include <string>

int main() {
    int r = 0;
    const int INITIAL_POSITION = 50;
    int current_position = INITIAL_POSITION;
    std::string input;
    while (std::cin >> input) {
        char direction = input[0];
        int number = std::stoi(input.substr(1));
        if (direction == 'R') {
            current_position += number;
        } else {
            current_position -= number;
        }
        if (current_position % 100 == 0) r++;
    }
    std::cout << r << std::endl;
}