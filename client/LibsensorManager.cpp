#include "LibsensorManager.h"
#include "LibsensorSensor.h"
#include <sensors/sensors.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

LibsensorManager::LibsensorManager(){
	// initialize libsensors
	sensors_init(NULL);
	
	// initialize our hashmap
	mappings = map<string, LibsensorSensor>();
	
	// local variables for iterating sensors
	sensors_chip_name const * cn;
	sensors_feature const *feat;
	sensors_subfeature const *subf;
	char* label;
    int c = 0;
    
    // get all readable input sensors and put them in the map
    while((cn = sensors_get_detected_chips(0, &c)) != 0) {
        int f = 0;
        while((feat = sensors_get_features(cn, &f)) != 0) {
            int s = 0;
            
            // this function call leaks memory... not sure if there's anything we can do about it
			label = sensors_get_label(cn, feat);
			
			// TODO: optimize this by using the get_subfeature function so we don't have to loop
            while((subf = sensors_get_all_subfeatures(cn, feat, &s)) != 0) {
                double val;
                bool input;
                
                // we're only interested in the actual value of the sensor
                switch(subf->type){
                	// temperature sensors
                	case SENSORS_SUBFEATURE_TEMP_INPUT:
                		input = true;
                		break;
					default:
						input = false;
						break;
                }
                
                // verify that we can actually read the sensor
                if(subf->flags & SENSORS_MODE_R && input) {
                    int rc = sensors_get_value(cn, subf->number, &val);
                    if(rc >= 0) {
                    	string name = string(cn->prefix) + "_" + string(subf->name);
                    	LibsensorSensor id = LibsensorSensor(name, label, cn, subf->number);
                    	mappings.insert(pair<string,LibsensorSensor>(name, id));
                    }
                }
            }
        }
    }
}

LibsensorManager::~LibsensorManager(){
	sensors_cleanup();
}

string LibsensorManager::getVersion(){
    ostringstream conv;
    conv << "Using libsensors version " << libsensors_version;
    return conv.str();
}

AbstractSensor* LibsensorManager::getSensor(string key){
	return &(mappings.at(key));
}

vector<AbstractSensor*> LibsensorManager::getSensors(){
	vector<AbstractSensor*> v = vector<AbstractSensor*>();
	for(map<string,LibsensorSensor>::iterator it=mappings.begin(); it!=mappings.end(); ++it)
    	v.push_back(&(it->second));
	return v;
}

vector<string> LibsensorManager::getKeys(){
	vector<string> v = vector<string>();
	for(map<string,LibsensorSensor>::iterator it=mappings.begin(); it!=mappings.end(); ++it)
    	v.push_back(it->first);
	return v;
}

