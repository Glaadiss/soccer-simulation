//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_GOAL_H
#define BACKEND_GOAL_H
#include "Ball.h"
class Goal {
public:
    double getX() const;

    double getYTop() const;

    double getYBot() const;

    Goal(double x1, double y1, double y2);

    bool waitForBall(Ball &ball);

private:
    double x;
    double yTop;
    double yBot;
};


#endif //BACKEND_GOAL_H
