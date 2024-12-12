#include <iostream>
#include "base.hpp"
#include "day6.hpp"

using namespace std;

long Day6::part1(istream& in) {
  dotMatrix screen;
  getDotMatrix(in, &screen);
  long total = 0L;

  printDotMatrix(screen);

  coordinate position = this->findGuard(screen);
  while (this->isOnScreen(screen, position)) {
    position = this->nextPosition(screen, position);
    printDotMatrix(screen);
  }

  for (int y = 0; y < screen.y; y++) {
    for (int x = 0; x < screen.x; x++) {
      if (screen.matrix[y][x] == 'X') {
        ++total;
      }
    }
  }

  return total;
}

long Day6::part2(istream& in) {
  return 0L;
}

coordinate Day6::findGuard(dotMatrix screen) {
  for (int y = 0; y < screen.y; y++) {
    for (int x = 0; x < screen.x; x++) {
      if (screen.matrix[y][x] == '^' || screen.matrix[y][x] == 'v' || screen.matrix[y][x] == '<' || screen.matrix[y][x] == '>') {
        return coordinate(x, y);
      }
    }
  }

  return NOT_FOUND;
}

coordinate Day6::nextPosition(dotMatrix& screen, coordinate current) {
  char guard = screen.matrix[current.second][current.first];
  coordinate next;
  char rotated;
  switch (guard) {
  case '^':
    next = coordinate(current.first, current.second - 1);
    rotated = '>';
    break;
  case 'v':
    next = coordinate(current.first, current.second + 1);
    rotated = '<';
    break;
  case '<':
    next = coordinate(current.first - 1, current.second);
    rotated = '^';
    break;
  case '>':
    next = coordinate(current.first + 1, current.second);
    rotated = 'v';
    break;
  default:
    char* out = (char*)malloc(23 * sizeof(char));
    snprintf(out, 23, "invalid guard token %c", guard);
    throw runtime_error(string(out));
  }

  if (screen.matrix[next.second][next.first] == '#') {
    screen.matrix[current.second][current.first] = rotated;
    return current;
  }

  screen.matrix[current.second][current.first] = 'X';
  screen.matrix[next.second][next.first] = guard;

  return next;
}

bool Day6::isOnScreen(dotMatrix screen, coordinate position) {
  return (position.first >= 0 && position.first < screen.x) &&
    (position.second >= 0 && position.second < screen.y);
}
