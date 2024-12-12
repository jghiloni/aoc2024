#include <iostream>
#include "base.hpp"
#include "day6.hpp"
#include <map>

using namespace std;


const map<char, coordinate> adjustments = {
  {'^', coordinate(0,-1)},
  {'v', coordinate(0,1)},
  {'<', coordinate(-1, 0)},
  {'>', coordinate(1, 0)}
};

const map<char, char> rotated = {
  {'^', '>'},
  {'>', 'v'},
  {'v', '<'},
  {'<', '^'}
};

coordinate potentialObstacle(coordinate corner1, coordinate corner2, coordinate corner3, char guard) {
  int c4x, c4y;

  if (corner1.first == corner2.first) {
    c4x = corner3.first;
  } else if (corner1.first == corner3.first) {
    c4x = corner2.first;
  } else if (corner2.first == corner3.first) {
    c4x = corner1.first;
  }

  if (corner1.second == corner2.second) {
    c4y = corner3.second;
  } else if (corner1.second == corner3.second) {
    c4y = corner2.second;
  } else if (corner2.second == corner3.second) {
    c4y = corner1.second;
  }

  coordinate adjustment = adjustments.at(guard);

  return coordinate(c4x + adjustment.first, c4y + adjustment.second);
}

long Day6::part1(istream& in) {
  dotMatrix screen;
  getDotMatrix(in, &screen);
  long total = 0L;

  printDotMatrix(screen);

  pair<coordinate, char> guard = this->findGuard(screen);
  coordinate position = guard.first;
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
  dotMatrix screen;
  getDotMatrix(in, &screen);
  long total = 0L;

  printDotMatrix(screen);

  pair<coordinate, char> guard = this->findGuard(screen);
  coordinate corner1, corner2, corner3, newObstacle;

  rotationPoint next = this->nextRotationPoint(screen, guard.first, guard.second);
  corner1 = next.location;

  next = this->nextRotationPoint(screen, corner1, next.newAlignment);
  corner2 = next.location;

  next = this->nextRotationPoint(screen, corner2, next.newAlignment);
  corner3 = next.location;

  newObstacle = potentialObstacle(corner1, corner2, corner3, next.newAlignment);

  while (this->isOnScreen(screen, newObstacle)) {
    screen.matrix[newObstacle.second][newObstacle.first] = 'O';
    total++;

    corner1 = corner2;
    corner2 = corner3;

    next = this->nextRotationPoint(screen, corner2, next.newAlignment);
    corner3 = next.location;

    if (corner3 == NOT_FOUND) {
      break;
    }

    newObstacle = potentialObstacle(corner1, corner2, corner3, next.newAlignment);
  }

  printDotMatrix(screen);

  return total;
}

pair<coordinate, char> Day6::findGuard(const dotMatrix& screen) {
  for (int y = 0; y < screen.y; y++) {
    for (int x = 0; x < screen.x; x++) {
      if (screen.matrix[y][x] == '^' || screen.matrix[y][x] == 'v' || screen.matrix[y][x] == '<' || screen.matrix[y][x] == '>') {
        return pair(coordinate(x, y), screen.matrix[y][x]);
      }
    }
  }

  return pair(NOT_FOUND, '.');
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

bool Day6::isOnScreen(const dotMatrix& screen, coordinate position) {
  return (position.first >= 0 && position.first < screen.x) &&
    (position.second >= 0 && position.second < screen.y);
}

rotationPoint Day6::nextRotationPoint(const dotMatrix& screen, coordinate currentPosition, char guard) {
  coordinate adjustment = adjustments.at(guard);

  coordinate position = currentPosition;
  while (position != NOT_FOUND) {
    coordinate previous = position;
    position = coordinate(position.first + adjustment.first, position.second + adjustment.second);
    if (screen.matrix[position.second][position.first] == '#') {
      return rotationPoint{
        .location = previous,
        .oldAlignment = guard,
        .newAlignment = rotated.at(guard),
      };
    }

    if (!this->isOnScreen(screen, position)) {
      break;
    }
  }

  return rotationPoint{
    .location = NOT_FOUND,
    .oldAlignment = guard,
    .newAlignment = 'X',
  };
}
