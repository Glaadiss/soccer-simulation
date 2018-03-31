#include <iostream>
#include "Playground.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand (time(NULL));
    Playground playground;
    unsigned int microseconds = 32000;
    while(true){
        usleep(microseconds);
        playground.play();
    }
    return 1;
}