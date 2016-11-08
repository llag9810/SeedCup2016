//
//  wordAnalyst.hpp
//  SeedCupProject
//
//  Created by 唐艺峰，王启萌，朱一帆 on 16/10/28.
//  Copyright © 2016年 唐艺峰，王启萌，朱一帆. All rights reserved.
//

#ifndef wordAnalyst_hpp
#define wordAnalyst_hpp

#include "token.hpp"
#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <strstream>
#include <iomanip>
#include <cstring>

using namespace std;

/**
 * 词法分析类，类中函数的注释在.cpp文件中
 */
class WordAnalyst {
public:

/**
 * 分析结束后获得Token流的方法
 * @return 一个装有所有Token的vector
 */
    vector<Token> getTokens();

private:
    int leftSmall = 0;//左小括号
    int rightSmall = 0;//右小括号
    int leftMiddle = 0;//左中括号
    int rightMiddle = 0;//右中括号
    int leftBig = 0;//左大括号
    int rightBig = 0;//右大括号
    int lineBra[6][1000] = {{0}};//括号和行数的对应关系，第一维代表左右6种括号
    int static_iden_number = 0;//模拟标志符的地址，自增
    vector<Token> tokens;
    vector<Token> identifiers;

    void scanner();

/**
 * createNewNode() 创建新Token节点的方法
 * @param content Token的具体内容
 * @param describe Token的描述，如：keyword(保留字), opreator(运算符), identifier(变量名或函数名)等
 * @param type Token的种别码，例如+ - * / 同为operator，但用不同种别码加以区分便于语法分析
 * @param addr 对于identifier(变量名或函数名)而言，如果同一作用域中出现相同的Token，地址是相同的
 * @param line 这个token所在的行数，记录下来便于后续输出
 */
    void createNewNode(string content, string describe, int type, int addr, int line);

/**
 * createNewIden() Token中有一类identifier，即变量名和函数名，在遇到时，不仅加入token流，而且单独维护一份identifier表便于查找
 * @param content
 * @param descirbe
 * @param type
 * @param addr
 * @param line
 * @return
 */
    int createNewIden(string content, string descirbe, int type, int addr, int line);

/**
 * 打印所有Token节点的方法，这是词法分析器做好后进行调试的方法
 */
    void printNodeLink();

/**
 * 预处理#include和#define语句
 * @param word 传入的语句
 * @param line 所在行数
 */
    void preProcess(string word, int line);

/**
 * 寻找保留字的方法
 * @param word 传入用于比较的字符串
 * @return 如果是保留字，返回保留字数组的第i项。如果不是，返回IDENTIFIER(定义好的常量)
 */
    int seekKey(string word);

    //C中的保留字数组
    string key[32] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double",
                      "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
                      "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
                      "union", "unsigned", "void", "volatile", "while"
    };
};

#endif /* wordAnalyst_hpp */
