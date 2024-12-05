#ifndef AOC2024_DAY4_H
#define AOC2024_DAY4_H

#include "base.hpp"
#include <iostream>

using namespace std;

const string XMAS("XMAS");

class Day4 : public AdventOfCodeDay {
public:
  long part1(istream& in);
  long part2(istream& in);
private:
  uint findForward(vector<string> lines);
  uint findBackward(vector<string> lines);
  uint findUp(vector<string> lines);
  uint findDown(vector<string> lines);
  uint findUpLeft(vector<string> lines);
  uint findUpRight(vector<string> lines);
  uint findDownLeft(vector<string> lines);
  uint findDownRight(vector<string> lines);
  uint findXMASForward(vector<string> lines);
  uint findXMASBackward(vector<string> lines);
  uint findXMASDown(vector<string> lines);
  uint findXMASUp(vector<string> lines);
};

#endif
