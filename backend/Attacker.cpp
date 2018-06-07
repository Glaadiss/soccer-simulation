//
// Created by Bartłomiej Gładys on 04/06/2018.
//

#include "Attacker.h"

void Attacker::playWithBall(Ball &ball, Bot friendFromTeam){
    double choice = MovableObject::fRand(0, 1);
    if(choice < 0.3 && id != friendFromTeam.getId()){
        ball.kick(friendFromTeam.getX(),friendFromTeam.getY(), friendFromTeam.getId());
    }
    else if(choice >= 0.4 && choice < 0.9){
        attack();
        ball.moveWithPlayer(this);
    }
    else if(abs(enemyGoalX - x) < 35 ){
        ball.kick(enemyGoalX, MovableObject::fRand(45, 55), id);
    }
}

void Attacker::setOffensiveTactic(){
    int xFactor = origX > 50 ? -1 : 1;
    bool xCondition = abs(origX - x) < maxX;
    if (xCondition) {
        dx = xFactor * fRand(0.05, 0.1);
    }
    else
        dx= 0;

    int yFactor = origY < 50 ? -1 : 1;
    bool yCondition = abs(origY - y) < maxY;
    if (yCondition) {
        dy = yFactor * fRand(0.05, 0.1);
    }
    else
        dy= 0;
}

void Attacker::attack(){
    double xx = origX > 50 ? 15 : 85;
    double yy = fRand(20, 80);
    approach(xx, yy);
}