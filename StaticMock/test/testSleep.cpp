#include <gtest/gtest.h>

#include "Sleep.h"

namespace hg {

TEST(Sleep, Waits)
{
	auto now(std::chrono::steady_clock::now());
	ASSERT_EQ(0, Sleep(1));
	auto after(std::chrono::steady_clock::now());

	ASSERT_GE(after - now, std::chrono::seconds(1));
}

} // namespace hg
