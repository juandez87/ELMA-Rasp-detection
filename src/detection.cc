#include <chrono>
#include <vector>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace detection;

Detection::detection() : StateMachine("detection") {

    // Define state machine initial states and transitions here
    set_initial(stop_op);
    set_propagate(false);
    add_transition("Object/disappear", stop_op, search);
    //add_transition("reset", stop_op, stop_op);            
    add_transition("Object/detected", search, stop_op);
    //add_transition("lap",   search, search);

    // Make sure we start in the right condition
    reset();
}

high_resolution_clock::duration Detection::value() {
    if ( current().name() == "search" ) {
        return high_resolution_clock::now() - _start_time + _elapsed;
    } else {
        return _elapsed;
    }
}

void Detection::begin() {
    _start_time = high_resolution_clock::now();
}

void Detection::reset() {
    _elapsed = high_resolution_clock::duration::zero();
    _laps.clear();
}

void Detection::stop() {
    _elapsed += high_resolution_clock::now() - _start_time;
}

void Detection::lap() {
    _laps.insert(_laps.begin(), value());
}