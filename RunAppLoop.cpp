#include "RunAppLoop.h"
#include <chrono>
#include <iostream>
#include "StateMachine/FSM.h"
#include "StateMachine/States.h"

void RunAppLoop::Run() {
    FSM fsm;
    Event event;

    auto next = std::chrono::high_resolution_clock::now();
    const auto interval = std::chrono::seconds(2);

    event = Event::Activate;
    fsm.HandleEvents(event);

    int failureCounter = 0;
    constexpr int maxUnresolvedFailCount = 3;

    while (fsm.GetState() == State::ACTIVE || fsm.GetState() == State::FAULT) {
        std::cout << "Fail Count: " << failureCounter << std::endl;

        if (failureCounter == maxUnresolvedFailCount) {
            event = Event::EmergencyStop;
            fsm.HandleEvents(event);
        }

        char input;
        std::cin.get(input);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input == 'q') {
            event = Event::EmergencyStop;
            fsm.HandleEvents(event);

        }
        else if (input == 'e') {
            event = Event::SensorFailure;
            fsm.HandleEvents(event);
        }

        if (fsm.GetState() == State::FAULT) {
            std::cerr << "ERROR: SENSOR FAILURE\n";
            failureCounter++;
        }

        auto now = std::chrono::high_resolution_clock::now();

        if (now > next) {
            std::cout << "Application Event: " << event << std::endl;
            next = now + interval;
        }

    }
}