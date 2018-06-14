//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_BOT_H
#define BACKEND_BOT_H


#include "MovableObject.h"
#include "Ball.h"

class Bot : public MovableObject{
protected:
    using MovableObject::MovableObject;
    double maxX;
    double maxY;
    double enemyGoalX;
public:
    Bot(int i, double d, double d1);
    void move(Ball &ball);
    virtual void setOffensiveTactic();
    virtual void playWithBall(Ball &ball, Bot friendFromTeam);
    void setDirection(Ball &ball, bool ballClosest, Bot bot, bool teamHasBall, bool shouldAttackBall);
};


#endif //BACKEND_BOT_H
