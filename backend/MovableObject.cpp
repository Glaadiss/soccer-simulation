//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "MovableObject.h"

MovableObject::MovableObject(int ID, double X, double Y) {
    id = ID;
    x = X;
    y = Y;
}

std::string MovableObject::getPosition() {
    auto strX = std::to_string(x);
    auto strY = std::to_string(y);
    auto strId = std::to_string(id);
    std::stringstream result;
    result << "{x: " << strX << ", y:" << strY << ", id: " << strId << "}";
    return result.str();
}

void MovableObject::move(double dx, double dy){
    x+=dx;
    y+=dy;
}