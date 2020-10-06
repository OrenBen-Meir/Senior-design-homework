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
	je STRLEN_ENDLOOPBODY
	STRLEN_BEGINLOOPBODY:
	inc %rdi
	inc %rax
	movb (%rdi), %cl
	cmpb $0, %cl
	jne STRLEN_BEGINLOOPBODY
	STRLEN_ENDLOOPBODY:
	ret
