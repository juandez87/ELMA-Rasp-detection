#ifndef _ELMA_DETECTION_H
#define _ELMA_DETECTION_H

#include "elma/elma.h" // Note installation directory for elma

#include "search.h"
#include "stop_dect.h"
#include "user_interface.h"

namespace detection {

    using namespace std::chrono;
    using namespace elma;    

    //! A stop watch class, that inherits from StateMachine
    class Detection : public StateMachine {

        public:
        //! Make a new detection
        Detection();

        //! Start the detection
        void begin();

        //! Reset the detection to zero and erase laps
        void reset();

        //! Stop the detection
        void stop();

        //! Add a lap time to the list of lap times.
        void lap();

        //! Get the time stored by the detection
        high_resolution_clock::duration value();

        //! Get a list of lap times
        const vector<high_resolution_clock::duration>& laps() { return _laps; }

        private:

        // When overriding the StateMachine class, put state declarations here.
        SearchState search;
        StopState stop_op;

        // Other private variables
        bool _running;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;
        vector<high_resolution_clock::duration> _laps;

    };

}

#endif