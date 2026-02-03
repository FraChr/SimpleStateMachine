#include "RunTests.h"
#include <iostream>

void RunTests::ExecuteTests() {
    int passed = 0;
    for (auto& test : _tests) {
        const bool result = test.Func();
        std::cout << test.testName << '\n';
        if (result) passed++;
    }
    std::cout << "\n" << passed << " / " << std::size(_tests) << " Tests Passed\n";
}
