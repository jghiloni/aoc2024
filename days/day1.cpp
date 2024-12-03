#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "base.hpp"
#include "day1.hpp"

long Day1::part1(std::istream& in) {
  std::vector<int> left = std::vector<int>();
  std::vector<int> right = std::vector<int>();

  int l, r;
  while (in >> l >> r) {
    left.push_back(l);
    right.push_back(r);
  }

  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());

  long total = 0;
  for (int i = 0; i < left.size(); ++i) {
    int x = left.at(i);
    int y = right.at(i);

    total += abs(x - y);
  }

  return total;
}

long Day1::part2(std::istream& in) {
  std::map<int, int> cache = std::map<int, int>();

  std::vector<int> left = std::vector<int>();
  std::vector<int> right = std::vector<int>();

  int l, r;
  while (in >> l >> r) {
    left.push_back(l);
    right.push_back(r);
  }

  long total = 0;
  for (std::vector<int>::iterator iter = left.begin(); iter != left.end(); iter++) {
    int l = *iter;

    if (cache.count(l) == 1) {
      total += cache.at(l);
      continue;
    }

    int lcount = 0;
    for (std::vector<int>::iterator riter = right.begin(); riter != right.end(); riter++) {
      int r = *riter;
      if (l == r) {
        lcount++;
      }
    }

    total += l * lcount;
    cache[l] = l * lcount;
  }

  return total;
}
