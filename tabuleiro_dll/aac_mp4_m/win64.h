#ifdef _M_IA64
#error This source was not tested on Itanium
#endif

#ifdef _M_X64
#define __INT32_OR_INT64 __int64
 #ifdef __GNUC__
 //#warning size of __INT32_OR_INT64 is 8
 #else
 //#pragma message ( "size of __INT32_OR_INT64 is 8" )
 #endif
#else

#define __INT32_OR_INT64 int
 #ifdef __GNUC__
 //#warning size of __INT32_OR_INT64 is 4
 #else
 //#pragma message ( "size of __INT32_OR_INT64 is 4" )
 #endif
#endif 