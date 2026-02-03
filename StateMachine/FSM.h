#pragma once
#include "Events.h"
#include "States.h"

class FSM {
    public:
        FSM() : _currentState(INIT) { }

        State GetState();
        void HandleEvents(const Event &event);
    private:
        State _currentState;
};
