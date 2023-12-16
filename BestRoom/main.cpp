//
// Created by 허은정 on 12/16/23.
//
#include<iostream>
#include "House.h"
#include <fstream>

using namespace std;

int main(){
    string line;
    ifstream file("houseInfo.txt"); //houseInfo 파일 열기, 없으면 생성
    string name;
    int number;
    if(file.is_open()) {
        while (getline(file, line)){
            cout << line << endl;
            file >> name >> number;
        }
    }
}