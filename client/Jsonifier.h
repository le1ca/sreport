#ifndef Jsonifier_h
#define Jsonifier_h
#include <string>
#include <map>

class Jsonifier {
  private:
    std::map<std::string,std::string> vals;
  public:
    Jsonifier();
    void add(std::string k, std::string v);
	void print();
};

typedef enum JsonEntryType {
	JSON_OBJECT,
	JSON_STRING,
	JSON_NUMBER,
	JSON_ARRAY
} JsonEntryType;

typedef struct JsonEntry {
	JsonEntryType t;
	union d {
		Jsonifier   o;
		std::string s;
		double      n; // TODO: make more generic to separate ints and floats
		Jsonifier   a; // TODO: implement separate JSON array type
	};
} JsonEntry;

#endif
