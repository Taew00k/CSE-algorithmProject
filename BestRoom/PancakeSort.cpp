#include "House.h"
#include <vector>
#include "PancakeSort.h"
#include <iostream>

int compare_cnt_pan = 0;
int datamove_cnt_pan = 0;

void flip(vector<House>& arr, int i) {
    int start = 0;
    while (start < i) {
        if (++datamove_cnt_pan && ++datamove_cnt_pan && ++datamove_cnt_pan && arr[start].totalScore < arr[i].totalScore) {
            swap(arr[start], arr[i]);
        }
        start++;
        i--;
    }
}

int findMaxIndex(vector<House>& arr, int n) {
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (++compare_cnt_pan && arr[i].totalScore > arr[maxIdx].totalScore) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

vector<House> pancakeSort(vector<House>& arr) {
    int n = arr.size();

    compare_cnt_pan = 0;
    datamove_cnt_pan = 0;

    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);

        if (maxIndex != currSize - 1) {
            flip(arr, maxIndex);

            flip(arr, currSize - 1);
        }
    }
    return arr;
}

int pancakeCompareCount() {
    return compare_cnt_pan;
}

int pancakeMoveCount() {
    return datamove_cnt_pan;
}