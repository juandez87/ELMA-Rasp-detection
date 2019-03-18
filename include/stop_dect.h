#ifndef _ELMA_STOP_DECT_H
#define _ELMA_STOP_DECT_H

#include "detection.h"

namespace Detection {

    using namespace std::chrono;
    using namespace elma;

    class Detection; // Declare containing class so it can be refered to here
                     // before it is defined in Detection.h

    //! A State class to represen the state in which the Detection is off
    class StopState : public State {

        public:
        //! Construct a new stop_op state
        StopState() : State("stop_op") {}
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