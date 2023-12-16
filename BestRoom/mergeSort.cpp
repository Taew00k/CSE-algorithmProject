#include "House.h"
#include <vector>

void flip(vector<int> arr, int i) {
    int start = 0;
    while (start < i) {
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

// 가장 큰 요소를 배열의 맨 끝으로 이동시키는 함수
int findMaxIndex(vector<int> arr, int n) {
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// 팬케이크 정렬 함수
void pancakeSort(vector<int> arr) {
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
}