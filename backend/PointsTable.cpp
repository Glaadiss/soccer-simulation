//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "PointsTable.h"


PointsTable::PointsTable() {
    redScore = 0;
    blueScore = 0;
}

void PointsTable::incrementRedScore() {
    redScore++;
}

void PointsTable::incrementBlueScore() {
    blueScore++;
}

std::string PointsTable::displayScores() {
    auto strRedScore = std::to_string(redScore);
    auto strBlueScore = std::to_string(blueScore);
    std::stringstream result;
    result << "\"" << "scores" << "\"" << ":{\"red\":" << strRedScore << ",\"blue\":" << strBlueScore << "}";
    return result.str();
}

