#include "House.h"
#include <vector>
#include "PancakeSort.h"
int compare_Cnt_pan = 0;
int move_Cnt_pan = 0;

void flip(vector<House>& arr, int i) {
    int start = 0;
    while (start < i) {
        move_Cnt_pan = move_Cnt_pan + 3;
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

// 가장 큰 요소를 배열의 맨 끝으로 이동시키는 함수
int findMaxIndex(vector<House>& arr, int n) {
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].totalScore > arr[maxIdx].totalScore && compare_Cnt_pan++) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// 팬케이크 정렬 함수
vector<House> pancakeSort(vector<House>& arr) {
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);

        if (maxIndex != currSize - 1) {
            // 현재 크기의 가장 큰 요소를 맨 끝으로 이동
            flip(arr, maxIndex);

            // 현재 크기를 배열의 맨 끝으로 이동
            flip(arr, currSize - 1);
        }
    }
    return arr;
}