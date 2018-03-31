//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Ball.h"

Ball::Ball(int i, double d, double d1) : MovableObject(i, d, d1) {
    radius = 0.5;
}

void Ball::move(){
    if(x < 0 ){
        dx = abs(dx)/2;
        dy = dy/2;
    }
    if(x >100){
        dx = -abs(dx)/2;
        dy = dy/2;
    }
    if(y<0){
        dy = abs(dy) /2;
        dx = dx/2;
    }
    if(y>100){
        dy = -abs(dy) /2;
        dx = dx/2;
    }
    MovableObject::move( dx,  dy);
}

void Ball::kick(double xx, double yy) {
    velocity = MovableObject::fRand(0.5, 1);
    double diffX = (xx - x);
    double diffY = (yy - y);
    double distance = sqrt(diffX*diffX + diffY*diffY);
    if(distance < 0.1) return;
    int signX = diffX > 0 ? 1 : -1;
    int signY = diffY > 0 ? 1 : -1;
    double angleX = diffX/distance;
    double angleY = diffY/distance;
    dx = signX*sqrt(velocity * velocity * angleX * angleX);
    dy = signY *sqrt(velocity * velocity * angleY * angleY);

}

void Ball::moveWithPlayer(MovableObject *bot){
    velocity = bot->getVelocity();
    dx =bot->getDx();
    dy =bot->getDy();
}

