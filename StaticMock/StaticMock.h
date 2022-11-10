/*--------------------------------------------------------------------------------------------------
 *
 * StaticMock.h
 *     Used for replacing calls to a class or function with a mock at link time.
 *     Allows you to mock out calls you wouldn't want to use other methods to mock out e.g sleep.
 *     For examples see readme and tests.
 *
 * Copyright (c) Harry George 2022
 *
 *--------------------------------------------------------------------------------------------------
 */

#pragma once

#include <cassert>

namespace hg {

template <class T>
class StaticMock {
public:
	StaticMock()
	{
		// There shouldn't be multiple instances of this at the same time
		assert(nullptr == *SingletonClass());
		// Set our instance of the mock to the singleton
		*SingletonClass() = static_cast<T *>(this);
	}

	~StaticMock()
	{
		assert(nullptr != *SingletonClass());
		*SingletonClass() = nullptr;
	}

	/**
         * Gets the current instance of the global singleton
         * @return The global singleton
         */
	static T &GetInstance()
	{
		assert(nullptr != *SingletonClass());
		return **SingletonClass();
	}

private:
	static T **SingletonClass()
	{
		static T *instance(nullptr);
		return &instance;
	}
};

} // namespace hg
