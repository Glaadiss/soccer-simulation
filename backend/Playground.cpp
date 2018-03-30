//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Playground.h"

Playground::Playground() {
    blueTeam = new Team(true);
    redTeam = new Team(false);
}

void Playground::play() {
    blueTeam->moveAll();
    redTeam->moveAll();
    blueTeam->displayPlayers();
    blueTeam->displayPlayers();
    std::cout << std::flush;
}