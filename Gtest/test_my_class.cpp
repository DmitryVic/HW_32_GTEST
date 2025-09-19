#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mocks/mock_test.h" 
#include "../HW_32/my_class.h" 

using ::testing::Return;

TEST(test_my_class, UsesMock) {
    // Мокаем зависимость
    MockZavisim mockZav;
    EXPECT_CALL(mockZav, kv(42))
        .WillOnce(Return(100));

    test_my_class testObj(&mockZav);
    auto result = testObj.test(42);
    EXPECT_EQ(result, 100);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}