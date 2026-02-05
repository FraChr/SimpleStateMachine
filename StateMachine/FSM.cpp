#include "FSM.h"

State FSM::GetState() const {
    return _currentState;
}

void FSM::HandleEvents(const Event &event) {
    if (event == Event::EmergencyStop) {
        _currentState = State::SHUTDOWN;
        return;
    }

    switch (_currentState) {
        case State::INIT:
            if (event == Event::Activate) _currentState = State::ACTIVE;
            break;
        case State::ACTIVE:
            if (event == Event::SensorFailure) _currentState = State::FAULT;
            break;
        case State::FAULT:
            _currentState = State::SHUTDOWN;
            break;
        case State::SHUTDOWN:
            break;
        default:
            _currentState = State::SHUTDOWN;
            break;
    }
}

