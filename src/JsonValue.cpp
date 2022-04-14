#include "fjson/JsonValue.hpp"
#include "JsonBool.hpp"
#include "JsonNull.hpp"
#include "JsonNumber.hpp"
#include "JsonString.hpp"
#include "JsonArray.hpp"

using namespace std;

namespace fjson {

string JsonValue::toString() { return ptr->toString(); }

JsonValue &JsonValue::operator[](size_t index) { return (*ptr)[index]; }
JsonValue &JsonValue::operator[](std::string &name) { return (*ptr)[name]; }
JsonValue &JsonValue::operator[](int index) { return (*ptr)[(size_t)index]; }
JsonValue &JsonValue::operator[](const char *name) {
  string sName(name);
  return (*ptr)[sName];
}

JsonValue::JsonValue() : ptr(JsonNull::getInstance().ptr) {}
JsonValue::JsonValue(JsonValueData *p) : ptr(p) {}
void JsonValue::serialize(std::ostringstream &stream) {
  return ptr->serialize(stream);
}
size_t JsonValue::size() { return ptr->size(); }
double JsonValue::toDouble() { return ptr->toDouble(); }
int JsonValue::toInt() { return ptr->toInt(); }
long JsonValue::toLong() { return ptr->toLong(); }
bool JsonValue::toBool() { return ptr->toBool(); }

JsonValue &JsonValue::operator=(std::string &value) {
  ptr = SharedPtrJsonValue(new JsonString(value));
  return *this;
}

JsonValue &JsonValue::operator=(const char *value) {
  string sValue(value);
  return *this = sValue;
}

JsonValue &JsonValue::operator=(double value) {
  ptr = SharedPtrJsonValue(new JsonNumber(value));
  return *this;
}

JsonValue &JsonValue::operator=(int value) {
  ptr = SharedPtrJsonValue(new JsonNumber(value));
  return *this;
}

JsonValue &JsonValue::operator=(bool &value) {
  ptr = SharedPtrJsonValue(new JsonBool(value));
  return *this;
}

JsonValue::JsonValue(bool b) { ptr = SharedPtrJsonValue(new JsonBool(b)); }

JsonValue::JsonValue(const char *s) {
  ptr = SharedPtrJsonValue(new JsonString(s));
}

JsonValue::JsonValue(string &s) { ptr = SharedPtrJsonValue(new JsonString(s)); }

JsonValue::JsonValue(int value) : ptr(new JsonNumber(value)) {}

void JsonValue::push_back(JsonValue value) {
  ptr->push_back(value);
}

bool JsonValue::hasValue(string s) { return ptr->hasValue(s); }

} // namespace fjson