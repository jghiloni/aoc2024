#ifndef AOC_2024_BASE_H_
#define AOC_2024_BASE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AdventOfCodeDay {
public:
  virtual long part1(istream& in) = 0;
  virtual long part2(istream& in) = 0;
};

typedef struct dotMatrix {
  vector<string> matrix;
  size_t y;
  size_t x;
} dotMatrix;

string readStream(istream& in);
vector<string> getLines(istream& in);
void getDotMatrix(istream& in, dotMatrix* out);
void printDotMatrix(dotMatrix out);

#endif
