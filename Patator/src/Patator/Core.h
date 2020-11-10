#pragma once

#ifdef PATATOR_BUILD_DLL
#define PAT_API __declspec(dllexport)
#else
#define PAT_API __declspec(dllimport)
#endif

// BIT definis une macro qui renvoie un octet avec un BIT
// mis a 1 a l'emplacement x
#define BIT(x) (1 << x)
