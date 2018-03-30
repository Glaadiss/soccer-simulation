//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_BOT_H
#define BACKEND_BOT_H


#include "MovableObject.h"
#include "Seesight.h"
#include <math.h>

class Bot : public MovableObject{
    using MovableObject::MovableObject;
    Seesight seesight;
public:
    Bot(int i, double d, double d1);
    void move();
};


#endif //BACKEND_BOT_H
