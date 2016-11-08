//
// Created by yifan on 11/6/16.
//

#include "KeywordToken.h"
KeywordToken::KeywordToken(string name, string property, double weight, bool isKey) {
    this->name = name;
    this->property = property;
    this->weight = weight;
    this->isKey = isKey;
}
KeywordToken::KeywordToken() {

}