#ifndef JSONARRAY_HPP
#define JSONARRAY_HPP

#include "JsonValueData.hpp"
#include <vector>

namespace fjson {

class JsonArray : public JsonValueData {
private:
  std::vector<JsonValue> data;

public:
  JsonArray(std::vector<JsonValue> &data) : data(data) {}
  JsonArray() {}
  virtual JsonValue &operator[](size_t index);
  virtual JsonValue &operator[](std::string &name);
  virtual void serialize(std::ostringstream &stream);
  virtual size_t size();
  void push_back(JsonValue value);
};

} // namespace fjson

#endif