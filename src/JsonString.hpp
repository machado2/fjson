#ifndef JSONSTRING_HPP
#define JSONSTRING_HPP

#include "JsonValueData.hpp"

namespace fjson {

class JsonString : public JsonValueData {
private:
  std::string value;

public:
  virtual std::string toString();
  JsonString(const char *value);
  JsonString(std::string &value);
  virtual void serialize(std::ostringstream &stream);
  virtual bool isString() { return true; }
};

} // namespace fjson

#endif