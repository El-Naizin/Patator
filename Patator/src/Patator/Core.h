#pragma once

#ifdef PATATOR_BUILD_DLL
#define PAT_API __declspec(dllexport)
#else
#define PAT_API __declspec(dllimport)
#endif
