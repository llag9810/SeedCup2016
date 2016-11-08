//
//  FileHelper.hpp
//  SeedCupProjectFinal
//
//  Created by 唐艺峰 on 16/11/6.
//  Copyright © 2016年 唐艺峰. All rights reserved.
//

#ifndef FileHelper_hpp
#define FileHelper_hpp

#include <stdio.h>
#include "KeywordToken.h"
#include "TokenHelper.h"
#include <vector>
#include <map>

using namespace std;

class FileHelper{
public:
    vector<KeywordToken> * token1;
    vector<KeywordToken> * token2;
    void getTokens(char * name);
    void getAnswer(char * name, bool result);
private:
    FILE *in, *out;
    TokenHelper tokenHelper;
};
#endif /* FileHelper_hpp */
