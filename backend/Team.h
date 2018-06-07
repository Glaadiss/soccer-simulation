//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_TEAM_H
#define BACKEND_TEAM_H

#include "Attacker.h"
#include "Deffender.h"
#include "iostream"
#include "Ball.h"
#include <array>
class Team {
    bool leftField;
    Bot *players[11];
public:
    Team(bool);
    Bot* locatePlayer(int id, double x, double y);
    void displayPlayers();
    void moveAll(Ball &ball);
    Bot* findBallClosest(Ball &ball);
    std::array<Bot *, 11> getBallClosestArr(Ball &ball);
    Bot* getBotWithBall(Ball &ball);

    Bot *getAttacker(Ball &ball);
};


#endif //BACKEND_TEAM_H
