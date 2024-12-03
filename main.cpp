#include <iostream>
#include <map>
#include <string>
#include "days/base.hpp"
#include "days/day1.hpp"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <day> <part>" << std::endl;
    exit(1);
  }

  std::string day = std::string(argv[1]);
  std::string part = std::string(argv[2]);

  std::map<std::string, AdventOfCodeDay*> daymap = std::map<std::string, AdventOfCodeDay*>();

  daymap[std::string("day1")] = new Day1();

  AdventOfCodeDay* exercise = daymap[day];

  if (exercise != NULL) {
    long output = part == std::string("part1") ? (*exercise).part1(std::cin) : (*exercise).part2(std::cin);
    std::cout << output << std::endl;
    return 0;
  }

  return 1;
}
