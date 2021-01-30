#pragma once


#ifdef PAT_DEBUG
	#define PAT_ASSERTIONS
#endif

// BIT definis une macro qui renvoie un octet avec un BIT
// mis a 1 a l'emplacement x
#define BIT(x) (1 << x)

#define PAT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
