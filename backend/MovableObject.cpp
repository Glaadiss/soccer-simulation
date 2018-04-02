//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "MovableObject.h"

MovableObject::MovableObject(int ID, double X, double Y) {
    id = ID;
    x = X;
    y = Y;
    origX = X;
    origY = Y;
}

std::string MovableObject::getPosition() {
    auto strX = std::to_string(x);
    auto strY = std::to_string(y);
    auto strId = std::to_string(id);
    std::stringstream result;
    result << "\"" << strId << "\"" <<":{\"x\":" << strX << ",\"y\":" << strY << "}";
    return result.str();
}

double MovableObject::getX() const{
    return x;
}

double MovableObject::getY() const{
    return y;
}

double MovableObject::getOrigX(){
    return origX;
}

double MovableObject::getOrigY(){
    return origY;
}

double MovableObject::getDistance(MovableObject &other){
    double xDiff = x - other.getX();
    double yDiff = y - other.getY();
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}

double MovableObject::getDistance(double xx, double yy){
    double xDiff = x - xx;
    double yDiff = y - yy;
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

void MovableObject::approach(double xx, double yy){
    double diffX = (xx - x);
    double diffY = (yy -y);
    double distance = sqrt(diffX*diffX + diffY*diffY);
    if(distance<0.1) return;
    int signX = diffX >= 0 ? 1 : -1;
    int signY = diffY >= 0 ? 1 : -1;
    double angleX = diffX/distance;
    double angleY = diffY/distance;
    dx = signX*sqrt(velocity * velocity * angleX * angleX);
    dy = signY*sqrt(velocity * velocity * angleY * angleY);
}

bool MovableObject::operator==(MovableObject &other) const {
    return getId() == other.getId();
}

bool MovableObject::operator!=(MovableObject &other) const {
    return getId() != other.getId();
}