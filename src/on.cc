#include <iostream>
#include <chrono>
#include <vector>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

StopWatch&OnState:: stopwatch() { return (StopWatch&) state_machine(); }

void OnState::exit(const Event& e) {
    if ( e.name() == "start/stop") {
        // User stopped the servo
        stopwatch().stop();
    } 
}
