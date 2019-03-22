#ifndef _ELMA_STOP_WATCH_OFF_H
#define _ELMA_STOP_WATCH_OFF_H

#include "detection.h"

namespace detection {

    using namespace std::chrono;
    using namespace elma;

    class Detection; 

    //! A State class to represen the state in which the Servo motor is off
    class OffState : public State {

        public:
        //! Construct a new off state
        OffState() : State("off") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        Detection& detection();

    };

}

#endif