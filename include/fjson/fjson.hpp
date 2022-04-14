#ifndef FJSON_HPP
#define FJSON_HPP

#include "JsonValue.hpp"

namespace fjson
{

  class ParseException : public std::exception
  {
  };

  JsonValue parse_json(std::istringstream &text);
  JsonValue parse_json(const char *text);
  JsonValue parse_json(std::string text);
  JsonValue new_json_array();
  JsonValue new_json_object();

} // namespace fjson

#endif