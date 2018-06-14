//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_PLAYGROUND_H
#define BACKEND_PLAYGROUND_H


#include "PointsTable.h"
#include "Team.h"
#include "Goal.h"
#include "Ball.h"
#include <vector>
#include <memory>


class Playground {
    std::unique_ptr<PointsTable> pointsTable;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Team> redTeam;
    std::unique_ptr<Team> blueTeam;
    std::unique_ptr<Goal> redGoal;
    std::unique_ptr<Goal> blueGoal;
public:
    Playground();
    void play();
    void flush();
    void setMovableObjects();
    void checkGoals();
};


#endif //BACKEND_PLAYGROUND_H
