//
// Created by sarkara on 2023/9/5.
//
#ifndef TEXTQUERY_CTEXTQUERY_H
#define TEXTQUERY_CTEXTQUERY_H
#include<iostream>
#include<string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <fstream>
#include "CQueryResult.h"
#pragma once

using namespace std;
//该类为实现查询功能主要的类。
class CTextQuery{
public:
    CTextQuery(ifstream&);
    CQueryResult Query(string&);
private:
    //以行为单位存放文件内容的vector
    shared_ptr<vector<string>> file;
    //存放单词与该单词对应行号集合set的map。
    map<string,shared_ptr<set<int>>> wm;
};

#endif //TEXTQUERY_CTEXTQUERY_H

