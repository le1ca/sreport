#include "LibsensorSensor.h"
#include <sensors/sensors.h>
#include <string>
using namespace std;

LibsensorSensor::LibsensorSensor(string name, string label, sensors_chip_name const * chip, int num){
	this->name = name;
	this->label = label;
	this->chip = chip;
	this->num = num;
}

string LibsensorSensor::getName(){
	return name;
}

string LibsensorSensor::getLabel(){
	return label;
}

double LibsensorSensor::getValue(){
	double val;
	int rc = sensors_get_value(chip, num, &val);
	if(rc >= 0) 
		return val;
	else
		return -1;
	return val;
}
void LibsensorSensor::setLabel(string label){
	this->label = label;
}

