#ifndef JSONVALUEDATA_HPP
#define JSONVALUEDATA_HPP

#include "fjson/JsonValue.hpp"

namespace fjson {

class JsonValueData {
public:
  virtual std::string toString();
  virtual JsonValue &operator[](size_t index);
  virtual JsonValue &operator[](std::string &name);
  virtual void serialize(std::ostringstream &stream) = 0;
  virtual size_t size();
  virtual double toDouble() { return 0; };
  virtual long toLong() { return (long)toDouble(); }
  virtual int toInt() { return (int)toDouble(); }
  virtual bool toBool() { return toInt() != 0; }
  virtual void push_back(JsonValue value) {}
  virtual bool hasValue(std::string name) { return false; }
  virtual bool isNull() { return false; }
  virtual bool isNumber() { return false; }
  virtual bool isString() { return false; }
  virtual bool isArray() { return false; }
  virtual bool isObject() { return false; }
  virtual bool isBool() { return false; }
  bool isTrue() { return isBool() && toBool(); }
  bool isFalse() { return isBool() && !toBool(); }
};

}

#endif