#ifndef PRINT
#define PRINT

#include "tostring.hpp"


void print(const char* message) {
	int length = string_length(message);
#if defined(__arm__) || defined(__thumb__) || defined(_M_ARM) || defined(_M_ARMT)
	// ARM-specific inline assembly
	__asm__(
	    "mov r7, %0 \n\t"
	    "mov r0, %1 \n\t"
	    "mov r1, %2 \n\t"
	    "mov r2, %3 \n\t"
	    "svc 0 \n\t"
	    :
	    : "r"((long)4), "r"((long)1), "r"(message), "r"((long)length)
	    : "r0", "r1", "r2", "r7");

#elif defined(__aarch64__) || defined(_M_ARM64)
	// ARM64-specific inline assembly
	__asm__(
	    "mov x8, %0 \n\t"
	    "mov x0, %1 \n\t"
	    "mov x1, %2 \n\t"
	    "mov x2, %3 \n\t"
	    "svc 0 \n\t"
	    :
	    : "r"((long)64), "r"((long)1), "r"(message), "r"((long)length)
	    : "x0", "x1", "x2", "x8");

#elif defined(__i386__) || defined(_M_IX86)
	// x86-specific inline assembly
	__asm__(
	    "movl %0, %%eax \n\t"
	    "movl %1, %%ebx \n\t"
	    "movl %2, %%ecx \n\t"
	    "movl %3, %%edx \n\t"
	    "int $0x80 \n\t"
	    :
	    : "r"((long)4), "r"((long)1), "r"(message), "r"((long)length)
	    : "%eax", "%ebx", "%ecx", "%edx");

#elif defined(__x86_64__) || defined(_M_X64)
	// x86-64-specific inline assembly
	__asm__(
	    "movq %0, %%rax \n\t"
	    "movq %1, %%rdi \n\t"
	    "movq %2, %%rsi \n\t"
	    "movq %3, %%rdx \n\t"
	    "syscall \n\t"
	    :
	    : "r"((long)1), "r"((long)1), "r"(message), "r"((long)length)
	    : "%rax", "%rdi", "%rsi", "%rdx");

#else
#error "Unsupported architecture"
#endif
}

#endif