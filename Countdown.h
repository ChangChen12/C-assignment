#ifndef COUNTDOWN_H
#define COUNTDOWN_H
#include<cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using std::string;
using std::vector;
using std::stod;
using std::cout;
using std::endl;
using std::reverse;
using std::sort;
using std::accumulate;
using std::swap;
using std::list;



// this is provided code for the last part of the README



string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

 class CountdownSolution {
  
private:
    string solution;
    int value;
    
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:

void perm(vector<string> list, int k, int m, vector<vector<string>> & result) { 
    
    int i; 
    if(k>m) {
        result.push_back(list);
    }
    else
    { 
    for(i= k ; i <=m;i++)
    {
        if(i!=k)
        {
            string temp = list[k];
            list[k] = list[i];
            list[i] = temp;
        }
        perm(list, k+1, m, result); 
        if(i != k)
        {
        string temp = list[k];
        list[k] = list[i];
        list[i] = temp;
        }
    } 
    } 
}

double evaluateCountdown(const string & expressionIn) {
    vector<double> operationNumber;
    string number = "";
    for (int i = 0; i < expressionIn.size(); i++) {
        char symbol = expressionIn[i];
        double b = 0.0;
        double a = 0.0;
        switch(symbol) {
            case ' ':
            if(number.size() > 0) {
                operationNumber.push_back(stod(number));
                number = "";
            }
            break;
            
            case '+':
            if(operationNumber.size()>=2){
            b = operationNumber.back();
            operationNumber.pop_back();
            a = operationNumber.back();
            operationNumber.pop_back();
            operationNumber.push_back(a + b);
            }else{
                return NULL;
            }
            break;
            
            case '-':
            if(operationNumber.size()>=2){
            b = operationNumber.back();
            operationNumber.pop_back();
            a = operationNumber.back();
            operationNumber.pop_back();
            operationNumber.push_back(a - b);
            }else{
                return NULL;
            }
            break;
            
            case '*':
            if(operationNumber.size()>=2){
            b = operationNumber.back();
            operationNumber.pop_back();
            a = operationNumber.back();
            operationNumber.pop_back();
            operationNumber.push_back(a * b );
            }else{
                 return NULL;
            }
            break;
            
            case '/':
            if(operationNumber.size()>=2){
            b = operationNumber.back();
            operationNumber.pop_back();
            a = operationNumber.back();
            operationNumber.pop_back();
            operationNumber.push_back(a / b);
            }else{
                return NULL;
            }
            break;
            
            default:
            number += symbol;
            break;

        }
    }
    return operationNumber.back();
}

const vector<vector<string>> combinationWithSymbol(const vector<string> & combination){
    
    vector<vector<string>> finalCombinations;
    vector<string> copy = combination;
    
    copy.push_back("+ ");
    finalCombinations.push_back(copy);
    copy.pop_back();

    copy.push_back("- ");
    finalCombinations.push_back(copy);
    copy.pop_back();
   
    copy.push_back("* ");
    finalCombinations.push_back(copy);
    copy.pop_back();
    
    copy.push_back("/ ");
    finalCombinations.push_back(copy);
    copy.pop_back();

    return finalCombinations;
    }

const vector<vector<string>> getCombination(const vector<int> & item) {
    vector<vector<string>> totalCombinations;
    for (int a = 0; a <= 5; a++){
        for (int b = a+1; b <=5; b++) {
            vector<string> singleCombination;
            singleCombination.push_back(intToString(item[a])+" ");
            singleCombination.push_back(intToString(item[b])+" ");
            totalCombinations.push_back(singleCombination);
            for (int c = b+1; c <=5; c++) {
                vector<string> singleCombination;
                singleCombination.push_back(intToString(item[a])+" ");
                singleCombination.push_back(intToString(item[b])+" ");
                singleCombination.push_back(intToString(item[c])+" ");
                totalCombinations.push_back(singleCombination);
                for (int d = c+1; d <=5; d++) {
                    vector<string> singleCombination;
                    singleCombination.push_back(intToString(item[a])+" ");
                    singleCombination.push_back(intToString(item[b])+" ");
                    singleCombination.push_back(intToString(item[c])+" ");
                    singleCombination.push_back(intToString(item[d])+" ");
                    totalCombinations.push_back(singleCombination);
                    for (int e = d+1; e <=5; e++) {
                        vector<string> singleCombination;
                        singleCombination.push_back(intToString(item[a])+" ");
                        singleCombination.push_back(intToString(item[b])+" ");
                        singleCombination.push_back(intToString(item[c])+" ");
                        singleCombination.push_back(intToString(item[d])+" ");
                        singleCombination.push_back(intToString(item[e])+" ");
                        totalCombinations.push_back(singleCombination);
                        for (int f = e+1; f <=5; f++) {
                            vector<string> singleCombination;
                            singleCombination.push_back(intToString(item[a])+" ");
                            singleCombination.push_back(intToString(item[b])+" ");
                            singleCombination.push_back(intToString(item[c])+" ");
                            singleCombination.push_back(intToString(item[d])+" ");
                            singleCombination.push_back(intToString(item[e])+" ");
                            singleCombination.push_back(intToString(item[f])+" ");
                            totalCombinations.push_back(singleCombination);
                            }
                        }
                    }
                }
            }
        }
        int y = totalCombinations.size();
        cout<<y<<endl;
        
        return totalCombinations;
}



const vector<vector<string>> getResult(const vector<string> & input){
       
       vector<vector<string>> twoResult;

        if(input.size() >= 2){
                const vector<vector<string>> & single = combinationWithSymbol(input);
                for(int l = 0;l < single.size();l++)
                {
                    twoResult.push_back(single[l]);
                }
            
       }
       if(input.size() == 2){
           return twoResult;
       }
       vector<vector<string>> threeResult;
       if(input.size() >= 3){
           for(int j = 0; j < twoResult.size();j++){
                const vector<vector<string>> & single = combinationWithSymbol(twoResult[j]);
                for(int l = 0;l<single.size();l++)
                {
                    threeResult.push_back(single[l]);
                }
            }
       }
       if(input.size() == 3){
           return threeResult;
       }
       vector<vector<string>> fourResult;
        if(input.size() >= 4){
           for(int j = 0; j < threeResult.size();j++){
                const vector<vector<string>> & single = combinationWithSymbol(threeResult[j]);
                for(int l = 0;l<single.size();l++)
                {
                    fourResult.push_back(single[l]);
                }
                
           }
       }
       if(input.size() == 4){
           return fourResult;
       }
        vector<vector<string>> fiveResult;
       if(input.size() >= 5){
           for(int j = 0; j < fourResult.size();j++){
                const vector<vector<string>> & single = combinationWithSymbol(fourResult[j]);
                for(int l = 0;l<single.size();l++)
                {
                    fiveResult.push_back(single[l]);
                }
                
           }
       }
       if(input.size() == 5){
           return fiveResult;
       }
        vector<vector<string>> sixResult;
       if(input.size() >= 6){
           for(int j = 0; j < fiveResult.size();j++){
                const vector<vector<string>> & single = combinationWithSymbol(fiveResult[j]);
                for(int l = 0;l<single.size();l++)
                {
                    sixResult.push_back(single[l]);
                }
            }
       } 
           return sixResult;
} 

 
const CountdownSolution   solveCountdownProblem(const vector<int> & problem, const int & target) {
    const vector<vector<string>> & stringVector = getCombination(problem);
    double difference = 10000000000;
    string solutionString;
    for (int i = 0; i < stringVector.size(); i++)
    {  
       const vector<vector<string>> & result = getResult(stringVector[i]);
           for(int j = 0; j < result.size(); j++){
               vector<vector<string>> get;
               const vector<string>  permutation =result[j];
               perm(permutation, 0, permutation.size()-1,get);
               for(int z = 0; z < get.size(); z++){
                   
                   if(get[z][0]=="+ "||get[z][0]=="- "||get[z][0]=="* "||get[z][0]=="/ "){
                       continue;
                   }
                   if(get[z][1]=="+ "||get[z][1]=="- "||get[z][1]=="* "||get[z][1]=="/ "){
                       continue;
                   }
                   if(get[z][get[z].size()-1]!="+ "&&get[z][get[z].size()-1]!="- "&&get[z][get[z].size()-1]!="* "&&get[z][get[z].size()-1]!="/ "){
                       continue;
                   }
                   string trans = "";
                   
                   for(int x = 0; x < get[z].size();x++){
                       
                       trans += get[z][x];
                    }
                    
                    
                    if(NULL == evaluateCountdown(trans)){
                        continue;
                        }
                    
                    if(target==evaluateCountdown(trans)){
                       
                        const CountdownSolution & two = CountdownSolution(trans,target);
                        return two;
                    }
                    
                    if(fabs(evaluateCountdown(trans)-target)<difference){
                        difference = fabs(evaluateCountdown(trans)-target);
                        solutionString = trans;
                    }
                }
           
            }
        }
        const CountdownSolution & one = CountdownSolution(solutionString,evaluateCountdown(solutionString));
        return one; 
    }
    








    
    






// Do not edit below this line


#endif
