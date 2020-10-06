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
	BEGINLOOPSTRLEN:
	movb (%rdi), %cl
	cmpb $0, %cl
	je ENDLOOPSTRLEN
	inc %rdi
	inc %rax
	jmp BEGINLOOPSTRLEN
	ENDLOOPSTRLEN:
	ret
