//
// Created by Bartłomiej Gładys on 04/06/2018.
//

#ifndef BACKEND_ATTACKER_H
#define BACKEND_ATTACKER_H
#include "Bot.h"

class Attacker : public Bot{
    using Bot::Bot;
public:
    void setOffensiveTactic();
    void playWithBall(Ball &ball, Bot friendFromTeam);
    void attack();
};


#endif //BACKEND_ATTACKER_H
