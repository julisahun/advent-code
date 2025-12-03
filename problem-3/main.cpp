#include <iostream>
#include <string>
#include <utility>

std::pair<char, int> get_max_digit(const std::string &row) {
  char max = row[0];
  int max_i = 0;
  for (int i = 1; i < row.length(); i++) {
    if (row[i] > max) {
      max = row[i];
      max_i = i;
    }
  }
  return std::pair<char, int>(max, max_i);
}

int get_max(const std::string &bank) {
  std::pair<char, int> max = get_max_digit(bank);
  if (max.second == bank.length() - 1) {
    std::string truncated = bank.substr(0, bank.length() - 1);
    std::pair<char, int> secondMax = get_max_digit(truncated);
    auto s = std::string(1,secondMax.first)+max.first;
    return std::stoi(s);
  } else {
    std::string truncated = bank.substr(max.second + 1);
    std::pair<char, int> secondMax = get_max_digit(truncated);
    auto s = std::string(1,max.first)+secondMax.first;
    return std::stoi(s);
  }
}

int main() {
  int total = 0;
  std::string bank;
  while (std::cin >> bank) {
    int max = get_max(bank);
    std::cout << max << std::endl;
    total += max;
  }
  std::cout << total << std::endl;
}