//
// Created by yifan on 11/6/16.
//

#include "TokenHelper.h"
#include "cppjieba/Jieba.hpp"

vector<KeywordToken> * TokenHelper::getTokens(string s){
    vector<KeywordToken> tokens;
    cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
    vector<pair<string, string> > tagres;
    jieba.Tag(s, tagres);
    int cur = 0;
    for (int i = 0; i < tagres.size(); ++i) {
        KeywordToken token = KeywordToken();
        pair<string,string> res = tagres[i];
        token.name = res.first;
        token.property = res.second;
        tokens.push_back(token);
        cout<<"名字：" + token.name + "         属性" + token.property<<endl;

    }

    const size_t topk = 30000;
    vector<cppjieba::KeywordExtractor::Word> keywordres;
    jieba.extractor.Extract(s, keywordres, topk);
    for (int j = 0; j < keywordres.size(); ++j) {
        for (int k = 0; k < tokens.size(); ++k) {
            if(keywordres[j].word == tokens[k].name){
                tokens[k].isKey = true;
                tokens[k].weight = keywordres[j].weight;
            }
        }
        cout<<keywordres[j].word<<endl;
    }

    for (int i = 0; i < tokens.size(); ++i) {
        cout<<"name:" + tokens[i].name<<endl;
        cout<<"weight:"<<tokens[i].weight<<endl;
        cout<<"iskey:" << tokens[i].isKey <<endl;
        cout<<"property:"<<tokens[i].property <<endl;
    }
    return &tokens;
}