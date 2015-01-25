#ifndef Jsonifier_h
#define Jsonifier_h
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <map>

typedef struct JsonEntry JsonEntry;

class Jsonifier {
  private:
    std::map<std::string, JsonEntry> vals;
    void print_entry(JsonEntry *e);
  public:
    Jsonifier();
    ~Jsonifier();
    void add_string(std::string k, std::string v);
    void add_array(std::string k, JsonEntry *v, int len);
    void add_float(std::string k, double v);
    // TODO: add methods for other types
	void print();
};

typedef enum JsonEntryType {
	JSON_OBJECT,
	JSON_STRING,
	JSON_INTEGER,
	JSON_FLOAT,
	JSON_ARRAY
} JsonEntryType;

typedef struct JsonEntry JsonEntry;

typedef struct JsonArray {
	int len;
	JsonEntry *t;
} JsonArray;

typedef struct JsonEntry {
	JsonEntryType t;
	union {
		Jsonifier   *o;
		const char  *s;
		long        i;
		double      f;
		JsonArray   a;
	} d;
} JsonEntry;

#endif
