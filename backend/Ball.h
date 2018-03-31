//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_BALL_H
#define BACKEND_BALL_H


#include "MovableObject.h"
#include <algorithm>

class Ball : public MovableObject{
    using MovableObject::MovableObject;
public:
    int kickedById;
    Ball(int i, double d, double d1);
    void kick(double x, double y, int id);
    void move();
    void moveWithPlayer(MovableObject *bot);
};


#endif //BACKEND_BALL_H
