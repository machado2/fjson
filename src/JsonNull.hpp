#ifndef JSONNULL_HPP
#define JSONNULL_HPP

#include "JsonValueData.hpp"

namespace fjson {

class JsonNull : public JsonValueData {
public:
  static JsonValue &getInstance();
  virtual void serialize(std::ostringstream &stream);
  virtual bool isNull() { return true; }
};

} // namespace fjson

#endif