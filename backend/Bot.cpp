//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Bot.h"

Bot::Bot(int i, double d, double d1) : MovableObject(i, d, d1) {
    radius = 2;
    velocity = MovableObject::fRand(0.05, 0.2);
}

void Bot::setDirection(Ball &ball, bool ballClosest){
    if(ballClosest){
        double ballX = ball.getX();
        double ballY = ball.getY();
        double diffX = ballX - x;
        double diffY = ballY - y;
        double distance = sqrt(diffX*diffX + diffY*diffY);
        int signX = diffX > 0 ? 1 : -1;
        int signY = diffY > 0 ? 1 : -1;
        double angleX = diffX/distance;
        double angleY = diffY/distance;
        dx = signX * sqrt(velocity * velocity * angleX * angleX);
        dy = signY * sqrt(velocity * velocity * angleY * angleY);
    }
    else{
        dx = 0;
        dy =0;
    }

}


void Bot::move(Ball &ball, Bot bots[]){
    if(isCollision(ball)){
        double choice = MovableObject::fRand(0, 1);
        if(choice >= 0 && choice < 0.2){
            Bot bot = bots[rand()%11];
            ball.kick(bot.getX(),bot.getY());
        }
        if(choice >= 0.2 && choice < 0.5){
            ball.moveWithPlayer(this);
        }
    }

    MovableObject::move(dx, dy);
}