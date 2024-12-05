#include <iostream>
#include <string>
#include <vector>
#include "base.hpp"
#include "day4.hpp"

using namespace std;

long Day4::part1(istream& in) {
  vector<string> lines = getLines(in);
  return this->findForward(lines) +
    this->findBackward(lines) +
    this->findUp(lines) +
    this->findDown(lines) +
    this->findUpLeft(lines) +
    this->findUpRight(lines) +
    this->findDownLeft(lines) +
    this->findDownRight(lines);
}

long Day4::part2(istream& in) {
  vector<string> lines = getLines(in);
  return this->findXMASForward(lines) +
    this->findXMASBackward(lines) +
    this->findXMASUp(lines) +
    this->findXMASDown(lines);
}

uint Day4::findForward(vector<string> lines) {
  uint total = 0;
  for (int y = 0; y < lines.size(); y++) {
    string line = lines.at(y);
    for (int x = 0; x <= line.length() - XMAS.length(); x++) {
      if (line.at(x) == 'X' && line.at(x + 1) == 'M' && line.at(x + 2) == 'A' && line.at(x + 3) == 'S') {
        cout << "XMAS found going forward starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findBackward(vector<string> lines) {
  uint total = 0;
  for (int y = 0; y < lines.size(); y++) {
    string line = lines.at(y);
    for (int x = 3; x < line.length(); x++) {
      if (line.at(x) == 'X' && line.at(x - 1) == 'M' && line.at(x - 2) == 'A' && line.at(x - 3) == 'S') {
        cout << "XMAS found going backward starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findUp(vector<string> lines) {
  uint total = 0;

  for (int y = 3; y < lines.size(); y++) {
    for (int x = 0; x < lines.at(0).length(); x++) {
      if (lines.at(y).at(x) == 'X' && lines.at(y - 1).at(x) == 'M' && lines.at(y - 2).at(x) == 'A' && lines.at(y - 3).at(x) == 'S') {
        cout << "XMAS found going up starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findDown(vector<string> lines) {
  uint total = 0;

  for (int y = 0; y <= lines.size() - XMAS.length(); y++) {
    for (int x = 0; x < lines.at(0).length(); x++) {
      if (lines.at(y).at(x) == 'X' && lines.at(y + 1).at(x) == 'M' && lines.at(y + 2).at(x) == 'A' && lines.at(y + 3).at(x) == 'S') {
        cout << "XMAS found going down starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findUpLeft(vector<string> lines) {
  uint total = 0;

  for (int y = 3; y < lines.size(); y++) {
    for (int x = 3; x < lines.at(0).length(); x++) {
      if (lines.at(y).at(x) == 'X' && lines.at(y - 1).at(x - 1) == 'M' && lines.at(y - 2).at(x - 2) == 'A' && lines.at(y - 3).at(x - 3) == 'S') {
        cout << "XMAS found going up left starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findUpRight(vector<string> lines) {
  uint total = 0;

  for (int y = 3; y < lines.size(); y++) {
    for (int x = 0; x <= lines.at(0).length() - XMAS.length(); x++) {
      if (lines.at(y).at(x) == 'X' && lines.at(y - 1).at(x + 1) == 'M' && lines.at(y - 2).at(x + 2) == 'A' && lines.at(y - 3).at(x + 3) == 'S') {
        cout << "XMAS found going up right starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findDownLeft(vector<string> lines) {
  uint total = 0;

  for (int y = 0; y <= lines.size() - XMAS.length(); y++) {
    for (int x = 3; x < lines.at(0).length(); x++) {
      if (lines.at(y).at(x) == 'X' && lines.at(y + 1).at(x - 1) == 'M' && lines.at(y + 2).at(x - 2) == 'A' && lines.at(y + 3).at(x - 3) == 'S') {
        cout << "XMAS found going down left starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findDownRight(vector<string> lines) {
  uint total = 0;

  for (int y = 0; y <= lines.size() - XMAS.length(); y++) {
    for (int x = 0; x <= lines.at(0).length() - XMAS.length(); x++) {
      if (lines.at(y).at(x) == 'X' && lines.at(y + 1).at(x + 1) == 'M' && lines.at(y + 2).at(x + 2) == 'A' && lines.at(y + 3).at(x + 3) == 'S') {
        cout << "XMAS found going down right starting at (x,y) = (" << x << "," << y << ")" << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findXMASForward(vector<string> lines) {
  uint total = 0;
  for (int y = 0; y < lines.size() - 2; y++) {
    for (int x = 0; x < lines.at(0).length() - 2; x++) {
      if (lines.at(y).at(x) == 'M' && lines.at(y).at(x + 2) == 'S' &&
        lines.at(y + 1).at(x + 1) == 'A' &&
        lines.at(y + 2).at(x) == 'M' && lines.at(y + 2).at(x + 2) == 'S') {
        cout << "Found an X-MAS going forward starting at (x,y) (" << x << ',' << y << ')' << endl;
        ++total;
      }
    }
  }

  return total;
}

uint Day4::findXMASBackward(vector<string> lines) {
  uint total = 0;

  for (int y = 0; y < lines.size() - 2; y++) {
    for (int x = 0; x < lines.at(0).length() - 2; x++) {
      if (lines.at(y).at(x) == 'S' && lines.at(y).at(x + 2) == 'M' &&
        lines.at(y + 1).at(x + 1) == 'A' &&
        lines.at(y + 2).at(x) == 'S' && lines.at(y + 2).at(x + 2) == 'M') {
        cout << "Found an X-MAS going backward starting at (x,y) (" << x << ',' << y << ')' << endl;
        ++total;
      }
    }
  }

  return total;
}
uint Day4::findXMASDown(vector<string> lines) {
  uint total = 0;
  for (int y = 0; y < lines.size() - 2; y++) {
    for (int x = 0; x < lines.at(0).length() - 2; x++) {
      if (lines.at(y).at(x) == 'M' && lines.at(y).at(x + 2) == 'M' &&
        lines.at(y + 1).at(x + 1) == 'A' &&
        lines.at(y + 2).at(x) == 'S' && lines.at(y + 2).at(x + 2) == 'S') {
        cout << "Found an X-MAS going down starting at (x,y) (" << x << ',' << y << ')' << endl;
        ++total;
      }
    }
  }

  return total;
}
uint Day4::findXMASUp(vector<string> lines) {
  uint total = 0;
  for (int y = 0; y < lines.size() - 2; y++) {
    for (int x = 0; x < lines.at(0).length() - 2; x++) {
      if (lines.at(y).at(x) == 'S' && lines.at(y).at(x + 2) == 'S' &&
        lines.at(y + 1).at(x + 1) == 'A' &&
        lines.at(y + 2).at(x) == 'M' && lines.at(y + 2).at(x + 2) == 'M') {
        cout << "Found an X-MAS going up starting at (x,y) (" << x << ',' << y << ')' << endl;
        ++total;
      }
    }
  }

  return total;
}
