//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Ball.h"

Ball::Ball(int i, double d, double d1) : MovableObject(i, d, d1) {
    radius = 0.5;
    velocity = 1;
}


void Ball::move(){
    double ballX = 50;
    double ballY = 50;
    double diffX = ballX - x;
    double diffY = ballY - y;
    double distance = sqrt(diffX*diffX + diffY*diffY);
    if(distance < 0.1) return;
    int signX = diffX > 0 ? 1 : -1;
    int signY = diffY > 0 ? 1 : -1;
    double angleX = diffX/distance;
    double angleY = diffY/distance;
    double dx = sqrt(velocity * velocity * angleX * angleX);
    double dy = sqrt(velocity * velocity * angleY * angleY);
    MovableObject::move(signX* dx, signY * dy);
}