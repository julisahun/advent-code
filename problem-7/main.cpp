#include <iostream>
#include <string>
#include <vector>

const char SPLITTER = '^';
const char SOURCE = 'S';

void init_slots(std::vector<bool>& slots, const std::string& line) {
  int i = 0;
  for (int i = 0; i < line.size(); i++) {
    slots[i] = line[i] == SOURCE;
  }
}

int update_slots(std::vector<bool>& slots, const std::string& line) {
  int i = 0;
  int splits = 0;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == SPLITTER && slots[i]) {
      splits++;
      if (i - 1 >= 0) {
        slots[i - 1] = true;
      }
      if (i + 1 < line.size()) {
        slots[i + 1] = true;
      }
      slots[i] = false;
    }
  }
  return splits;
}

int main() {
  std::string s;
  std::cin >> s;
  int n = s.length();

  std::vector <bool> slots(n, false);
  init_slots(slots, s);

  int splits = 0;
  while (std::cin >> s) {
    splits += update_slots(slots, s);
  }

  std::cout << splits << std::endl;
}

