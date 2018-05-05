//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_POINTSTABLE_H
#define BACKEND_POINTSTABLE_H
#include "string"
#include <sstream>


class PointsTable {
    int redScore;
    int blueScore;
public:
    PointsTable();
    void incrementRedScore();
    void incrementBlueScore();
    std::string displayScores();
};



#endif //BACKEND_POINTSTABLE_H
