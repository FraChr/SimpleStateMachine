#include <iostream>

#include "RunAppLoop.h"
#include "Tests/RunTests.h"

int main() {

    try {
        RunTests testApp;
        testApp.ExecuteTests();
        /*RunAppLoop app;
        app.Run();*/
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }

    return 0;
}
