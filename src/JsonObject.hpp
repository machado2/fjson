#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP

#include "JsonValueData.hpp"
#include <map>

namespace fjson {

class JsonObject : public JsonValueData {
private:
  std::map<std::string, JsonValue> data;

public:
  JsonObject(std::map<std::string, JsonValue> &data) : data(data) {}
  JsonObject() {}
  virtual JsonValue &operator[](size_t index);
  virtual JsonValue &operator[](std::string &name);
  virtual void serialize(std::ostringstream &stream);
  virtual size_t size();
  virtual bool hasValue(std::string name);
};

} // namespace fjson

#endif