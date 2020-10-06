#pragma once

#if defined(__MACH__)
#define ENTRY(x) .text; .align 4,0x90;.globl _##x; _##x
#else
#define ENTRY(x) .text; .globl x; .type x,@function; x
#endif

