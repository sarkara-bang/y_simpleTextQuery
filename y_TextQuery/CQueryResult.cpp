//
// Created by sarkara on 2023/9/6.
//
#include <iostream>
#include "CQueryResult.h"

using namespace std;
//CQueryResult类的构造函数
CQueryResult::CQueryResult(string w, shared_ptr<set<int>> l,
                           shared_ptr<vector<string>> f):word(w),lines(l),file(f){}

//print函数为CQueryResult对象提供输出。
ostream& print(ostream& out,CQueryResult qr){
    if(qr.lines->size() == 0){
        //lines中没有记录的单词，即该单词不存在。
        out<<"there's no "<<qr.word<<" in this particle!"<<endl;
    }else{
        int n = qr.lines->size();
        //提示单词出现次数。
        out << "'" << qr.word << "'" << " occurs " << n <<" times!" << endl;
        //根据行号对出现查询单词的行逐个输出。
        for(set<int>::iterator it = qr.lines->begin();it != qr.lines->end();it++){
            out<< "(line" << *it + 1 << ")" << " " + qr.file->at(*it) << endl;
        }
        cout<<endl;
    }
    return out;
}