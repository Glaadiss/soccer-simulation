//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_MOVABLEOBJECT_H
#define BACKEND_MOVABLEOBJECT_H
#include <sstream>
#include "string"
#include <math.h>

class MovableObject {

protected:
    int radius;
    double velocity;
    double x;
    double y;
    double origX;
    double origY;
    int id;
    double dx;
protected:
    double dy;
public:
    explicit MovableObject(int, double, double);
    double getVelocity() const;
    int getId() const;
    double getDx() const;
    double getDy() const;
    std::string getPosition();
    double getX() const;
    double getY() const;
    double getOrigX();
    double getOrigY();
    void move(double dx, double dy);
    bool isCollision(MovableObject &other);
    static double fRand(double fMin, double fMax);
    double getDistance(MovableObject &other);
    double getDistance(double xx, double yy);
    void approach(double xx, double yy);
    bool operator==(MovableObject &other) const;
    bool operator!=(MovableObject &other) const;

};


#endif //BACKEND_MOVABLEOBJECT_H
