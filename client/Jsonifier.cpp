#include "Jsonifier.h"

Jsonifier::Jsonifier(){
	
}

Jsonifier::~Jsonifier(){
	std::map<std::string, JsonEntry>::iterator it;
	
	for(it = vals.begin(); it != vals.end(); it++){
		JsonEntry v = it->second;
		switch(v.t){
			case JSON_STRING:
				free((void*) v.d.s);
				break;
			default:
				break;
		}
	}
}

void Jsonifier::add_string(std::string k, std::string v){
	JsonEntry e;
	e.t     = JSON_STRING;
	e.d.s   = strdup(v.c_str());
	vals[k] = e;
}

void Jsonifier::add_float(std::string k, double v){
	JsonEntry e;
	e.t     = JSON_FLOAT;
	e.d.f   = v;
	vals[k] = e;
}

void Jsonifier::add_array(std::string k, JsonEntry *v, int len){
	JsonEntry e;
	e.t       = JSON_ARRAY;
	e.d.a.len = len;
	e.d.a.t   = v;
	vals[k]   = e;
}

void Jsonifier::print_entry(JsonEntry *e){
	switch(e->t){
		
		case JSON_STRING: {
			std::cout << "'" << e->d.s << "'";
			break;
		}
		
		case JSON_FLOAT:{
			std::cout << e->d.f;
			break;
		}
		
		case JSON_INTEGER: {
			std::cout << e->d.i;
			break;
		}
				
		case JSON_ARRAY: {
			JsonEntry *h = e->d.a.t;
			std::cout << "[";
			for(int i = 0; i < e->d.a.len; i++){
				print_entry(h+i);
				if(i < e->d.a.len - 1)
					std::cout << ",";
			}
			std::cout << "]";
			break;
		}
				
		case JSON_OBJECT: {
			e->d.o->print();
			break;
		}
				
		default: {
			throw std::runtime_error(
				std::string("JSON printing for data type ") +
				std::to_string((long) e->t) +
				std::string(" not implemented")
			);
		}
			
	}
}

void Jsonifier::print(){
	std::map<std::string, JsonEntry>::iterator it = vals.begin();
	std::cout << "{";
	
	while(it != vals.end()){
		std::string k = it->first;
		JsonEntry   v = it->second;
		
		std::cout << "'" << k << "':";
		print_entry(&v);
		
		if(++it != vals.end()){
			std::cout << ",";
		}
	}
	
	std::cout << "}";
}
