//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Bot.h"
Bot::Bot(int i, double d, double d1) : MovableObject(i, d, d1) {
    maxX = MovableObject::fRand(10, 20);
    maxY = MovableObject::fRand(10, 20);
    radius = 1;
    velocity = MovableObject::fRand(0.2, 0.5);
    enemyGoalX = d > 50 ? 0 : 100;
}

void Bot::setOffensiveTactic(){
//
}

void Bot::playWithBall(Ball &ball, Bot friendFromTeam){
//
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


void Bot::move(Ball &ball){
    MovableObject::move(dx, dy);
}

