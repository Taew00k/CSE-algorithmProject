#include <iostream>
#include "House.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "CalculatePoint.h"
#include "PancakeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

using namespace std;

int main() {
    string line;
    ifstream file("BestRoom/houseInfo.txt"); //houseInfo ���� ����, ������ ����
    vector<House> houseList;
    // ����� ��
    int count;
    // �߿䵵
    int monthlyWeight;
    int depositWeight;
    int distanceWeight;
    int sizeWeight;
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "���Ͻô� ����� ����ŭ �Է� �� (����+������, ������, �Ÿ�, ���) 100���� �й��Ͽ� �߿䵵�� ǥ�����ּ���.\n";
    cout << "ex) ����� ��: 5, ����+������: 60, ������: 20, �Ÿ�:10, ���:10\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "����� �� :";
    cin >> count;
    do {
        cout << "���� + ������ :";
        cin >> monthlyWeight;
        cout << "������ :";
        cin >> depositWeight;
        cout << "�Ÿ� :";
        cin >> distanceWeight;
        cout << "��� :";
        cin >> sizeWeight;

        if (monthlyWeight + depositWeight + distanceWeight + sizeWeight != 100) {
            cout << "����ġ�� ���� 100�� �ƴմϴ�. �ٽ� �Է����ּ���.\n";
        }
    } while (monthlyWeight + depositWeight + distanceWeight + sizeWeight != 100);

    if (file.is_open()) {
        while (getline(file, line)) {

            vector<string> tempS;
            vector<double> tempD;
            istringstream ss(line);
            string field;
            int i = 0;
            int s = 0;
            int d = 0;
            string st = "";

            while (getline(ss, field, ',')) {
                //���⿡ �о�� ������ ������ Ÿ���� �ٴ޶�.
                if (i == 0 || i == 5) {
                    tempS.push_back(field);
                    s++;
                } else {
                    tempD.push_back(stod(field));
                    d++;
                }
                if (i >= 5) {
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
        vector<House> houses = calculateScores(houseList, monthlyWeight, depositWeight, distanceWeight, sizeWeight);
        cout << "-----------------��õ ����� ������ ���--------------------\n";
        /*
        //quicksort����
        cout << "-----------------quicksort����--------------------\n";
        */
        quicksort(houses,0,99);
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p+1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly <<"��"<<", ������:"<< houses[p].deposit <<"��"<< ", �Ÿ�: " << setprecision(0) << houses[p].distance<<"m" << ", ��� : " << setprecision(2) << houses[p].size <<"��"<< endl;
            cout << "url : " << houses[p].url << endl;
        }
        /* �ϴ��� ���� ���� ������ quicksort�� ��� ��� �������� �ּ������ϸ� Ȯ�ΰ���
        //shellSort����
        cout << "-----------------shellsort����--------------------\n";
        shellSort(houses,99); // houses�� ������ ���޵˴ϴ�.
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p+1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly <<"��"<<", ������:"<< houses[p].deposit <<"��"<< ", �Ÿ�: " << setprecision(0) << houses[p].distance<<"m" << ", ��� : " << setprecision(2) << houses[p].size <<"��"<< endl;
            cout << "url : " << houses[p].url << endl;
        }
        //pancake ����
        cout << "-----------------pancake����--------------------\n";
        vector<House> pancakeHouses = pancakeSort(houses);
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p+1 << "����) " << "�ּ�: " << pancakeHouses[p].roadNameAddress << ", ����+������: " << setprecision(0) << pancakeHouses[p].monthly <<"��"<<", ������:"<< pancakeHouses[p].deposit <<"��"<< ", �Ÿ�: " << setprecision(0) << pancakeHouses[p].distance<<"m" << ", ��� : " << setprecision(2) << pancakeHouses[p].size <<"��"<< endl;
            cout << "url : " << pancakeHouses[p].url << endl;
        }
        */
    } else {
        cout << "������ ������ �ʾҾ��!";
    }
}