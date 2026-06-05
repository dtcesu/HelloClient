#pragma once
#include "pch.h"

namespace offsets {
	inline uint64_t ImageBase = uint64_t(GetModuleHandle(nullptr));

	inline uint64_t FCommandLineGet = ImageBase + 0x647C10;
	inline uint64_t ReadyToStartMatch = ImageBase + 0x13A2CE0;
}