
#pragma once

#include "Sleep.h"
#include <StaticMock/StaticMock.h>

#include <gmock/gmock.h>

namespace hg::test {

// Create the static mock
class MockSleep : public StaticMock<MockSleep> {
public:
	MOCK_METHOD(unsigned int, Sleep, (unsigned int));
};

} // namespace hg::test

namespace hg {

// Create definitions of all the functions in sleep.cpp, this will prevent sleep.cpp definitions
// being pulled in
auto Sleep(unsigned int seconds) -> unsigned int
{
	return test::MockSleep::GetInstance().Sleep(seconds);
}

} // namespace hg