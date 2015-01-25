#ifndef LibsensorSensor_h
#include "AbstractSensor.h"
#include <sensors/sensors.h>
#include <string>
class LibsensorSensor : public AbstractSensor {
  private:
  	std::string name;
  	std::string label;
  	sensors_chip_name const * chip;
  	int num;
  public:
  	LibsensorSensor(std::string name, std::string label, sensors_chip_name const * chip, int num);
	double getValue();
	std::string getName();
	std::string getGroup();
	std::string getLabel();
	void setLabel(std::string label);
};
#define LibsensorSensor_h
#endif
