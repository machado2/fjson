#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <iostream>

#include <string>
#include <vector>
#include <memory>

#if (defined(__BORLANDC__) && __BORLANDC__ < 0x600)
#include <boost/shared_ptr.hpp>
#endif

namespace fjson
{

  class JsonValueData;

#if (defined(__BORLANDC__) && __BORLANDC__ < 0x600)
  typedef boost::shared_ptr<JsonValueData> SharedPtrJsonValue;
#else
  typedef std::shared_ptr<JsonValueData> SharedPtrJsonValue;
#endif

  class JsonValue
  {
  protected:
    SharedPtrJsonValue ptr;

  public:
    JsonValue();
    JsonValue(JsonValueData *p);
    JsonValue(bool b);
    JsonValue(double d);
    JsonValue(std::string &s);
    JsonValue(const char *s);
    JsonValue(int i);
    std::string toString();
    double toDouble();
    int toInt();
    long toLong();
    bool toBool();
    JsonValue &operator[](int index);
    JsonValue &operator[](size_t index);
    JsonValue &operator[](std::string &name);
    JsonValue &operator[](const char *name);
    void serialize(std::ostringstream &stream);
    JsonValue &operator=(std::string &value);
    JsonValue &operator=(const char *value);
    JsonValue &operator=(double value);
    JsonValue &operator=(int value);
    JsonValue &operator=(bool &value);
    size_t size();
    void push_back(JsonValue value);
    bool hasValue(std::string name);
    bool isNull();
    bool isNumber();
    bool isString();
    bool isArray();
    bool isObject();
    bool isBool();
    bool isTrue();
    bool isFalse();
  };

} // namespace fjson

#endif