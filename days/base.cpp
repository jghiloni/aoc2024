#include <iostream>
#include <string>
#include "base.hpp"

using namespace std;

string readStream(istream& in) {
  return string(istreambuf_iterator<char>(in), {});
}
