//
//  FileHelper.cpp
//  SeedCupProjectFinal
//
//  Created by 唐艺峰 on 16/11/6.
//  Copyright © 2016年 唐艺峰. All rights reserved.
//

#include "FileHelper.hpp"
#include <stdio.h>
#include <string>
#include "KeywordToken.h"
#include <vector>
#include <map>


void FileHelper::getTokens(char * name){
    char tempToken1[1000];
    char tempToken2[1000];
    in = fopen(name, "r");
    fscanf(in, "%s", tempToken1);
    fscanf(in, "%s", tempToken2);
    string tokens1(tempToken1);
    string tokens2(tempToken2);
    token1 = tokenHelper.getTokens(tokens1);
    token2 = tokenHelper.getTokens(tokens2);
    fclose(in);
}

void FileHelper::getAnswer(char * name, bool result){
    out = fopen(name, "w");
    fprintf(out, "%d", (result) ? 1 : 0);
    fclose(out);
}
