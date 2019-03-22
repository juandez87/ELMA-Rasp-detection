#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "detection.h"

namespace detection {

    using namespace std::chrono;
    using namespace elma;
    using namespace detection;

    //! A user interface for the a Detection object
    class UserInterface : public Process {

        public:

        //! Create a new detection user interface using curses
        //! \param sw A reference to a Detection object
        UserInterface(Detection& sw);

        void init() {}
        void start() {}

        //! Display the time at the given x,y position on the screen
        void show_time(int x, int y, high_resolution_clock::duration d);

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        Detection& _detection;
        bool button = true,
             startkey = true;
        int temp = 0;
        int dis = 0;

    };

}
