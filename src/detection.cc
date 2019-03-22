#include <chrono>
#include <vector>

#include "detection.h"
#include <wiringPi.h>
#include <softPwm.h>

// Pins definition
#define TRIG 7
#define ECHO 0
#define	RED 	1
#define	BLUE	3
#define	GREEN	2
#define PWM 4

//#include "user_interface.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;


StopWatch::StopWatch() : StateMachine("stopwatch") {

    // Define state machine initial states and transitions here
    set_initial(off);
    set_propagate(false);
    add_transition("start/stop", off, on);
    add_transition("reset", off, off);            
    add_transition("start/stop", on, off);

    // Make sure we start in the right condition
    // OUTPUT
    setup();
    reset();
}

high_resolution_clock::duration StopWatch::value() {
    if ( current().name() == "on" ) {
        return high_resolution_clock::now() - _start_time + _elapsed;
    } else {
        return _elapsed;
    }
}

void StopWatch::begin() {
    _start_time = high_resolution_clock::now();
    digitalWrite (GREEN, HIGH);
    digitalWrite (RED, LOW);
}

void StopWatch::reset() {
    _elapsed = high_resolution_clock::duration::zero();
    _laps.clear();
    digitalWrite (GREEN, LOW);
    digitalWrite (RED, LOW);
}

void StopWatch::stop() { 
    _elapsed += high_resolution_clock::now() - _start_time;
    digitalWrite (GREEN, LOW);
    digitalWrite (RED, HIGH);
    
}

void StopWatch::setup() {
        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
        pinMode (BLUE, OUTPUT) ;
        pinMode (GREEN, OUTPUT) ;
        pinMode (RED, OUTPUT) ;
        pinMode(PWM, PWM_OUTPUT);
        digitalWrite(PWM, 0);
        softPwmCreate(PWM, 0, 200);
        softPwmWrite (PWM, 9);
 
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);
        delay(30);
        
}

int StopWatch::getCM() {
    //delay(500);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    int i=0;
    //Wait for echo start
    while(digitalRead(ECHO) == LOW);

    //Wait for echo end
    long startTime = micros();
    while(digitalRead(ECHO) == HIGH);
    long travelTime = micros() - startTime;

    //Get distance in cm
    int distance = travelTime / 58;
    delay(500);
    return distance;
}

void StopWatch::searching(double x) {
    softPwmWrite (PWM, x);
}
