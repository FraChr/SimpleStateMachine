#pragma once
#include <string>

struct TestCase {
    std::string testName;
    bool (*Func)();
};
