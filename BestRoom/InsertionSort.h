#ifndef CSE_ALGORITHMPROJECT_INSERTIONSORT_H
#define CSE_ALGORITHMPROJECT_INSERTIONSORT_H

#include <vector>
#include "House.h"

extern int compare_cnt_insertion;
extern int datamove_cnt_insertion;

void insertionSort(vector<House>& arr, int n);
int insertionCompareCount();
int insertionMoveCount();

#endif //CSE_ALGORITHMPROJECT_INSERTIONSORT_H
