#include "JsonObject.hpp"
#include "JsonNull.hpp"
#include <sstream>

using namespace std;

namespace fjson {

void JsonObject::serialize(ostringstream &stream) {
  stream << '{';
  map<string, JsonValue>::iterator it = data.begin();
  if (it != data.end()) {
    stream << "\"" << it->first << "\":";
    it->second.serialize(stream);
    it++;
  }
  for (; it != data.end(); it++) {
    stream << ",\"" << it->first << "\":";
    it->second.serialize(stream);
  }
  stream << '}';
}

JsonValue &JsonObject::operator[](size_t) { return JsonNull::getInstance(); }

JsonValue &JsonObject::operator[](std::string &name) { return data[name]; }

size_t JsonObject::size() { return data.size(); }

bool JsonObject::hasValue(string name) { return data.find(name) != data.end(); }

} // namespace fjson