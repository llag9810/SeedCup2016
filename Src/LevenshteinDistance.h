//
// Created by yifan on 11/6/16.
//

#ifndef SEEDCUP2016FINAL_DISTANCECALCULATOR_H
#define SEEDCUP2016FINAL_DISTANCECALCULATOR_H

#include <string>
#include <vector>
#include <cmath>
#include "KeywordToken.h"

using namespace std;

class LevenshteinDistance {
public:
    double calculate(vector<KeywordToken> &v1, vector<KeywordToken> &v2);
    int min(int a, int b);
    int max(int a, int b);
    int DutCalculateStringDistance(string &s1, string &s2);
};


#endif //SEEDCUP2016FINAL_DISTANCECALCULATOR_H
