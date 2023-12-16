// CalculatePoint.cpp
#include "House.h"
#include<iostream>
#include <vector>
#include <limits>

using namespace std;
//최솟값과 최댓값을 저장하는 구조체
struct MinMax {
    float min;
    float max;
};

MinMax findMinMax(vector<House> houses, double House::* feature) {
    MinMax result{numeric_limits<float>::max(), numeric_limits<float>::min()};
    for (const auto& house : houses) {
        if (house.*feature < result.min) result.min = house.*feature;
        if (house.*feature > result.max) result.max = house.*feature;
    }
    return result;
}

// 각 속성에 대한 최소값, 최대값, 가중치를 인자로 받아서 점수 계산
vector<House> calculateScores(vector<House> houses, int monthlyWeight, int depositWeight, int distanceWeight, int sizeWeight) {
    MinMax monthlyMM = findMinMax(houses, &House::monthly);
    MinMax depositMM = findMinMax(houses, &House::deposit);
    MinMax distanceMM = findMinMax(houses, &House::distance);
    MinMax sizeMM = findMinMax(houses, &House::size);

    for (auto& house : houses) {
        house.totalScore = ((1 - (house.monthly - monthlyMM.min) / (monthlyMM.max - monthlyMM.min)) * monthlyWeight +
                            (1-(house.deposit - depositMM.min) / (depositMM.max - depositMM.min)) * depositWeight +
                            (1-(house.distance - distanceMM.min) / (distanceMM.max - distanceMM.min)) * distanceWeight +
                            (house.size - sizeMM.min) / (sizeMM.max - sizeMM.min) * sizeWeight);
    }
    return houses;
}



