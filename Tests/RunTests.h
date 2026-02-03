#pragma once
#include "Test.h"
#include "TestCase.h"

class RunTests {
public:
    void ExecuteTests();
private:
    TestCase _tests[3] = {
        {"Init to Active", Test::TestInitToActive},
        {"Active to Failure", Test::TestActiveToFailure},
        {"Emergency Shutdown", Test::TestEmergencyShutdown},
    };
};