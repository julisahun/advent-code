#include <iostream>
#include <string>

const char ROLL = '@';
const int MAX_COLLISIONS = 4;

int count_rolls(std::string prev, std::string curr, std::string post) {
  int n = curr.size();
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (curr[i] != ROLL) continue;
    int collisions = 0;
    if (i-1 >= 0) {
      collisions += curr[i-1] == ROLL;
      collisions += prev[i-1] == ROLL;
      collisions += post[i-1] == ROLL;
    }
    if (i+1 < n) {
      collisions += curr[i+1] == ROLL;
      collisions += prev[i+1] == ROLL;
      collisions += post[i+1] == ROLL;
    }
    collisions += prev[i] == ROLL;
    collisions += post[i] == ROLL;
    total += collisions < MAX_COLLISIONS;
  }
  return total;
}

int count_rolls(std::string row, std::string adjacent) {
  int n = row.size();
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (row[i] != ROLL) continue;
    int collisions = 0;
    if (i-1 >= 0) {
      collisions += row[i-1] == ROLL;
      collisions += adjacent[i-1] == ROLL;
    }
    if (i+1 < n) {
      collisions += row[i+1] == ROLL;
      collisions += adjacent[i+1] == ROLL;
    }
    collisions += adjacent[i] == ROLL;
    total += collisions < MAX_COLLISIONS;
  }
  return total;
}

int main() {
  int j = 0;
  std::string prev;
  std::string curr;
  std::string post;
  
  std::cin >> prev;
  std::cin >> curr;
  int sum = count_rolls(prev, curr);
  std::cin >> post;
  do {
    sum += count_rolls(prev, curr, post);
    prev = curr;
    curr = post;
  }
  while(std::cin >> post);

  sum += count_rolls(curr, prev);

  std::cout << sum << std::endl;
}