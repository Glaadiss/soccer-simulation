//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_MOVABLEOBJECT_H
#define BACKEND_MOVABLEOBJECT_H


class MovableObject {
    int id;
    double x;
    double y;
    int radius;
    double velocity;

public:
    MovableObject(int, double, double);
};


#endif //BACKEND_MOVABLEOBJECT_H
