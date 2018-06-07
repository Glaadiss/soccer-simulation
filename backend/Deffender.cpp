//
// Created by Bartłomiej Gładys on 04/06/2018.
//

#include "Deffender.h"

void Deffender::playWithBall(Ball &ball, Bot friendFromTeam){
    double choice = MovableObject::fRand(0, 1);
    if(choice < 0.8 && id != friendFromTeam.getId()){
        ball.kick(friendFromTeam.getX(),friendFromTeam.getY(), friendFromTeam.getId());
    }
    else if(choice >= 0.8 && choice < 0.9){
        ball.moveWithPlayer(this);
    }
}

void Deffender::setOffensiveTactic(){
    approach(origX, origY);
}
