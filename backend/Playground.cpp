//
// Created by Bartłomiej Gładys on 30.03.2018.
//

#include "Playground.h"

Playground::Playground() {
    setMovableObjects();
    redGoal = std::make_unique<Goal>(3, 45, 55);
    blueGoal = std::make_unique<Goal>(97, 45, 55);
    pointsTable = std::make_unique<PointsTable>();
}

void Playground::setMovableObjects(){
    blueTeam = std::make_unique<Team>(true);
    redTeam = std::make_unique<Team>(false);
    ball = std::make_unique<Ball>(23, 50.0, 50.0);
}

void Playground::play() {
    blueTeam->moveAll(*ball);
    redTeam->moveAll(*ball);
    ball->move();
    checkGoals();
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

void Playground::checkGoals() {
    if(redGoal->waitForBall(*ball)){
        pointsTable->incrementBlueScore();
        setMovableObjects();

    }
    if(blueGoal->waitForBall(*ball)){
        pointsTable->incrementRedScore();
        setMovableObjects();
    }
}
