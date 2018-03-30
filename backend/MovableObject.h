//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_MOVABLEOBJECT_H
#define BACKEND_MOVABLEOBJECT_H
#include <sstream>
#include "string"

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
    void move(double dx, double dy);
};


#endif //BACKEND_MOVABLEOBJECT_H
