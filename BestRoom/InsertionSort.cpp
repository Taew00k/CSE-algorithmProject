#include "InsertionSort.h"

int compare_cnt_insertion = 0;
int datamove_cnt_insertion = 0;

// 내림차순 정렬 함수
void insertionSort(vector<House>& arr, int n) {
    int i, j;
    House v;
    n = n+1;

    for (i = 2; i <= n; i++) {
        v = arr[i];
        datamove_cnt_insertion++;

        j = i;
        while (++compare_cnt_insertion && j > 0 && arr[j - 1].totalScore < v.totalScore) {
            datamove_cnt_insertion++;
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = v;
        datamove_cnt_insertion++;
    }
}
int insertionCompareCount() {
    return compare_cnt_insertion;
}

int insertionMoveCount() {
    return datamove_cnt_insertion;
}