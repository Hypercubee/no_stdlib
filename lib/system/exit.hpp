#if defined(__arm__) || defined(__thumb__) || defined(_M_ARM) || defined(_M_ARMT)
void exit(int status) {
	__asm__(
	    "mov r7, %0 \n\t"
	    "mov r0, %1 \n\t"
	    "svc 0 \n\t"
	    :
	    : "r"(1L), "r"((long)status)
	    : "r0", "r7");
}
#elif defined(__aarch64__) || defined(_M_ARM64)
void exit(int status) {
	__asm__(
	    "mov x8, %0 \n\t"
	    "mov x0, %1 \n\t"
	    "svc 0 \n\t"
	    :
	    : "r"(93L), "r"((long)status)
	    : "x0", "x8");
}
#elif defined(__i386__) || defined(_M_IX86)
void exit(int status) {
	__asm__(
	    "movl %0, %%eax \n\t"
	    "movl %1, %%ebx \n\t"
	    "int $0x80 \n\t"
	    :
	    : "r"(1L), "r"((long)status)
	    : "%eax", "%ebx");
}
#elif defined(__x86_64__) || defined(_M_X64)
void exit(int status) {
	__asm__(
	    "movq %0, %%rax \n\t"
	    "movq %1, %%rdi \n\t"
	    "syscall \n\t"
	    :
	    : "r"(60L), "r"((long)status)
	    : "%rax", "%rdi");
}
#endif
