#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>

void read_line(std::string first_number, std::vector<int>& numbers, std::istringstream& iss) {
  std::string word;

  numbers.push_back(std::stoi(first_number));
  while (iss >> word) {
    numbers.push_back(std::stoi(word));
  }
}

long long compute_operation(const std::string& operation, int i, const std::vector<std::vector<int>>& numbers) {
  long long total = operation == "*" ? 1 : 0;
  for (auto number_set : numbers) {
    if (operation == "*") {
      total *= number_set[i];
    } else if (operation == "+") {
      total += number_set[i];
    }
  }
  return total;
}

long long compute_total(const std::string& first_operation, const std::vector<std::vector<int>>& numbers, std::istringstream& iss) {
  int i = 0;
  long long total = compute_operation(first_operation, i++, numbers);
  std::string operation;
  while (iss >> operation) {
    total += compute_operation(operation, i++, numbers);
  }
  return total;
}

int main() {
  std::vector<std::vector<int>> numbers;
  std::string line;
  std::string word;
  int i = 0;
  while (true) {
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> word;
    if (word == "*" || word == "+") {
      std::cout << compute_total(word, numbers, iss) << std::endl;
      return 0;
    } else {
      numbers.push_back(std::vector<int>());
      read_line(word, numbers[i], iss);
      i++;
    }
  }
}
