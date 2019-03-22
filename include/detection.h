#ifndef _ELMA_STOP_WATCH_H
#define _ELMA_STOP_WATCH_H

#include "elma/elma.h" // Note installation directory for elma

#include "on.h"
#include "off.h"
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
        
        //! Set-up the GPIO pins of the Raspberry Pi 
        void setup();
        
        //! Get the distance in centimeters 
        int getCM();
        
        void searching(double);

        //! Get the time stored by the detection
        high_resolution_clock::duration value();

        //! Get a list of lap times
        const vector<high_resolution_clock::duration>& laps() { return _laps; }
        
        
        private:

        // When overriding the StateMachine class, put state declarations here.
        OnState on;
        OffState off;

        // Other private variables
        bool _running;
        int y = 0;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;
        vector<high_resolution_clock::duration> _laps;

    };

}

#endif
