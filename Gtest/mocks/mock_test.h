#pragma once
#include "../HW_32/my_class.h"

class MockDBC : public DBConnection {
public:
    MOCK_METHOD(int, execQuery, (int x), (override));
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(void, close, (), (override));
};