//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Goal.h"

double Goal::getX() const {
    return x;
}

double Goal::getYTop() const {
    return yTop;
}

Goal::Goal(double x1, double y1, double y2) {
    x = x1;
    yTop = y1;
    yBot = y2;
}

bool Goal::waitForBall(Ball &ball){
    bool isBallInGoal = abs(ball.getX() - x) < 1
                        && ball.getY() < yBot
                        && ball.getY() > yTop;
    return isBallInGoal;
}

double Goal::getYBot() const {
    return yBot;
}

