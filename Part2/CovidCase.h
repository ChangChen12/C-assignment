// TODO: Replace this file with your CovidCase.h from Part1
// then extend as per the instructions in README.md

#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <math.h>
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
using std::cout;

#include <string>
using std::string;
using std::stod;
using std::stoi;

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
	//51.5115, -0.1160, \"PatientA\", 48, 49
	CovidCase(const string & constructByString ){
		string analysis = "";
		int count = 0;
        int countForquote = 0;
		for (int i = 0 ; i < constructByString.size(); i++){
			switch(constructByString[i]){
				case ' ':
				if(countForquote == 1){
					analysis += constructByString[i];
				}
				break;
				

				case '"':
				countForquote++;
				break;

				case ',':
				if(count == 0){
					latitude = stod(analysis);
					analysis = "";
					count++;
					break;
				}
				if(count == 1){
					longitude = stod(analysis);
					analysis = "";
					count++;
					break;
				}if(count == 2){
					name = analysis;
					analysis = "";
					count++;
					break;
				}if(count == 3){
					age = stoi(analysis);
					analysis = "";
					count++;
					break;
				}

				default:
				analysis += constructByString[i];
				if(i == constructByString.size() - 1){
					time = stoi(analysis);
				}
				break;
				}
		    }
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

	bool operator==(const CovidCase & other) const {
         return (latitude == other.latitude&&longitude == other.longitude&&name == other.name&&age == other.age&&time == other.time);
    }

};

double translate(string tr){
	double x = stod(tr);
	return x;
}

ostream & operator<<(ostream & o, const CovidCase & toPrint) {
    o << "{" << toPrint.getLatitude() << ", " << toPrint.getLongitude() << ", " << "\"" << toPrint.getName() << "\"" << ", " << toPrint.getAge() << ", " << toPrint.getTime() << "}";
    return o;
}

//don't write any code below this line

#endif