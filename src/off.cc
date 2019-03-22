#include <iostream>
#include <chrono>
#include <vector>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

StopWatch& OffState:: stopwatch() { return (StopWatch&) state_machine(); }

void OffState::exit(const Event& e) {
    if ( e.name() == "start/stop" ) {
        // User started the servo
        stopwatch().begin();
    } else if ( e.name() == "reset" ) {
        // User reset the servo back in start mode
        stopwatch().reset();
    }
}
