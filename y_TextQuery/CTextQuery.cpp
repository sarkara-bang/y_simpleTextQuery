//
// Created by sarkara on 2023/9/5.
//
#include "CTextQuery.h"
#include "CQueryResult.h"
#include <string>
using namespace std;

//CTextQuery类的构造函数将文件存放到vector中，并在这个过程中建立单词与行号集合的对应关系。
CTextQuery::CTextQuery (ifstream& inFile):file(new vector<string>){
    string line;
    //从inFile中不忽略空格的直接读取一整行。
    while(getline(inFile,line)){
        file->push_back(line);

        //获取相应行号。
        int n = file->size() - 1;
        istringstream words(line);
        string word;
        //利用istringstream对象将一行内容以空格为分隔符，分割成单个单词。
        while(words >> word){
            //若wordmap中没有出现过单词word，则分配一个空的shared_ptr
            auto& line_nos = wm[word];
            if(!line_nos){
                //line_nos为空则创建一个新的set给其维护。
                line_nos.reset(new set<int>);
            }
            //将行号添加到set中。
            line_nos->insert(n);
        }
    }
}

CQueryResult CTextQuery::Query(string& s){
    //准备空的set
    shared_ptr<set<int>> empty(new set<int>);

    //在word map 中查询单词关联的行号集合set
    auto location = wm.find(s);
    //如果在map中没有找到相应单词的记录，则将空set传进CQueryResult对象中
    CQueryResult qro (s,empty,file);
    CQueryResult qrt (s,(location->second),file);

    if(location == wm.end()){
        return qro;
    }
    else {
        return qrt;
    }
}