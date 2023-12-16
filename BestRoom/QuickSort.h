//
// Created by 허은정 on 12/17/23.
//
#include <iostream>
#include <vector>
#include "House.h"
using namespace std;
typedef House itemType;

#ifndef CSE_ALGORITHMPROJECT_QUICKSORT_H
#define CSE_ALGORITHMPROJECT_QUICKSORT_H

void swap(vector<itemType> a, int i, int j);
int partition(vector<itemType> a, int l, int r);
vector<House> quicksort(vector<itemType> a, int l, int r);

#endif //CSE_ALGORITHMPROJECT_QUICKSORT_H
