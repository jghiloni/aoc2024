#ifndef AOC2024_DAY2_H
#define AOC2024_DAY2_H

#include "base.hpp"
#include <iostream>

class Day2 : public AdventOfCodeDay {
public:
  long part1(std::istream& in);
  long part2(std::istream& in);
};

std::vector<int> getValues(std::string line);
int unsafeIndex(std::vector<int> values);
void printValues(std::vector<int> values);

#endif
