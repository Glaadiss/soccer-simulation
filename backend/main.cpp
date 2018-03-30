#include <iostream>
#include "Playground.h"
#include <unistd.h>


int main() {
    Playground playground;
    unsigned int microseconds = 16000;
    while(true){
        usleep(microseconds);
        playground.play();
    }
    return 1;
}