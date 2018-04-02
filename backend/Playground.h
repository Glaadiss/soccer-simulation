//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_PLAYGROUND_H
#define BACKEND_PLAYGROUND_H


#include "PointsTable.h"
#include "TimeTable.h"
#include "Team.h"
#include "Goal.h"
#include "Ball.h"
#include <vector>

class Playground {
    PointsTable pointsTable;
    TimeTable timeTable;
    Ball *ball;
    Team *redTeam;
    Team *blueTeam;
    Goal redGoal;
    Goal blueGoal;
public:
    Playground();
    void play();
    void flush();
};


#endif //BACKEND_PLAYGROUND_H
