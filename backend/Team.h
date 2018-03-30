//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_TEAM_H
#define BACKEND_TEAM_H


#include "Bot.h"
#include "RealPlayer.h"
#include "iostream"
#include "Ball.h"
class Team {
    bool leftField;
    Bot *players[11];
    RealPlayer *realPlayer;
public:
    Team(bool);
    Bot* locatePlayer(int id, double x, double y);
    void displayPlayers();
    void moveAll(Ball &ball);
};


#endif //BACKEND_TEAM_H
