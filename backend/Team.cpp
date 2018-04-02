//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Team.h"

int indexofSmallestElement(double array[], int size)
{
    int index = 0;
    for(int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;
    }
    return index;
}

Bot* Team::locatePlayer(int idd, double xx, double y){
    double x = leftField ? xx : 100 - xx;
    Bot *player = new Bot(leftField ? idd : idd + 11, x, y);
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
    Bot *closestPlayer= findBallClosest(ball);
    Bot *botWithBall = getBotWithBall(ball);
    Bot *randomBot = players[rand() % 11];
    for (auto &&player: players) {
        player->setDirection(ball,
                             player == closestPlayer,
                             *randomBot,
                             botWithBall != nullptr);
        player->move(ball);
    }
}


Bot * Team::getBotWithBall(Ball &ball){
    Bot * bot = nullptr;
    int i =0;
    while(i < 11 && bot == nullptr){
        bool cond = players[i]->isCollision(ball) || players[i]->getId() == ball.getKickedById();
        bot =  cond ? players[i] : nullptr;
        ++i;
    }
    return bot;
}

Bot* Team::findBallClosest(Ball &ball){
    double tempMinArray[11];
    for (int i = 0; i < 11; ++i) {
        tempMinArray[i] = players[i]->getDistance(ball);
    }
    int index = indexofSmallestElement(tempMinArray, 11);
    return players[index];
}



