#ifndef JSONBOOL_HPP
#define JSONBOOL_HPP

#include "JsonValueData.hpp"
#include <sstream>

namespace fjson {

class JsonBool : public JsonValueData {
private:
  bool value;

public:
  JsonBool(bool value) : value(value) {}
  virtual void serialize(std::ostringstream &stream) {
    stream << (value ? "true" : "false");
  }
  bool toBool() { return value; }
  virtual bool isBool() { return true; }
};

} // namespace fjson

#endif