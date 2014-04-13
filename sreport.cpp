#include "LibsensorManager.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    LibsensorManager s = LibsensorManager();
    vector<AbstractSensor*> sensors = s.getSensors();
    for (unsigned i=0; i<sensors.size(); i++){
    	AbstractSensor* id = sensors.at(i);
		cout << id->getLabel() << " => " << id->getValue() << endl;
	}
    return 0;
}
