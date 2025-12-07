#include <iostream>
#include <string>

const int INITIAL_POSITION = 50;
const int mod = 100;

int main() {
    int r = 0;
    int current_position = INITIAL_POSITION;
    std::string input;
    bool was_zero = false;
    while (std::cin >> input) {
        char direction = input[0];
        int number = std::stoi(input.substr(1));
        
        if (direction == 'R') {
            current_position += number;
        } else {
            current_position -= number;
        }

        r += abs(current_position / mod);
        r += current_position <= 0 && !was_zero;

        current_position = (current_position % mod + mod) % mod;
        was_zero = current_position == 0;
    }
    std::cout << r << std::endl;
}