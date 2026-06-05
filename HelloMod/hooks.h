#pragma once

namespace hooks {
	inline TCHAR* (*FCommandLineGetOG)();
	TCHAR* FCommandLineGet();
	void init();
}