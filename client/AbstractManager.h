#ifndef AbstractManager_h
#include "AbstractSensor.h"
#include <string>
#include <vector>
class AbstractManager {
  public:
  	virtual std::vector<std::string> getKeys() = 0;
  	virtual std::vector<AbstractSensor*> getSensors() = 0;
  	virtual AbstractSensor* getSensor(std::string key) = 0;
};
#define AbstractManager_h
#endif
