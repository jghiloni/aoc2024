#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "base.hpp"
#include "day5.hpp"

using namespace std;

map<int, vector<int>> buildRules(vector<string> lines) {
  map<int, vector<int>> rules = map<int, vector<int>>();
  for (string line : lines) {
    if (line.find("|") == string::npos) {
      return rules;
    }

    int before, after;
    sscanf(line.c_str(), "%d|%d", &before, &after);

    auto locator = rules.find(after);
    if (locator == rules.end()) {
      vector<int> befores = { before };
      rules.insert_or_assign(after, befores);
    } else {
      rules.at(after).push_back(before);
    }
  }

  return rules;
}

vector<int> getPrintJob(string line) {
  vector<int> printJob;
  string split;
  istringstream lineStream(line);
  while (getline(lineStream, split, ',')) {
    printJob.push_back(atoi(split.c_str()));
  }

  return printJob;
}

void swap(vector<int>& printJob, int x, int y) {
  int tmp = printJob[x];
  printJob[x] = printJob[y];
  printJob[y] = tmp;
}

string join(const vector<int>& v, char delim) {
  ostringstream out = ostringstream();
  for (int i = 0; i < v.size() - 1; i++) {
    out << v[i] << delim;
  }

  out << v[v.size() - 1];

  return out.str();
}

int centerpoint(const vector<int>& printJob, const map<int, vector<int>>& rules) {
  for (int i = 0; i < printJob.size(); i++) {
    int page = printJob.at(i);
    auto locator = rules.find(page);
    if (locator == rules.end() && i < printJob.size() - 1) {
      continue;
    }

    vector<int> prohibitedBefores = locator->second;
    vector<int> afters = vector<int>(printJob.begin() + i + 1, printJob.end());

    for (int after : afters) {
      for (int prohibitedBefore : prohibitedBefores) {
        if (after == prohibitedBefore) {
          return -1;
        }
      }
    }
  }

  return printJob[printJob.size() / 2];
}

int correctedCenterpoint(vector<int>& printJob, const map<int, vector<int>>& rules) {
  int center = centerpoint(printJob, rules);
  if (center != -1) {
    return center;
  }

  for (int i = 0; i < printJob.size(); i++) {
    int page = printJob[i];
    auto locator = rules.find(page);
    if (locator == rules.end() && i < printJob.size() - 1) {
      continue;
    }

    vector<int> prohibitedBefores = locator->second;

    for (int j = i + 1; j < printJob.size(); j++) {
      for (int prohibitedBefore : prohibitedBefores) {
        if (printJob[j] == prohibitedBefore) {
          swap(printJob, i, j);
          int center = correctedCenterpoint(printJob, rules);
          if (center != -1) {
            return center;
          }
        }
      }
    }
  }

  return printJob[printJob.size() / 2];
}

long Day5::part1(istream& in) {
  vector<string> lines = getLines(in);
  map<int, vector<int>> rules = buildRules(lines);

  long total = 0;
  for (string line : lines) {
    bool isPrintJob = line.find(",") != string::npos;
    if (isPrintJob) {
      int center = centerpoint(getPrintJob(line), rules);
      if (center != -1) {
        cout << "Print job " << line << " is ordered and its center page is " << center << endl;
        total += center;
      }
    }
  }

  return total;
}

long Day5::part2(istream& in) {
  vector<string> lines = getLines(in);
  map<int, vector<int>> rules = buildRules(lines);

  long total = 0;
  for (string line : lines) {
    bool isPrintJob = line.find(",") != string::npos;
    if (isPrintJob) {
      vector<int> printJob = getPrintJob(line);
      int center = centerpoint(printJob, rules);
      if (center == -1) {
        center = correctedCenterpoint(printJob, rules);
        cout << "Line " << line << " has been corrected to " << join(printJob, ',')
          << " and its centerpoint is " << center << endl;
        total += center;
      }
    }
  }
  return total;
}

