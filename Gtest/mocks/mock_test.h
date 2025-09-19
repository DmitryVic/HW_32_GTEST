#pragma once
#include "../HW_32/my_class.h"

class MockZavisim : public zavisim {
public:
    MOCK_METHOD(int, kv, (int x), (override));
};