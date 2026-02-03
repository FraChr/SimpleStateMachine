#include "Test.h"

#include "../StateMachine/FSM.h"

bool Test::TestInitToActive() {
    FSM fsm;
    Event event;
    event.Active = true;
    fsm.HandleEvents(event);
    return fsm.GetState() == ACTIVE;
}

bool Test::TestActiveToFailure() {
    FSM fsm;
    Event eventStart;
    eventStart.Active = true;
    fsm.HandleEvents(eventStart);

    Event eventFailure;
    eventFailure.SensorFailure = true;
    fsm.HandleEvents(eventFailure);
    return fsm.GetState() == FAULT;
}

bool Test::TestEmergencyShutdown() {
    FSM fsm;
    Event event;
    event.EmergencyShutdown = true;
    fsm.HandleEvents(event);
    return fsm.GetState() == SHUTDOWN;
}
