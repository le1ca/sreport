#ifndef LibsensorSource_h
#include "AbstractManager.h"
#include "LibsensorSensor.h"
#include <string>
#include <vector>
#include <map>
class LibsensorManager : public AbstractManager {
  private:
  	std::map<std::string, LibsensorSensor> mappings;
  public:
	LibsensorManager();
	~LibsensorManager();
	std::string getVersion();
	std::vector<std::string> getKeys();
	std::vector<AbstractSensor*> getSensors();
	AbstractSensor* getSensor(std::string name);
};
#define LibsensorSource_h
#endif
