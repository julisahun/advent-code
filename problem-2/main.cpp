#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

bool is_valid(int number) {
  std::string num_str = std::to_string(number);
  if (num_str.length() % 2 == 1) return true;
  int middle = num_str.length() / 2;
  std::string first_half = num_str.substr(0, middle);
  std::string second_half = num_str.substr(middle);
  return first_half != second_half;
}

int main() {
  long long sum = 0;
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss(line);
  std::string range;
  while (std::getline(ss, range, ',')) {
    size_t dash_pos = range.find('-');
    if (dash_pos != std::string::npos) {
      std::string start_str = range.substr(0, dash_pos);
      std::string end_str = range.substr(dash_pos + 1);
      long long start = std::stoll(start_str);
      long long end = std::stoll(end_str);
      for (long long i = start; i <= end; ++i) {
        if (!is_valid(i)) {
          std::cout << "Invalid number: " << std::to_string(i) << std::endl;
          sum += i;
        }
      }
    }
  }
  std::cout << sum << std::endl;
  return 0;
}