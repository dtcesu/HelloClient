// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H
#include <stdio.h>
#include <string>

// add headers that you want to pre-compile here
// add headers that you want to pre-compile here
#include "../SDK/Basic.hpp"
#include "../SDK/CoreUObject_structs.hpp"
#include "../SDK/CoreUObject_classes.hpp"
#include "../SDK/Engine_structs.hpp"
#include "../SDK/Engine_classes.hpp"
#include "../SDK/HelloNeighbor_classes.hpp"
#include "../SDK/HelloNeighbor_parameters.hpp"

#include "framework.h"
#include "options.h"
#include "../logger.h"
#include "../offsets.h"
#include "ue.h"
#include "hooks.h"

#include "../include/MinHook.h"
using namespace SDK;
#endif //PCH_H