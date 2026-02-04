#include "Test.h"

#include "../StateMachine/FSM.h"

bool Test::TestInitToActive() {
    FSM fsm;
    constexpr Event event = Activate;
    fsm.HandleEvents(event);
    return fsm.GetState() == ACTIVE;
}

bool Test::TestActiveToFailure() {
    FSM fsm;
    constexpr Event eventStart = Activate;
    fsm.HandleEvents(eventStart);

    constexpr Event eventFailure = SensorFailure;
    fsm.HandleEvents(eventFailure);
    return fsm.GetState() == FAULT;
}

bool Test::TestEmergencyShutdown() {
    FSM fsm;
    constexpr Event event = EmergencyStop;
    fsm.HandleEvents(event);
    return fsm.GetState() == SHUTDOWN;
}
