#ifndef AbstractSensor_h
#include <string>
class AbstractSensor {
  public:
  	virtual double getValue() = 0;
	virtual std::string getName() = 0;
	virtual std::string getLabel() = 0;
	virtual void setLabel(std::string label) = 0;
};
#define AbstractSensor_h
#endif
