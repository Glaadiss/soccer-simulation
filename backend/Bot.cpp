//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Bot.h"
Bot::Bot(int i, double d, double d1) : MovableObject(i, d, d1) {
    maxX = MovableObject::fRand(10, 20);
    maxY = MovableObject::fRand(10, 20);
    radius = 1;
    velocity = MovableObject::fRand(0.2, 0.5);
}


void Bot::playWithBall(Ball &ball, Bot friendFromTeam){
    double choice = MovableObject::fRand(0, 1);
    if(choice >= 0 && choice < 0.3 && id != friendFromTeam.getId()){
        ball.kick(friendFromTeam.getX(),friendFromTeam.getY(), friendFromTeam.getId());
    }
    else if(choice >= 0.3 && choice < 1){
        attack();
        ball.moveWithPlayer(this);
    }
}

void Bot::setOffensiveTactic(){
    int xFactor = origX > 50 ? -1 : 1;
    bool xCondition = abs(origX - x) < maxX;
    if (xCondition) {
        dx = xFactor * fRand(0.01, 0.05);
    }
    else
        dx= 0;

    int yFactor = origY < 50 ? -1 : 1;
    bool yCondition = abs(origY - y) < maxY;
    if (yCondition) {
        dy = yFactor * fRand(0.01, 0.05);
    }
    else
        dy= 0;
}

void Bot::setDirection(Ball &ball, bool ballClosest, Bot friendFromTeam, bool teamHasBall, bool shouldAttackBall){

    if(isCollision(ball)){
        playWithBall(ball, friendFromTeam);
    }
    else if(ballClosest || ball.getKickedById() == getId()){
        approach(ball.getX(), ball.getY());
    }
    else if(teamHasBall) {
        setOffensiveTactic();
    }
    else if(shouldAttackBall){
        approach(fRand(ball.getX() -10, ball.getX() + 10),
                 fRand(ball.getY() -10, ball.getY() + 10)
                );
    }
    else if(getDistance(origX, origY) > 3 ) {
        approach(origX, origY);
    }
    else{
        dx =0;
        dy =0;
    }

}

void Bot::attack(){
    double xx = origX > 50 ? 15 : 85;
    double yy = fRand(20, 80);
    approach(xx, yy);
}


void Bot::move(Ball &ball){
    MovableObject::move(dx, dy);
}

double Bot::getMaxX() const {
    return maxX;
}

double Bot::getMaxY() const {
    return maxY;
}
