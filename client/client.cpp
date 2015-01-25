#include "LibsensorManager.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
	(void) argc; // to satisfy -Wpedantic for now
	(void) argv;

    LibsensorManager s = LibsensorManager();
    vector<AbstractSensor*> sensors = s.getSensors();
    
    for (unsigned i=0; i<sensors.size(); i++){
    	AbstractSensor* id = sensors.at(i);
    	cout << " {  " << endl;
    	cout << "    " << "name:  " << id->getName()  << endl;
    	cout << "    " << "group: " << id->getGroup() << endl;
    	cout << "    " << "label: " << id->getLabel() << endl;
    	cout << "    " << "value: " << id->getValue() << endl;
		cout << " }  " << endl << endl;;
	}
	
    return 0;
}
