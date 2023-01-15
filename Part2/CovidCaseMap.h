#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include <iostream>
#include <vector>
using std::ostream;
using std::cout;
using std::endl;
using std::cout;
using std::vector;



// TODO: your code goes here
class  TimeAndCaseData {
private:
    int time;
    int numberOfCases;

public:
     TimeAndCaseData(const int timeIn, const int number)
         :time(timeIn), numberOfCases(number){
             
         }
     



int getTime()
{
    return time;
}

int getNumberOfCases()
{
    return numberOfCases;
}



};




class CovidCaseMap {
private:
    vector<CovidCase> list;

public:



void addCase(const CovidCase & oneCase)
{
    list.push_back(oneCase);
}


const vector<TimeAndCaseData> getCasesOverTime(int number){
    vector<TimeAndCaseData> activeCases;
     
     vector<int> mark;
    
    for (int i = 0; i < list.size(); i++)
    {    
        int x = list[i].getTime();

        if(activeCases.size() == 0){
            activeCases.push_back(TimeAndCaseData(x,1));
            continue;
        }   
            int a = activeCases.size();
            for (int j = 0; j < a; j++){  
                bool check = true;
                 for(int i = 0; i < mark.size(); i++){
                        if(j == mark[i]){
                            check = false;
                            break;
                        }
                        }
                        if(check == false){
                            continue;
                        }

                int deadline = activeCases[j].getTime()+number;
                if(deadline < x){
                    activeCases.push_back(TimeAndCaseData(deadline,activeCases.back().getNumberOfCases()-1));
                    mark.push_back(activeCases.size()-1);
                    mark.push_back(j);
                }
            }
        activeCases.push_back(TimeAndCaseData(x, activeCases.back().getNumberOfCases()+1));
        if(i == list.size()-1){
            int b = activeCases.back().getTime()+number;
            int c = activeCases.size();
            for (int j = 0; j < c; j++){   
                bool check = true;
                 for(int i = 0; i < mark.size(); i++){
                        if(j == mark[i]){
                            check = false;
                            break;
                        }
                        }
                        if(check == false){
                            continue;
                        }
                int deadline = activeCases[j].getTime()+number;
                
                if(deadline < b){
                    activeCases.push_back(TimeAndCaseData(deadline,activeCases.back().getNumberOfCases()-1));
                }
            }
            activeCases.push_back(TimeAndCaseData(b, 0));
            activeCases.insert(activeCases.begin(),TimeAndCaseData(0, 0));


        }
    }
    return activeCases;
            
        
    }

double distanceTo(CovidCase & checkIn, double lat, double lon) const{
	double lat1 = lat*3.1415926/180.0;
	double lat2 = checkIn.getLatitude()*3.1415926/180.0;
	double lon1 = lon*3.1415926/180.0;
	double lon2 = checkIn.getLongitude()*3.1415926/180.0;
	double radLon = lon2 - lon1;
    double radLat = lat2 - lat1;
    double a = pow((sin(radLat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(radLon/2)), 2);
    double c = 2 * atan2( sqrt(a), sqrt(1-a) );
    double distance = 3960 * c;
	return distance;
	}

double supportVisitGreedyTSP(double lat, double lon, int time, int period){
    vector<CovidCase> checkin;
    for (int i = 0; i < list.size(); i++)
    {
        
        if(list[i].getTime()<time && list[i].getTime()+period > time){
            checkin.push_back(list[i]);
        }
    }
    
    double goBack = 0;
    double routeLength = 0;
    double latitude = lat;
    double longitude = lon;
    while(checkin.empty() == false){
    int mark = 0;
    double distance = distanceTo(checkin[0], latitude, longitude);
    for(int j = 0; j < checkin.size(); j++){
       if(distance > distanceTo(checkin[j],latitude,longitude)){
           distance = distanceTo(checkin[j],latitude,longitude);
           mark = j;
            }
        }
           latitude = checkin[mark].getLatitude();
           longitude = checkin[mark].getLongitude();
           routeLength += distance;
           goBack = distanceTo(checkin[mark],lat,lon);
           checkin.erase(checkin.begin() + mark);
        }
       routeLength += goBack;
    return routeLength;
    
}




    

    




};





// don't write any code below this line

#endif

