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
    result << "\"" << strId << "\"" <<":{\"x\":" << strX << ",\"y\":" << strY << "}";
    return result.str();
}

double MovableObject::getX(){
    return x;
}

double MovableObject::getY(){
    return y;
}

double MovableObject::getDistance(MovableObject &other){
    double xDiff = x - other.getX();
    double yDiff = y - other.getY();
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}


bool MovableObject::isCollision(MovableObject &other){
    bool nearX = abs(other.getX() - x) < radius;
    bool nearY = abs(other.getY() - y) < radius;
    return nearX && nearY;
}

void MovableObject::move(double dx, double dy){
    x+=dx;
    y+=dy;
}

double MovableObject::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double MovableObject::getVelocity() const {
    return velocity;
}

int MovableObject::getId() const {
    return id;
}

double MovableObject::getDx() const {
    return dx;
}

double MovableObject::getDy() const {
    return dy;
}
