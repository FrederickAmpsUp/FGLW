#pragma once

#include <stdio.h>

#ifndef NDEBUG

// debugging enabled

#define FGLW_DEBUG_PRINTF(...) printf(__VA_ARGS__)

#else

// debugging disabled

#define FGLW_DEBUG_PRINTF(...)


#endif