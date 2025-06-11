#ifndef STD_TYPE_H_
#define STD_TYPE_H_

#include <string.h>

/* define C boolean */
#ifndef false
#    define false (0)
#endif
#ifndef true
#    define true (!false)
#endif
#ifndef FALSE
#    define FALSE (0)
#endif
#ifndef TRUE
#    define TRUE (!FALSE)
#endif

/*   TYPE DEFINITIONS   */

typedef signed int sint;
typedef unsigned int uint;
typedef signed char sint8;     //        -128 to +127
typedef unsigned char uint8;   //           0 to 255
typedef signed short sint16;   //      -32768 to +32767
typedef unsigned short uint16; //           0 to 65535
typedef signed long sint32;    // -2147483648 to +2147483647
typedef unsigned long uint32;  //           0 to 4294967295
typedef float real32;
typedef double real64;
typedef unsigned char bool;

#endif /* STD_TYPE_H_ */
