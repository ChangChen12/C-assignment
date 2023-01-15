#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <math.h>
#include <iostream>
using std::ostream;
using std::cout;
//
#include <string>
using std::string;

// TODO: your code  goes here
 class CovidCase {
private:
	double latitude;
	double longitude;
	string name; 
	int age;
	int time;

public:
	CovidCase(const double latitudeIn, const double longitudeIn, const string & nameIn, const int ageIn, const int timeIn)
		: latitude(latitudeIn), longitude(longitudeIn), name(nameIn), age(ageIn), time(timeIn) {

		cout << "Made a CovidCase : " << latitude << ", " << longitude << ", " << name << ", " << age << ", " << time << "\n";
	}

	double getLatitude () const{
		return latitude;
	}

	double getLongitude() const{
		return longitude;
	}

	const string & getName() const{
        return name;  
	}

	int getAge() const{
		return age;
	}
	
	int getTime() const{
		return time;
	}

	double distanceTo(CovidCase & CovidCaseIn) const{
		double lat1 = latitude*3.1415926/180.0;
		double lat2 = CovidCaseIn.getLatitude()*3.1415926/180.0;
		double lon1 = longitude*3.1415926/180.0;
		double lon2 = CovidCaseIn.getLongitude()*3.1415926/180.0;
		double radLon = lon2 - lon1;
        double radLat = lat2 - lat1;
        double a = pow((sin(radLat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(radLon/2)), 2);
        double c = 2 * atan2( sqrt(a), sqrt(1-a) );
        double distance = 3960 * c;
		return distance;
	}

};

ostream & operator<<(ostream & o, const CovidCase & toPrint) {
    o << "{" << toPrint.getLatitude() << ", " << toPrint.getLongitude() << ", " << "\"" << toPrint.getName() << "\"" << ", " << toPrint.getAge() << ", " << toPrint.getTime() << "}";
    return o;
}

//don't write any code below this line

#endif
