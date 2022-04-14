#include "JsonString.hpp"
#include <sstream>

using namespace std;

namespace fjson {

string JsonString::toString() { return value; }

JsonString::JsonString(const char *value) : value(string(value)) {}

JsonString::JsonString(string &value) : value(string(value)) {}

void JsonString::serialize(ostringstream &stream) {
  stream << '\"' << value << '\"';
}

}