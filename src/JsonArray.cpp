#include "JsonArray.hpp"
#include "JsonNull.hpp"
#include <sstream>

using namespace std;

namespace fjson {

JsonValue &JsonArray::operator[](std::string &) {
  return JsonNull::getInstance();
}

void JsonArray::serialize(ostringstream &stream) {
  stream << '[';
  vector<JsonValue>::iterator it = data.begin();
  if (it != data.end()) {
    it->serialize(stream);
    it++;
  }
  for (; it != data.end(); it++) {
    stream << ',';
    it->serialize(stream);
  }
  stream << ']';
}

JsonValue &JsonArray::operator[](size_t index) { return data.at(index); }

size_t JsonArray::size() { return data.size(); }

void JsonArray::push_back(JsonValue value) {
  data.push_back(value);
}

} // namespace fjson