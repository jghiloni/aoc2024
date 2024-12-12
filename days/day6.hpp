#ifndef AOC2024_DAY6_H
#define AOC2024_DAY6_H

#include "base.hpp"
#include <iostream>

using namespace std;

typedef pair<size_t, size_t> coordinate;
const coordinate NOT_FOUND = coordinate(-1, -1);

class Day6 : public AdventOfCodeDay {
public:
  long part1(istream& in);
  long part2(istream& in);
private:
  coordinate nextPosition(dotMatrix& matrix, coordinate position);
  coordinate findGuard(dotMatrix matrix);
  bool isOnScreen(dotMatrix screen, pair<size_t, size_t> position);
};

#endif
