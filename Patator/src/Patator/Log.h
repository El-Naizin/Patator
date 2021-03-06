#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace pat {

	class Log
	{
	public:
		static void init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core logger
#define PAT_CORE_TRACE(...)     ::pat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PAT_CORE_INFO(...)      ::pat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PAT_CORE_WARN(...)      ::pat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PAT_CORE_ERROR(...)     ::pat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PAT_CORE_FATAL(...)     ::pat::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logger
#define PAT_TRACE(...)   ::pat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PAT_INFO(...)    ::pat::Log::GetClientLogger()->info(__VA_ARGS__)
#define PAT_WARN(...)    ::pat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PAT_ERROR(...)   ::pat::Log::GetClientLogger()->error(__VA_ARGS__)
#define PAT_FATAL(...)   ::pat::Log::GetClientLogger()->fatal(__VA_ARGS__)

#ifdef PAT_ASSERTIONS
	#define PAT_ASSERT(x, ...) { if(!(x)) { PAT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PAT_CORE_ASSERT(x, ...) { if(!(x)) { PAT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PAT_ASSERT(x, ...)
	#define PAT_CORE_ASSERT(x, ...)
#endif

