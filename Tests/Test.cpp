#include "Test.h"

#include "../StateMachine/FSM.h"

bool Test::TestInitToActive() {
    FSM fsm;
    constexpr Event event = Event::Activate;
    fsm.HandleEvents(event);
    return fsm.GetState() == State::ACTIVE;
}

bool Test::TestActiveToFailure() {
    FSM fsm;
    constexpr Event eventStart = Event::Activate;
    fsm.HandleEvents(eventStart);

    constexpr Event eventFailure = Event::SensorFailure;
    fsm.HandleEvents(eventFailure);
    return fsm.GetState() == State::FAULT;
}

bool Test::TestEmergencyShutdown() {
    FSM fsm;
    constexpr Event event = Event::EmergencyStop;
    fsm.HandleEvents(event);
    return fsm.GetState() == State::SHUTDOWN;
}
