//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#ifndef BACKEND_TEAM_H
#define BACKEND_TEAM_H


#include "Bot.h"
#include "RealPlayer.h"

class Team {
    Bot players[11];
    RealPlayer realPlayer;
public:
    Team(bool);
};


#endif //BACKEND_TEAM_H
