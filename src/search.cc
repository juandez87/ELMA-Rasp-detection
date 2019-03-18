#include <iostream>
#include <chrono>
#include <vector>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace detection;

Detection&SearchState:: detection() { return (Detection&) state_machine(); }

void SearchState::exit(const Event& e) {
    if ( e.name() == "start/stop" ) {
        // User stopped the Detection
        detection().stop();
    } else if ( e.name() == "lap" ) {
        // User adds a lap to the detection lap list
        detection().lap();
    }
}
