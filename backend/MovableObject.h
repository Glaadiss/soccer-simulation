//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_MOVABLEOBJECT_H
#define BACKEND_MOVABLEOBJECT_H
#include <sstream>
#include "string"
#include <math.h>

class MovableObject {
    int id;

protected:
    int radius;
    double velocity;
    double x;
    double y;
public:
    explicit MovableObject(int, double, double);
    std::string getPosition();
    double getX();
    double getY();
    void move(double dx, double dy);
    bool isCollision(MovableObject &other);
};


#endif //BACKEND_MOVABLEOBJECT_H
