//
// Created by yifan on 11/6/16.
//

#ifndef SEEDCUP2016FINAL_KEYWORDTOKEN_H
#define SEEDCUP2016FINAL_KEYWORDTOKEN_H

#include <string>
using namespace std;

class KeywordToken {
public:
    string name;
    string property;
    double weight;
    bool isKey;
    KeywordToken(string name, string property, double weight, bool isKey);
    KeywordToken();
};


#endif //SEEDCUP2016FINAL_KEYWORDTOKEN_H
