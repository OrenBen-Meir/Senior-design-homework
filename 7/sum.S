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
	cmp $0, %esi
	jle sum_EndLoopBody
	sum_BeginLoopBody:
	movl (%rdi), %ecx
	decl %esi
	addq %rcx, %rax
	addq $4, %rdi
	cmpl $0, %esi
	jg sum_BeginLoopBody
	sum_EndLoopBody:
	ret
