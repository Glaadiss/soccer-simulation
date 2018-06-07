//
// Created by Bartłomiej Gładys on 04/06/2018.
//

#ifndef BACKEND_DEFFENDER_H
#define BACKEND_DEFFENDER_H
#include "Bot.h"

class Deffender : public Bot{
    using Bot::Bot;
public:
    void setOffensiveTactic();
    void playWithBall(Ball &ball, Bot friendFromTeam);
};


#endif //BACKEND_DEFFENDER_H
