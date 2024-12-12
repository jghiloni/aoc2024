#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "days/base.hpp"
#include "days/day1.hpp"
#include "days/day2.hpp"
#include "days/day3.hpp"
#include "days/day4.hpp"
#include "days/day5.hpp"
#include "days/day6.hpp"

using namespace std;

int main(int argc, char** argv) {
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " <day> <part> [file]" << endl;
    exit(1);
  }

  string day = string(argv[1]);
  string part = string(argv[2]);

  istream* in = &cin;
  ifstream fstream;
  if (argc == 4) {
    fstream = ifstream(argv[3]);
    in = &fstream;
  }

  map<string, AdventOfCodeDay*> daymap = map<string, AdventOfCodeDay*>();

  daymap[string("day1")] = new Day1();
  daymap[string("day2")] = new Day2();
  daymap[string("day3")] = new Day3();
  daymap[string("day4")] = new Day4();
  daymap[string("day5")] = new Day5();
  daymap[string("day6")] = new Day6();

  AdventOfCodeDay* exercise = daymap[day];

  if (exercise != NULL) {
    long output = part == string("part1") ? (*exercise).part1(*in) : (*exercise).part2(*in);
    cout << output << endl;
    return 0;
  }

  cerr << "Exercise for " << day << ", " << part << " not found" << endl;
  return 1;
}
