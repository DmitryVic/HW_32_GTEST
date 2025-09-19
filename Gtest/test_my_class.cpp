#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mocks/mock_test.h" 
#include "../HW_32/my_class.h" 

using ::testing::Return;
using ::testing::AtLeast;

TEST(ChatBotStat, UsesMock) {
    auto* mockDBC = new MockDBC();

    EXPECT_CALL(*mockDBC, execQuery(10)).Times(AtLeast(1)).WillOnce(Return(100));
    EXPECT_CALL(*mockDBC, open()).Times(AtLeast(1)).WillOnce(Return(true));
    EXPECT_CALL(*mockDBC, close()).Times(0); 

    ChatBotStat testObj(mockDBC);

    auto open = testObj.openConnection();
    EXPECT_EQ(open, true);

    auto result = testObj.useConnection(10);
    EXPECT_EQ(result, 100);

    auto cl = testObj.closeConnection();
    EXPECT_EQ(cl, true);
    
    delete mockDBC;
}


TEST(ChatBotStat, UsesReal) {
    DBConnectionMySQL realDBC;
    ChatBotStat testObj(&realDBC);

    auto result = testObj.useConnection(5);
    ASSERT_EQ(result, 25); 

}

TEST(ChatBotStat, UsesRea2) {
    DBConnectionMySQL realDBC;
    ChatBotStat testObj(&realDBC);

    auto open = testObj.openConnection();
    ASSERT_EQ(open, true);
}

TEST(ChatBotStat, UsesRea3) {
    DBConnectionMySQL realDBC;
    ChatBotStat testObj(&realDBC);

    auto cl = testObj.closeConnection();
    EXPECT_EQ(cl, true);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}