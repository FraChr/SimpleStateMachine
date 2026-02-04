#include "FSM.h"

State FSM::GetState() const {
    return _currentState;
}

void FSM::HandleEvents(const Event &event) {
    if (event == EmergencyStop) {
        _currentState = SHUTDOWN;
        return;
    }

    switch (_currentState) {
        case INIT:
            if (event == Activate) _currentState = ACTIVE;
            break;
        case ACTIVE:
            if (event == SensorFailure) _currentState = FAULT;
            break;
        case FAULT:
            _currentState = SHUTDOWN;
            break;
        case SHUTDOWN:
            break;
        default:
            _currentState = SHUTDOWN;
            break;
    }
}

