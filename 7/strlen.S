#include "asm.h"

/*
 * extern size_t your_strlen(const char *);
 *
 * You are only allowed to use the following instructions:
 *   cmp
 *   jg
 *   jz
 *   je
 *   jne
 *   jge
 *   inc
 *   dec
 *   xor
 *   mov
 *   add
 *   jl
 *   jle
 */
ENTRY(your_strlen):
	xor %rax, %rax
	movb (%rdi), %cl
	cmpb $0, %cl
	je strlen_EndLoopBody
	strlen_BeginLoopBody:
	inc %rdi
	inc %rax
	movb (%rdi), %cl
	cmpb $0, %cl
	jne strlen_BeginLoopBody
	strlen_EndLoopBody:
	ret
