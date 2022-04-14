#include "fjson/fjson.hpp"
#include "JsonValueData.hpp"
#include <map>
#include <sstream>

#include "JsonArray.hpp"
#include "JsonBool.hpp"
#include "JsonNull.hpp"
#include "JsonNumber.hpp"
#include "JsonObject.hpp"
#include "JsonString.hpp"

using namespace std;

namespace fjson {

static void skip_whitespace(istringstream &text) {
  int c;
  while ((c = text.peek()) == ' ' || c == '\t' || c == '\n' || c == '\r') {
    text.get();
  }
}

static string read_string(istringstream &text) {
  int c = text.get();
  stringstream value;
  if (c != '"') {
    throw ParseException();
  }
  for (c = text.get(); c != '"' && c != EOF; c = text.get()) {
    value << (char)c;
  }
  if (c == EOF) {
    throw ParseException();
  }
  return value.str();
}

static JsonValue parse_string(istringstream &text) {
  string s = read_string(text);
  return JsonValue(new JsonString(s));
}

static JsonValue parse_array(istringstream &text) {
  char c = text.get();
  if (c != '[') {
    throw ParseException();
  }
  skip_whitespace(text);
  vector<JsonValue> data;
  do {
    JsonValue v = parse_json(text);
    data.push_back(v);
    skip_whitespace(text);
    c = text.get();
    if (c != ']' && c != ',') {
      throw ParseException();
    }
  } while (c != ']');
  return JsonValue(new JsonArray(data));
}

JsonValue parse_number(istringstream &text) {
  double n;
  text >> n;
  return JsonValue(new JsonNumber(n));
}

bool read_string(istringstream &text, const char *s) {
  for (const char *p = s; *p != 0; p++) {
    if (text.get() != *p) {
      return false;
    }
  }
  return true;
}

JsonValue parse_object(istringstream &text) {
  map<string, JsonValue> data;
  if (text.get() != '{') {
    throw ParseException();
  }
  skip_whitespace(text);
  int c;
  for (c = ','; c == ','; c = text.get()) {
    skip_whitespace(text);
    string key = read_string(text);
    skip_whitespace(text);
    if (text.get() != ':')
      throw ParseException();
    skip_whitespace(text);
    JsonValue value = parse_json(text);
    data[key] = value;
    skip_whitespace(text);
  }
  if (c != '}') {
    throw ParseException();
  }
  return JsonValue(new JsonObject(data));
}

JsonValue parse_json(istringstream &text) {
  skip_whitespace(text);
  int c = text.peek();
  if (c == '"') {
    return parse_string(text);
  } else if (c == '{') {
    return parse_object(text);
  } else if (c == '[') {
    return parse_array(text);
  } else if (c == '-' || (c >= '0' && c <= '9')) {
    return parse_number(text);
  } else if (c == 'n' && read_string(text, "null")) {
    return JsonNull::getInstance();
  } else if (c == 't' && read_string(text, "true")) {
    return JsonValue(new JsonBool(true));
  } else if (c == 'f' && read_string(text, "false")) {
    return JsonValue(new JsonBool(false));
  } else {
    throw ParseException();
  }
}

JsonValue parse_json(std::string text) {
  istringstream iss(text);
  return parse_json(iss);
}

JsonValue parse_json(const char *text) {
  string s(text);
  return parse_json(s);
}

JsonValue new_json_array() {
 return JsonValue(new JsonArray()); 
}

JsonValue new_json_object() {
  return JsonValue(new JsonObject());
}

} // namespace fjson