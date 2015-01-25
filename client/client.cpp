#include "LibsensorManager.h"
#include "Jsonifier.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	(void) argc; // to satisfy -Wpedantic for now
	(void) argv;

    LibsensorManager s = LibsensorManager();
    vector<AbstractSensor*> sensors = s.getSensors();
    
    Jsonifier ja;
    Jsonifier *js = new Jsonifier[sensors.size()];

    JsonArray a;
    a.len = sensors.size();
    a.t   = (JsonEntry*) malloc(a.len * sizeof(JsonEntry));
    
    for (unsigned i=0; i<sensors.size(); i++){
    	AbstractSensor* id = sensors.at(i);
    	
    	/*
    	cout << " {  " << endl;
    	cout << "    " << "name:  " << id->getName()  << endl;
    	cout << "    " << "group: " << id->getGroup() << endl;
    	cout << "    " << "label: " << id->getLabel() << endl;
    	cout << "    " << "value: " << id->getValue() << endl;
		cout << " }  " << endl << endl;
		*/

		js[i].add_string("name",  id->getName() );
		js[i].add_string("group", id->getGroup());
		js[i].add_string("label", id->getLabel());
		js[i].add_float ("value", id->getValue());
		
		JsonEntry e;
		e.t = JSON_OBJECT;
		e.d.o = &js[i];
		a.t[i] = e;
	}
	
	ja.add_array("sensors", a.t, a.len);
	ja.print();
	cout << endl;
	
	delete[] js;
	free(a.t);
	
    return 0;
}
