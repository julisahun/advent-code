#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype> 

bool is_in_ranges(std::vector<std::string> ranges, long long number) {
    for (int i = 0; i < ranges.size(); i++) {

        size_t pos = ranges[i].find('-');

        long long lower_bound = std::stoll(ranges[i].substr(0, pos));
        if (number < lower_bound) continue;
        long long upper_bound = std::stoll((pos == std::string::npos) ? "" : ranges[i].substr(pos + 1));
        if (number <= upper_bound) return true;
    }
    return false;
}

long long count_range(std::string range) {

        size_t pos = range.find('-');

        long long lower_bound = std::stoll(range.substr(0, pos));
        long long upper_bound = std::stoll((pos == std::string::npos) ? "" : range.substr(pos + 1));
        std::cout << upper_bound << ' ' << lower_bound << ' ' << upper_bound - lower_bound << std::endl;
        return upper_bound - lower_bound + 1;
}

bool is_blank(const std::string& s) {
    return std::all_of(s.begin(), s.end(),
                       [](unsigned char c){ return std::isspace(c); });
}

int main() {
    std::vector<std::string> ranges;
    std::string range;
    long long count = 0;
    while (true) {
        std::getline(std::cin, range);
        if (is_blank(range)) break;
        count += count_range(range);
        // ranges.push_back(range);
    }
    // long long number;
    // while (std::cin >> number) {
    //     if (is_in_ranges(ranges, number)) count++;
    // }
    std::cout << count << std::endl;
}