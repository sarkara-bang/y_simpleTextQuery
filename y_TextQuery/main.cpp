#include<iostream>
#include "CTextQuery.h"
#include "CQueryResult.h"
using namespace std;


void runCTextQuery(ifstream &inFile){
    CTextQuery tq(inFile);
    //为使用者提供复数查询或退出的选项。
    while(true){
        string s;
        cout << "enter word you look for ,or q to quit:";
        //读取的字符串为空的情况。
        if(!(cin >> s)) {
            cout<<"exit:you entered nothing!"<<endl;
            break;
        //用户选择退出。
        }else if(s == "q"){
            cout<<"exit:user quit!"<<endl;
            break;
        //查询并打印查询结果。
        }else{
            print(cout,(tq.Query(s)));
        }
    }
}

int main() {
    //需要查询的文件的文件名。如果使用相对路径打开文件，请确保文件与可运行程序处在同一文件夹下。
    ifstream inFile("dngg.txt");
    //对是否成功打开文件的简单提示。
    if(inFile.is_open() == 0){
        cout<<"file open failed!"<<endl;
    }else{
        cout<<"your file is opened!"<<endl;
        //成功打开文件，进行文件查询函数。
        runCTextQuery(inFile);
    }
    return 0;
}