//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_BOT_H
#define BACKEND_BOT_H


#include "MovableObject.h"
#include "Seesight.h"

class Bot : public MovableObject{
    Seesight seesight;
};


#endif //BACKEND_BOT_H
