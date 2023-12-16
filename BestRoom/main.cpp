//
// Created by 허은정 on 12/16/23.
//
#include <iostream>
#include "House.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CalculatePoint.h"

using namespace std;

int main(){
    string line;
    ifstream file("BestRoom/houseInfo.txt"); //houseInfo 파일 열기, 없으면 생성
    vector<House> houseList;
    // 출력의 수
    int count;
    // 중요도
    int monthlyWeight;
    int depositWeight;
    int distanceWeight;
    int sizeWeight;
    cout << "출력의 수 : ";
    cin >> count;
    cout << "월세 + 관리비 : ";
    cin >> monthlyWeight;
    cout << "보증금 : ";
    cin >> depositWeight;
    cout << "거리 : ";
    cin >> distanceWeight;
    cout << "평수 : ";
    cin >> sizeWeight;

    if(file.is_open()) {
        while (getline(file, line)){

            vector<string> tempS;
            vector<double> tempD;
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

            vector<House> houses = calculateScores(houseList,monthlyWeight,depositWeight,distanceWeight,sizeWeight);
            for (int p = 0 ; p < houses.size(); p++){
                cout<<houses[p].distance<<endl;
            }

        }
    } else {
        cout << "파일이 열리지 않았어요!";
    }

}