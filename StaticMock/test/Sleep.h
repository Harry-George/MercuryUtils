/*
 * Wrapper around sleep to allow mocking
 */

#pragma once

#include <unistd.h>

namespace hg {

unsigned int Sleep(unsigned int seconds);

} // namespace hg
