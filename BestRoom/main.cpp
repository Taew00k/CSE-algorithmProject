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
#include "InsertionSort.h"
#include <chrono>

using namespace std;

int main() {
    string line;
    ifstream file("C:\\Clion\\dongguk\\BestRoom\\houseInfo.txt"); //houseInfo ���� ����, ������ ����
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
            cout << "�߿䵵�� ���� 100�� �ƴմϴ�. �ٽ� �Է����ּ���.\n";
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
                }
                else {
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
        //quicksort �� ���� �ð� ���
        cout << "-----------------quicksort����--------------------\n";
        auto quick_start_time = chrono::high_resolution_clock::now();
        quicksort(houses, 0, 99);
        auto quick_end_time = chrono::high_resolution_clock::now();
        auto quick_duration = chrono::duration_cast<chrono::microseconds>(quick_end_time - quick_start_time);

        cout << fixed;
        for (int p = 0; p < count; p++) {
        cout << p + 1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly << "��" << ", ������:" << houses[p].deposit << "��" << ", �Ÿ�: " << setprecision(0) << houses[p].distance << "m" << ", ��� : " << setprecision(2) << houses[p].size << "��" << endl;
        cout << "url : " << houses[p].url << endl;
        }

        //shellSort �� ���� �ð� ���
        cout << "-----------------shellsort����--------------------\n";
        auto shell_start_time = chrono::high_resolution_clock::now();
        shellSort(houses, 99); // houses�� ������ ���޵˴ϴ�.
        auto shell_end_time = chrono::high_resolution_clock::now();
        auto shell_duration = chrono::duration_cast<chrono::microseconds>(shell_end_time - shell_start_time);
        cout << fixed;
        for (int p = 0; p < count; p++) {
        cout << p + 1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly << "��" << ", ������:" << houses[p].deposit << "��" << ", �Ÿ�: " << setprecision(0) << houses[p].distance << "m" << ", ��� : " << setprecision(2) << houses[p].size << "��" << endl;
        cout << "url : " << houses[p].url << endl;
        }

        //pancake �� ���� �ð� ���
        cout << "-----------------pancake����--------------------\n";
        auto pan_start_time = chrono::high_resolution_clock::now();
        vector<House> pancakeHouses = pancakeSort(houses);
        auto pan_end_time = chrono::high_resolution_clock::now();
        auto pan_duration = chrono::duration_cast<chrono::microseconds>(pan_end_time - pan_start_time);
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p + 1 << "����) " << "�ּ�: " << pancakeHouses[p].roadNameAddress << ", ����+������: " << setprecision(0) << pancakeHouses[p].monthly << "��" << ", ������:" << pancakeHouses[p].deposit << "��" << ", �Ÿ�: " << setprecision(0) << pancakeHouses[p].distance << "m" << ", ��� : " << setprecision(2) << pancakeHouses[p].size << "��" << endl;
            cout << "url : " << pancakeHouses[p].url << endl;
        }
*/
        // Insertion �� ���� �ð� ���
        cout << "-----------------���� ����--------------------\n";
        auto insert_start_time = chrono::high_resolution_clock::now();
        insertionSort(houses, 99);
        auto insert_end_time = chrono::high_resolution_clock::now();
        auto insert_duration = chrono::duration_cast<chrono::microseconds>(insert_end_time - insert_start_time);
        cout << fixed;
        for (int p = 0; p < count; p++) {
            cout << p + 1 << "����) " << "�ּ�: " << houses[p].roadNameAddress << ", ����+������: " << setprecision(0) << houses[p].monthly << "��" << ", ������:" << houses[p].deposit << "��" << ", �Ÿ�: " << setprecision(0) << houses[p].distance << "m" << ", ��� : " << setprecision(2) << houses[p].size << "��" << endl;
            cout << "url : " << houses[p].url << endl;
        }

        // �񱳿��� �� �̵����� Ƚ�� ���
        cout << endl;
        //cout << "-----QuickSort-----" << endl;
        //cout << "�񱳿��� Ƚ��: " << quickCompareCount() << ", �̵����� Ƚ��: " << quickMoveCount() << endl;
        //cout << "-----PanCakeSort-----" << endl;
        //cout << "�񱳿��� Ƚ��: " << pancakeCompareCount() << ", �̵����� Ƚ��: " << pancakeMoveCount() << endl;
        //cout << "-----ShellSort-----" << endl;
        //cout << "�񱳿��� Ƚ��: " << shellCompareCount() << ", �̵����� Ƚ��: " << shellMoveCount() << endl;
        cout << "-----InsertionSort-----" << endl;
        cout << "�񱳿��� Ƚ��: " << insertionCompareCount() << ", �̵����� Ƚ��: " << insertionMoveCount() << endl;

        // ���� �ð� ���
        cout << endl;
        cout << "-----���� �� ���� ���� �ð� ���-----" << endl;
        //cout << "QuickSort ���� �ð� : " << quick_duration.count() << "microseconds" << endl;
        //cout << "PancakeSort ���� �ð� : " << pan_duration.count() << "microseconds" << endl;
        //cout << "ShellSort ���� �ð� : " << shell_duration.count() << "microseconds" << endl;
        cout << "InsertionSort ���� �ð� : " << insert_duration.count() << "microseconds" << endl;
    }
    else {
        cout << "������ ������ �ʾҾ��!";
    }
}