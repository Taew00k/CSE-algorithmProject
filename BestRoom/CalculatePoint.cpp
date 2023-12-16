// CalculatePoint.cpp
#include "CalculatePoint.h"

MinMax findMinMax(std::vector<House> houses, double House::* feature) {
    MinMax result{std::numeric_limits<float>::max(), std::numeric_limits<float>::min()};
    for (const auto& house : houses) {
        if (house.*feature < result.min) result.min = house.*feature;
        if (house.*feature > result.max) result.max = house.*feature;
    }
    return result;
}

std::vector<House> calculateScores(std::vector<House> houses, int monthlyWeight, int depositWeight, int distanceWeight, int sizeWeight) {
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



