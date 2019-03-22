#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "detection.h"

using namespace std::chrono;
using namespace elma;
using namespace detection;

int main() {

    Manager m;
    Detection detection;
    UserInterface ui(detection);

    m.schedule(ui, 10_ms)
     .schedule(detection, 10_ms)     
     .init()
     .run();

    endwin();     
     
}
