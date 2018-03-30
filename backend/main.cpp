#include <iostream>
#include "Playground.h"
#include <unistd.h>


int main() {
    Playground playground;
    unsigned int microseconds = 32000;
    while(true){
        usleep(microseconds);
        playground.play();
    }
    return 1;
}