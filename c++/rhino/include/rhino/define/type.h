//badger
#pragma once

typedef unsigned $U;
typedef int $I;
typedef float $F;
typedef double $D;
typedef string $S;
typedef char $C;
typedef char* $C2;
typedef bool $B;
typedef void $V;

typedef const unsigned $CU;
typedef const int $CI;
typedef const float $CF;
typedef const double $CD;
typedef const string $CS;
typedef const char $CC;
typedef const char* $CC2;
typedef const bool $CB;
typedef const void $CV;

#define $C3 const

#define $DEF_C class
#define $DEF_S struct
#define $DEF_E enum
#define $DEF_U union

#define $DEF_CS const struct
#define $DEF_CE const enum

#define $S2 short
#define $L long
#define $A auto

#define $S3 static
#define $IS inline static

#define $OR override
#define $NE noexcept

#define $TYPE(name) template<typename name>
#define $SET_PTR(type,name,ptr_name) type name,*ptr_name=&name
#define $UI(bit) uint##bit##_t