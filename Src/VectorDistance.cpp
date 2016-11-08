//
//  VectorDistance.cpp
//  SeedCupProjectFinal
//
//  Created by 唐艺峰 on 16/11/6.
//  Copyright © 2016年 唐艺峰. All rights reserved.
//

#include "VectorDistance.hpp"
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include "KeywordToken.h"
#include <vector>
#include <map>

using namespace std;

double getAverage(vector<double> numbers);
double getSum(vector<double> numbers);

VectorDistance::VectorDistance(){
    initialValues();
}

void VectorDistance::initialValues(){
    values.insert(pair<string, double>("nK", 100.0));
    values.insert(pair<string, double>("n", 20.0));
    values.insert(pair<string, double>("nrK", 60.0));
    values.insert(pair<string, double>("nr", 15.0));
    values.insert(pair<string, double>("aK", 60.0));
    values.insert(pair<string, double>("a", 15.0));
    values.insert(pair<string, double>("engK", 100.0));
    values.insert(pair<string, double>("eng", 20.0));
    values.insert(pair<string, double>("x", 0.0));
    values.insert(pair<string, double>("defaultK", 80.0));
    values.insert(pair<string, double>("default", 16.0));
}

double VectorDistance::calculate(vector<KeywordToken> goodA  , vector<KeywordToken> goodB){
    vector<double> valuesOfA;
    vector<double> valuesOfB;
    vector<string> namesOfA;
    vector<string> namesOfB;
    for(int i = 0; i < goodA.size(); i++){
        namesOfA.insert(namesOfA.end(), goodA[i].name);
    }
    for(int i = 0; i < goodB.size(); i++){
        namesOfB.insert(namesOfB.end(), goodB[i].name);
    }
    for(int i = 0; i < goodA.size(); i++){
        if(find(namesOfB.begin(), namesOfB.end(), namesOfA[i]) != namesOfB.end()){
            valuesOfA.insert(valuesOfA.end(), getValueOfToken(goodA[i]));
            valuesOfB.insert(valuesOfB.end(), getValueOfToken(goodA[i]));
        }else{
            valuesOfA.insert(valuesOfA.end(), getValueOfToken(goodA[i]));
            valuesOfB.insert(valuesOfB.end(), 0);
        }
    }
    double numerator = 0.0;
    double denominator = 0.0;
    double sumOfSquareA = 0.0;
    double sumOfSquareB = 0.0;
    for(int i = 0; i < valuesOfA.size(); i++){
        numerator = numerator + (valuesOfA[i]) * (valuesOfB[i]);
        sumOfSquareA = sumOfSquareA + (valuesOfA[i]) * (valuesOfA[i]);
        sumOfSquareB = sumOfSquareA + (valuesOfA[i]) * (valuesOfA[i]);
    }
    denominator = sqrt((sumOfSquareA)) * sqrt((sumOfSquareB));
    return numerator/ denominator;
}

double VectorDistance::getValueOfToken(KeywordToken token){
    if(token.property.compare("n") == 0){
        if(token.isKey)
            return values.at("nK");
        else
            return values.at("n");
    }else if(token.property.compare("nr") == 0){
        if(token.isKey)
            return values.at("nrK");
        else
            return values.at("nr");
    }else if(token.property.compare("a") == 0){
        if(token.isKey)
            return values.at("aK");
        else
            return values.at("a");
    }else if(token.property.compare("eng") == 0){
        if(token.isKey)
            return values.at("engK");
        else
            return values.at("eng");
    }else if(token.property.compare("x") == 0){
        return values.at("x");
    }else{
        if(token.isKey)
            return values.at("defaultK");
        else
            return values.at("default");
    }
    return 0;
}

double getSum(vector<double> numbers){
    double result = 0.0;
    for(int i = 0; i < numbers.size(); i++){
        result = result + numbers[i];
    }
    return result;
}

double getAverage(vector<double> numbers){
    double result = 0.0;
    result = getSum(numbers) / numbers.size();
    return result;
}