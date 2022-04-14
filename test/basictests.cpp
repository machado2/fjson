#include "fjson/fjson.hpp"
#include <cassert>

using namespace fjson;
using namespace std;

void test_string()
{
	const char *s = "  \t \r\n  \t    \"potato\"  \t  ";
	JsonValue json = parse_json(s);
	assert(json.toString() == "potato");
}

void test_array()
{
	const char *s = "  [\"yellow\",  \"green\",\"red\"\t ,\t\r\n\"blue\"  ] ";
	JsonValue json = parse_json(s);

	assert(json.size() == 4);
	assert(json[0].toString() == "yellow");
	assert(json[1].toString() == "green");
	assert(json[2].toString() == "red");
	assert(json[3].toString() == "blue");
	assert(json.toString() == "[\"yellow\",\"green\",\"red\",\"blue\"]");

	json[2] = "blue";
	assert(json[2].toString() == "blue");
	json[1] = 4;
	assert(json[1].toInt() == 4);
	json[3] = true;
	assert(json[3].toBool() == true);
	json[3] = JsonValue(false);
	assert(json[3].toBool() == false);
}

void test_number()
{
	const char *s = "  \t \r\n  \t    1234  \t  ";
	JsonValue json = parse_json(s);
	assert(json.toString() == "1234");
	assert(json.toInt() == 1234);
	assert(json.toLong() == 1234);
	assert(json.toDouble() == 1234);
	json = parse_json("-1.10E4");
	assert(json.toDouble() == -1.10E4);
}

void test_object()
{
	const char *s = "  { \"xyz\" : 123 }  ";
	JsonValue json = parse_json(s);

	assert(json["xyz"].toInt() == 123);
}

void test_same(std::string s)
{
	cout << s << "\n" << parse_json(s).toString();
	assert(parse_json(s).toString() == s);
}

void test_create_object() {
	JsonValue json = new_json_object();
	json["property"] = 4;
	assert(json["property"].toInt() == 4);
	assert(json.toString() == "{\"property\":4}");
	assert(json.hasValue("potato") == false);
	assert(json.hasValue("property") == true);
}

void test_create_array() {
	JsonValue json = new_json_array();
	json.push_back(1);
	json.push_back(2);
	assert(json.size() == 2);
	assert(json[0].toInt() == 1);
	assert(json[1].toInt() == 2);
}

int main()
{
	test_object();
	test_array();
	test_string();
	test_number();
	test_same("true");
	test_same("false");
	test_same("null");
	test_create_object();
	test_create_array();
	return 0;
}