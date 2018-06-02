//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Playground.h"

Playground::Playground() {
    setMovableObjects();
    redGoal = new Goal(3, 45, 55);
    blueGoal = new Goal(97, 45, 55);
    pointsTable = new PointsTable();
}

void Playground::setMovableObjects(){
    blueTeam = new Team(true);
    redTeam = new Team(false);
    ball = new Ball(23, 50.0, 50.0);
}

void Playground::play() {
    blueTeam->moveAll(*ball);
    redTeam->moveAll(*ball);
    ball->move();
    if(redGoal->waitForBall(*ball)){
        pointsTable->incrementBlueScore();
        setMovableObjects();
    }
    if(blueGoal->waitForBall(*ball)){
        pointsTable->incrementRedScore();
        setMovableObjects();
    }
    flush();
}

void Playground::flush() {
    std::cout << "{";
    blueTeam->displayPlayers();
    redTeam->displayPlayers();
    std::cout << ball->getPosition();
    std::cout << ",";
    std::cout << pointsTable->displayScores() << "}" << std::endl;
}