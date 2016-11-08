//
//  VectorDistance.hpp
//  SeedCupProjectFinal
//
//  Created by 唐艺峰 on 16/11/6.
//  Copyright © 2016年 唐艺峰. All rights reserved.
//

#ifndef VectorDistance_hpp
#define VectorDistance_hpp

#include <stdio.h>
#include "KeywordToken.h"
#include <vector>
#include <map>

using namespace std;

class VectorDistance{
public:
    double calculate(vector<KeywordToken> goodA, vector<KeywordToken> goodB);
    VectorDistance();
private:
    map<string, double> values;
    void initialValues();
    double getValueOfToken(KeywordToken token);
};

#endif /* VectorDistance_hpp */
