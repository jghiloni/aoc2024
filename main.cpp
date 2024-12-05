#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "days/base.hpp"
#include "days/day1.hpp"
#include "days/day2.hpp"

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <day> <part> [file]" << std::endl;
    exit(1);
  }

  std::string day = std::string(argv[1]);
  std::string part = std::string(argv[2]);

  std::istream* in = &std::cin;
  std::ifstream fstream;
  if (argc == 4) {
    fstream = std::ifstream(argv[3]);
    in = &fstream;
  }

  std::map<std::string, AdventOfCodeDay*> daymap = std::map<std::string, AdventOfCodeDay*>();

  daymap[std::string("day1")] = new Day1();
  daymap[std::string("day2")] = new Day2();

  AdventOfCodeDay* exercise = daymap[day];

  if (exercise != NULL) {
    long output = part == std::string("part1") ? (*exercise).part1(*in) : (*exercise).part2(*in);
    std::cout << output << std::endl;
    return 0;
  }

  return 1;
}
