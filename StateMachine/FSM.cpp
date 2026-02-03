#include "FSM.h"

State FSM::GetState() {
    return _currentState;
}

void FSM::HandleEvents(const Event &event) {
    if (event.EmergencyShutdown) {
        _currentState = SHUTDOWN;
        return;
    }

    switch (_currentState) {
        case INIT:
            if (event.Active) _currentState = ACTIVE;
            break;
        case ACTIVE:
            if (event.SensorFailure) _currentState = FAULT;
            break;
        case FAULT:
            _currentState = SHUTDOWN;
            break;
        case SHUTDOWN:
            break;
    }
}
