#include "Sleep.h"

namespace hg {

unsigned int Sleep(unsigned int seconds)
{
	return ::sleep(seconds);
}

} // namespace hg
