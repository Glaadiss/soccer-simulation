//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Team.h"


Bot* Team::locatePlayer(int idd, double xx, double y){
    double x = leftField ? xx : 100 - xx;
    Bot *player = new Bot(leftField ? idd : idd + 10, x, y);
    return player;
}

Team::Team(bool LeftField) {
    leftField = LeftField;

    players[0] = locatePlayer(1, 10, 50);

    players[1] = locatePlayer(2, 20, 20);
    players[2] = locatePlayer(3, 20, 40);
    players[3] = locatePlayer(4, 20, 60);
    players[4] = locatePlayer(5, 20, 80);

    players[5] = locatePlayer(6, 30, 20);
    players[6] = locatePlayer(7, 30, 40);
    players[7] = locatePlayer(8, 30, 60);
    players[8] = locatePlayer(9, 30, 80);

    players[9] = locatePlayer(10, 40, 40);
    players[10] = locatePlayer(11, 40, 60);
}

void Team::displayPlayers() {
    for (auto &&item : players) {
        std::cout << item->getPosition() << ",";
    }
}

void Team::moveAll(Ball &ball) {
    for (auto &&item : players) {
        item->move(ball);
    }
}



