//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Ball.h"

Ball::Ball(int i, double d, double d1) : MovableObject(i, d, d1) {
    radius = 0.5;
}

void Ball::move(){
    if(x < 0 ){
        dx = abs(dx);
    }
    if(x >100){
        dx = -abs(dx);
    }
    if(y<0){
        dy = abs(dy);
    }
    if(y>100){
        dy = -abs(dy);
    }
    dx*=0.98;
    dy*=0.98;
    MovableObject::move( dx,  dy);
}

void Ball::kick(double xx, double yy, int id) {
    if(kickedById == id) return;
    kickedById = id;
    velocity = MovableObject::fRand(1, 1.5);
    approach(xx, yy);
}

void Ball::moveWithPlayer(MovableObject *bot){
    velocity = bot->getVelocity();
    dx =bot->getDx();
    dy =bot->getDy();
}

int Ball::getKickedById() const {
    return kickedById;
}

