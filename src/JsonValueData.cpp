#include "JsonValueData.hpp"
#include "JsonNull.hpp"
#include <sstream>

using namespace std;

namespace fjson {

JsonValue &JsonValueData::operator[](size_t) { return JsonNull::getInstance(); }
JsonValue &JsonValueData::operator[](std::string &) {
  return JsonNull::getInstance();
}
size_t JsonValueData::size() { return 0; }

string JsonValueData::toString() {
  ostringstream ss;
  serialize(ss);
  return ss.str();
}

} // namespace fjson
