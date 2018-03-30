//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_BALL_H
#define BACKEND_BALL_H


#include "MovableObject.h"

class Ball : public MovableObject{
    using MovableObject::MovableObject;
public:
    Ball(int i, double d, double d1);
    void move();
};


#endif //BACKEND_BALL_H
