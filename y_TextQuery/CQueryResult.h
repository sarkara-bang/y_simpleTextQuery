//
// Created by sarkara on 2023/9/5.
//
#ifndef TEXTQUERY_CQUERYRESULT_H
#define TEXTQUERY_CQUERYRESULT_H
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<memory>
#pragma once
using namespace std;
//此为一个数据类，用于存放文本查询后的结果
class CQueryResult{
    friend ostream &print(ostream&, CQueryResult&);
public:
    CQueryResult(string w, shared_ptr<set<int>> l,shared_ptr<vector<string>> f);
//private:
    //用户查询的单词
    string word;
    //存放该单词出现行号的set
    shared_ptr<set<int>> lines;
    //以每行为单位存储文件中内容的vector
    shared_ptr<vector<string>> file;
};

//print函数的声明。
ostream& print(ostream& out,CQueryResult qr);

#endif //TEXTQUERY_CQUERYRESULT_H

