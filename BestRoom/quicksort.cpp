//
// Created by dlgos on 2023-12-17.
//
#include <iostream>
#include <vector>
using namespace std;
typedef int itemType;

int compare_Cnt = 0;
int dataMove_Cnt = 0;

inline void swap(vector<itemType> a, int i, int j) {
    itemType  t = a.at(i);
    dataMove_Cnt++;
    a.at(i) = a.at(j);
    dataMove_Cnt++;
    a.at(j) = t;
    dataMove_Cnt++;
}

int partition(vector<itemType> a, int l, int r) {
    int i, j; itemType v;
    if (r > l) {
        v = a.at(l);
        i = l;
        j = r + 1;
        // 항상 돌아간다는 뜻
        for (;;) {
            while (++compare_Cnt && a[++i] < v);
            while (++compare_Cnt && a[--j] > v);
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, j, l);
    }
    return j;
}

void quicksort(vector<itemType> a, int l, int r) {
    int  j;
    if (r > l) {
        j = partition(a, l, r);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}