#pragma once

#include "Events.h"
#include "States.h"

class FSM {
    public:
        FSM() : _currentState(State::INIT) { }

        State GetState() const;
        void HandleEvents(const Event &event);
    private:
        State _currentState;
};
