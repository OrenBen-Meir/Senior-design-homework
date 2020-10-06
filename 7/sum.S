#include "asm.h"

/*
 * extern unsigned long long sum(unsigned int *array, size_t n);
 *
 * You are only allowed to use the following instructions:
 *   cmp
 *   jg
 *   jge
 *   jne
 *   je
 *   inc
 *   dec
 *   jge
 *   xor
 *   mov
 *   add
 *   jl
 *   jle
 */
ENTRY(sum):
	xor %rax, %rax
	xor %rcx, %rcx
	BEGINLOOPSUM:
	cmp $0, %esi
	jle ENDLOOPSUM
	movl (%rdi), %ecx
	dec %esi
	addq %rcx, %rax
	add $4, %rdi
	jmp BEGINLOOPSUM
	ENDLOOPSUM:
	ret
