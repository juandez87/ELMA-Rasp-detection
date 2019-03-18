#ifndef _ELMA_DETECTION_ON_H
#define _ELMA_DETECTION_ON_H

#include "detection.h"

namespace detection {

    using namespace std::chrono;
    using namespace elma;

    class Detection;  // Declare containing class so it can be refered to here
                      // before it is defined in Detection.h 

    //! The on state of the Detection
    class SearchState : public State {        

        public:
        //! Build a new on state
        SearchState() : State("search") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from off to on
        //! \param e The event that triggered the transition        
        void exit(const Event&);

        Detection& detection();        

    };

}

#endif