#include <iostream>
#include <string>
#include "base.hpp"

using namespace std;

string readStream(istream& in) {
  return string(istreambuf_iterator<char>(in), {});
}

vector<string> getLines(istream& in) {
  vector<string> v = vector<string>();
  for (string line; getline(in, line);) {
    v.push_back(line);
  }

  return v;
}
