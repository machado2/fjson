#ifndef JSONNUMBER_HPP
#define JSONNUMBER_HPP

#include "JsonValueData.hpp"
#include <sstream>

namespace fjson {

class JsonNumber : public JsonValueData {
private:
  double value;

public:
  JsonNumber(double value) : value(value) {}
  virtual void serialize(std::ostringstream &stream) { stream << value; }
  virtual double toDouble() { return value; }
};

}

#endif