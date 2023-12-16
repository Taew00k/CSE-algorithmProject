//
// Created by 허은정 on 12/16/23.
//
#include<iostream>
#include "House.h"
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main(){
    string line;
    ifstream file("BestRoom/houseInfo.txt"); //houseInfo 파일 열기, 없으면 생성
    vector<string> tempS;
    vector<double> tempD;
    vector<House> houseList;
    // 출력의 수
    int count;
    // 중요도
    int monthlyImp;
    int depositImp;
    int distanceImp;
    int sizeImp;
    cout << "출력의 수 : ";
    cin >> count;
    cout << "월세 + 관리비 : ";
    cin >> monthlyImp;
    cout << "보증금 : ";
    cin >> depositImp;
    cout << "거리 : ";
    cin >> distanceImp;
    cout << "평수 : ";
    cin >> sizeImp;

    if(file.is_open()) {
        while (getline(file, line)){

            istringstream ss(line);
            string field;
            int i = 0;
            int s = 0;
            int d = 0;
            string st = "";

            while (getline(ss, field, ',')) {
                //여기에 읽어온 값들의 데이터 타입이 다달라.
                if(i == 0 || i == 5){
                    tempS.push_back(field);
                    s++;
                }else{
                    tempD.push_back(stod(field));
                    d++;
                }
                if(i >= 5){
                    st += field;
                }
                i++;
            }
            House h;
            h.roadNameAddress = tempS.at(0);
            h.monthly = tempD.at(0);
            h.deposit = tempD.at(1);
            h.distance = tempD.at(2);
            h.size = tempD.at(3);
            h.url = st;

            houseList.push_back(h);
        }
    } else{
         cout<<"파일이 열리지 않았어요!";
    }
}