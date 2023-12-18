#include "InsertionSort.h"

int compare_cnt_insertion = 0;
int datamove_cnt_insertion = 0;

void insertionSort(vector<House>& a, int n) {
    int i, j;
    float v;

    compare_cnt_insertion = 0;
    datamove_cnt_insertion = 0;

    for (i = 1; i < n; i++) {
        House temp = a[i]; // temp 객체에 a[i]를 저장합니다.
        datamove_cnt_insertion++;

        j = i;
        while (++compare_cnt_insertion && j > 0 && a[j - 1].totalScore < temp.totalScore) { // temp.totalScore와 비교합니다.
            datamove_cnt_insertion++;
            a[j] = a[j - 1];
            j--;
        }

        a[j] = temp; // temp 객체를 a[j]에 저장합니다.
        datamove_cnt_insertion++;
    }
}

int insertionCompareCount() {
    return compare_cnt_insertion;
}

int insertionMoveCount() {
    return datamove_cnt_insertion;
}