#include <iostream>
#include <cstdlib>
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

void getDotMatrix(istream& in, dotMatrix* out) {
  vector<string> lines = getLines(in);

  for (int i = 1; i < lines.size(); i++) {
    if (lines[i].length() != lines[i - 1].length()) {
      throw runtime_error(string("rows must have same number of columns"));
    }
  }

  size_t rows = lines.size();
  size_t cols = lines[0].length();

  dotMatrix dm = {
    .matrix = lines,
    .x = cols,
    .y = rows,
  };

  *out = dm;
}

void printDotMatrix(dotMatrix m) {
  cout << "SCREEN" << endl;
  for (int y = 0; y < m.y; y++) {
    cout << m.matrix[y] << endl;
  }
  cout << endl;
}
