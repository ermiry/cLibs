#ifndef _CLIBS_TYPES_H_
#define _CLIBS_TYPES_H_

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef unsigned char uchar;
typedef unsigned char ascii_char;

// takes no argument and returns a value (int)
typedef u8 (*Func)(void);

// takes an argument and does not return a value
typedef void (*Action)(void *);

// takes an argument and returns a value (int)
typedef u8 (*delegate)(void *);

// takes an argument and returns a value generic value ptr
typedef void *(*Work)(void *);

typedef int (*Comparator)(const void *, const void *);

#endif