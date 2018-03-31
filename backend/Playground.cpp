//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Playground.h"

Playground::Playground() {
    blueTeam = new Team(true);
    redTeam = new Team(false);
    ball = new Ball(23, 40, 40);
}

void Playground::play() {
    blueTeam->moveAll(*ball);
    redTeam->moveAll(*ball);
    ball->move();
    flush();
}

void Playground::flush() {
    std::cout << "{";
    blueTeam->displayPlayers();
    redTeam->displayPlayers();
    std::cout << ball->getPosition() << "}" << std::flush;
}