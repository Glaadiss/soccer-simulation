//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Bot.h"
Bot::Bot(int i, double d, double d1) : MovableObject(i, d, d1) {
    maxX = d + MovableObject::fRand(5, 10);
    maxY = d1 + MovableObject::fRand(5, 10);
    radius = 2;
    velocity = MovableObject::fRand(0.2, 0.5);
}

void Bot::setDirection(Ball &ball, bool ballClosest, Bot randomBot, bool teamHasBall){

    if(isCollision(ball)){
        double choice = MovableObject::fRand(0, 1);
        if(choice >= 0 && choice < 0.7 && id != randomBot.getId()){
            ball.kick(randomBot.getX(),randomBot.getY(), randomBot.getId());
        }
        else if(choice >= 0.7 && choice < 1){
            ball.moveWithPlayer(this);
        }
    }
    if(ballClosest){
        double ballX = ball.getX();
        double ballY = ball.getY();
        double diffX = ballX - x;
        double diffY = ballY - y;
        double distance = sqrt(diffX*diffX + diffY*diffY);
        if(distance<0.1) return;
        int signX = diffX > 0 ? 1 : -1;
        int signY = diffY > 0 ? 1 : -1;
        double angleX = diffX/distance;
        double angleY = diffY/distance;
        dx = signX * sqrt(velocity * velocity * angleX * angleX);
        dy = signY * sqrt(velocity * velocity * angleY * angleY);
    }
   else if(teamHasBall) {

        int xFactor = origX > 50 ? -1 : 1;
        bool xCondition = origX > 50 ? x > 100 - maxX : x < maxX;
        if (xCondition) {
            dx = xFactor * fRand(0.01, 0.05);
        }
        else
            dx= 0;

        int yFactor = origY < 50 ? -1 : 1;
        bool yCondition = origY > 50 ? y > 100 - maxY : y < maxY;
        if (yCondition) {
            dy = yFactor * fRand(0.01, 0.05);
        }
        else
            dy= 0;

    }
    else{
        if(ball.getX() > x && x < maxX){
            dx = fRand(0.01, 0.05);
        }
        else if(ball.getX() < x && x > 100 - maxX){
            dx = -fRand(0.01, 0.05);
        }
        else
            dx = 0;

        if(ball.getY() > y && y < maxY){
            dy = fRand(0.01, 0.05);
        }
        else if(ball.getY() < y && y > 100 - maxY){
            dy = -fRand(0.01, 0.05);
        }
        else
            dy =0;
    }

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
