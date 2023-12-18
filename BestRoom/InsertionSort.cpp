#include <iostream>
#include <vector>
#include "InsertionSort.h"
using namespace std;

int compare_cnt_insertion = 0;
int datamove_cnt_insertion = 0;

void insertionSort(vector<House>& a, int n) {
    int i, j;
    float v;

    compare_cnt_insertion = 0;
    datamove_cnt_insertion = 0;

    for (i = 1; i < n; i++) {
        v = a[i].totalScore;
        datamove_cnt_insertion++;

        j = i;
        while (++compare_cnt_insertion && j > 0 && a[j - 1].totalScore < v) {
            datamove_cnt_insertion++;
            a[j] = a[j - 1];
            j--;
        }

        a[j].totalScore = v;
        datamove_cnt_insertion++;
    }
}

int insertionCompareCount() {
    return compare_cnt_insertion;
}

int insertionMoveCount() {
    return datamove_cnt_insertion;
}