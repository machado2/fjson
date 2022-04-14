#include "JsonNull.hpp"
#include <sstream>
#include <string>

using namespace std;

namespace fjson {

static JsonValue jsonNullInstance = new JsonNull();

JsonValue &JsonNull::getInstance() { return jsonNullInstance; }

void JsonNull::serialize(std::ostringstream &stream) { stream << "null"; }

} // namespace fjson