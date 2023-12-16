//
// Created by dlgos on 2023-12-17.
//
#include <iostream>
#include <vector>
using namespace std;
typedef int itemType;


inline void swap(vector<itemType> a, int i, int j) {
    itemType  t = a.at(i);
    a.at(i) = a.at(j);
    a.at(j) = t;
}

int partition(vector<itemType> a, int l, int r) {
    int i, j; itemType v;
    if (r > l) {
        v = a.at(l);
        i = l;
        j = r + 1;
        // 항상 돌아간다는 뜻
        for (;;) {
            while (a[++i] < v);
            while (a[--j] > v);
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