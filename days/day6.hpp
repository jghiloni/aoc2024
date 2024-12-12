#ifndef AOC2024_DAY6_H
#define AOC2024_DAY6_H

#include "base.hpp"
#include <iostream>

using namespace std;

typedef pair<int, int> coordinate;
const coordinate NOT_FOUND = coordinate(-1, -1);

typedef struct rotationPoint {
  coordinate location;
  char oldAlignment;
  char newAlignment;
} rotationPoint;

class Day6 : public AdventOfCodeDay {
public:
  long part1(istream& in);
  long part2(istream& in);
private:
  coordinate nextPosition(dotMatrix& matrix, coordinate position);
  rotationPoint nextRotationPoint(const dotMatrix& matrix, coordinate currentPosition, char currentGuardAlignment);
  pair<coordinate, char> findGuard(const dotMatrix& matrix);
  bool isOnScreen(const dotMatrix& screen, coordinate position);
};

#endif
