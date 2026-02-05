#include "Events.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Event& event) {

    switch (event) {
        case Event::Activate:       return os << "Activate";
        case Event::SensorFailure:  return os << "SensorFailure";
        case Event::EmergencyStop:  return os << "EmergencyStop";
        default:                    return os << "Unknown Event";
    }
}
