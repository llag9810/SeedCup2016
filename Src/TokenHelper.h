//
// Created by yifan on 11/6/16.
//

#ifndef SEEDCUP2016FINAL_TOKENHELPER_H
#define SEEDCUP2016FINAL_TOKENHELPER_H

#include <string>
#include <vector>
#include "KeywordToken.h"

using namespace std;
const char* const DICT_PATH = "./dict/jieba.dict.utf8";
const char* const HMM_PATH = "./dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "./dict/user.dict.utf8";
const char* const IDF_PATH = "./dict/idf.utf8";
const char* const STOP_WORD_PATH = "./dict/stop_words.utf8";

class TokenHelper {
public:
    vector<KeywordToken> *getTokens(string s);
};


#endif //SEEDCUP2016FINAL_TOKENHELPER_H
