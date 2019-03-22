#include <iostream>
#include <chrono>
#include <vector>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace detection;

Detection& OffState:: detection() { return (Detection&) state_machine(); }

void OffState::exit(const Event& e) {
    if ( e.name() == "start/stop" ) {
        // User started the servo
        detection().begin();
    } else if ( e.name() == "reset" ) {
        // User reset the servo back in start mode
        detection().reset();
    }
}
