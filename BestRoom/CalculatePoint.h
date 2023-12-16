#ifndef CSE_ALGORITHMPROJECT_CALCULATEPOINT_H
#define CSE_ALGORITHMPROJECT_CALCULATEPOINT_H

// CalculatePoint.h
#include <vector>
#include <limits>
#include "House.h"

//최솟값과 최댓값을 저장하는 구조체
struct MinMax {
    float min;
    float max;
};

MinMax findMinMax(std::vector<House> houses, int House::* feature);

// 각 속성에 대한 최소값, 최대값, 가중치를 인자로 받아서 점수 계산
std::vector<House> calculateScores(std::vector<House> houses, int monthlyWeight, int depositWeight, int distanceWeight, int sizeWeight);

#endif //CSE_ALGORITHMPROJECT_CALCULATEPOINT_H
