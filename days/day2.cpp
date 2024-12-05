#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "base.hpp"
#include "day2.hpp"
#include <cstring>

long Day2::part1(std::istream& in) {
  long total = 0;
  for (std::string line; std::getline(in, line); ) {
    std::vector<int> vals = getValues(line);
    if (unsafeIndex(vals) == -1) {
      ++total;
    }
  }

  return total;
}

long Day2::part2(std::istream& in) {
  long total = 0;
  for (std::string line; std::getline(in, line); ) {
    std::vector<int> vals = getValues(line);

    if (unsafeIndex(vals) == -1) {
      std::cout << "Line " << line << " is safe" << std::endl;
      ++total;
      continue;
    }

    int oldTotal = total;
    for (int i = 0; i < vals.size(); ++i) {
      int erased = vals.at(i);
      vals.erase(vals.begin() + i);

      if (unsafeIndex(vals) == -1) {
        std::cout << "Line " << line << " is safe after removing " << erased << " at position " << i << std::endl;
        ++total;
        break;
      }

      vals.insert(vals.begin() + i, erased);
    }

    if (oldTotal == total) {
      std::cout << "Line " << line << " is always unsafe" << std::endl;
    }
  }

  return total;
}

std::vector<int> getValues(std::string line) {
  const char* cline = line.c_str();
  const char* delimiter = " ";

  std::vector<int> values = std::vector<int>();
  char* token = strtok((char*)cline, delimiter);
  while (token != NULL) {
    values.push_back(atol(token));
    token = std::strtok(NULL, delimiter);
  }

  return values;
}

int unsafeIndex(std::vector<int> values) {
  int direction = 0;
  for (int i = 1; i < values.size(); ++i) {
    int first = values.at(i - 1);
    int next = values.at(i);

    switch (direction) {
    case -1:
      if (next > first) {
        return i;
      }

      break;
    case 1:
      if (first > next) {
        return i;
      }
      break;
    default:
      direction = next > first ? 1 : -1;
    }

    int delta = abs(first - next);
    if (delta < 1 || delta > 3) {
      return i;
    }
  }

  return -1;
}

void printValues(std::vector<int> vals) {

  for (int i = 0; i < vals.size(); ++i) {
    std::cout << vals.at(i) << " ";
  }

  std::cout << std::endl;
}
