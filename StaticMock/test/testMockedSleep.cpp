#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "MockSleep.h"

namespace hg {

TEST(MockedSleep, NoMock_ThrowsError)
{
	ASSERT_DEATH({ Sleep(1); },
				 ::testing::HasSubstr("Assertion failed: nullptr != *SingletonClass()"));
}

TEST(MockedSleep, ExpectCall_Works)
{
	::testing::StrictMock<test::MockSleep> mockSleep;

	EXPECT_CALL(mockSleep, Sleep(1)).WillOnce(::testing::Return(10));
	ASSERT_EQ(Sleep(1), 10);
}

TEST(MockedSleep, CheckMockSleepIsntCallingActualFunction)
{
	::testing::NiceMock<test::MockSleep> mockSleep;
	ON_CALL(mockSleep, Sleep(::testing::_)).WillByDefault(::testing::Return(0));

	auto now(std::chrono::steady_clock::now());
	ASSERT_EQ(0, Sleep(1));
	ASSERT_EQ(0, Sleep(2));
	ASSERT_EQ(0, Sleep(3));
	ASSERT_EQ(0, Sleep(4));
	auto after(std::chrono::steady_clock::now());

	ASSERT_LT(after - now, std::chrono::seconds(3));
}

} // namespace hg
