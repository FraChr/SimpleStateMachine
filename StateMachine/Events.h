#include <iosfwd>

enum class Event {
    Activate,
    SensorFailure,
    EmergencyStop,
};

std::ostream& operator<<(std::ostream& os, const Event& event);
