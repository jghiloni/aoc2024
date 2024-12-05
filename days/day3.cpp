#include <iostream>
#include <string>
#include <cstdio>
#include "base.hpp"
#include "day3.hpp"

using namespace std;

const char* token = "mul(";
const char* disable = "don't()";
const char* enable = "do()";

long Day3::part1(istream& in) {
  string input = readStream(in);

  size_t idx = input.find(token);
  long total = 0;
  while (idx != string::npos) {
    cout << "Found mul( at position " << idx << endl;
    string substr = input.substr(idx);

    uint x, y;
    char closer;
    int found = sscanf(substr.c_str(), "mul(%3u,%3u%c", &x, &y, &closer);
    if (found == 3 && closer == ')') {
      cout << "multiplying " << x << " and " << y << " and adding to total" << endl;
      total += (x * y);
    }

    idx = input.find(token, idx + 1);
  }

  return total;
}

long Day3::part2(istream& in) {
  string input = readStream(in);

  size_t idx = input.find(token);
  size_t disableIdx = input.find(disable);
  size_t enableIdx = input.find(enable, disableIdx + strlen(disable));
  long total = 0;
  cout << idx << " " << disableIdx << " " << enableIdx << endl;
  while (idx != string::npos) {
    if (idx > disableIdx && idx < enableIdx) {
      cout << "Found mul( but it is currently disabled" << endl;
      size_t newStart = enableIdx + strlen(enable);
      idx = input.find(token, newStart);
      disableIdx = input.find(disable, newStart);
      if (disableIdx != string::npos) {
        enableIdx = input.find(enable, disableIdx + strlen(disable));
      }
      continue;
    }

    cout << "Found mul( at position " << idx << endl;
    string substr = input.substr(idx);

    uint x, y;
    char closer;
    int found = sscanf(substr.c_str(), "mul(%3u,%3u%c", &x, &y, &closer);
    if (found == 3 && closer == ')') {
      cout << "multiplying " << x << " and " << y << " and adding to total" << endl;
      total += (x * y);
    }

    idx = input.find(token, idx + 1);
  }

  return total;
}
