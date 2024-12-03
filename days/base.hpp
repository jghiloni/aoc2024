#ifndef AOC_2024_BASE_H_
#define AOC_2024_BASE_H_

#include <iostream>

class AdventOfCodeDay {
public:
  virtual long part1(std::istream& in) = 0;
  virtual long part2(std::istream& in) = 0;
};

#endif
