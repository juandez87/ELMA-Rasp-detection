#include <iostream>
#include <chrono>
#include <vector>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace detection;

Detection& StopState:: detection() { return (Detection&) state_machine(); }

void StopState::exit(const Event& e) {
    if ( e.name() == "start/stop" ) {
        // User started the Detection
        detection().begin();
    } else if ( e.name() == "reset" ) {
        // User rest the detection
        detection().reset();
    }
}
