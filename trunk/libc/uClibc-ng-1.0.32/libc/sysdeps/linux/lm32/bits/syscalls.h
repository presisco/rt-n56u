#ifndef _BITS_SYSCALLS_H
#define _BITS_SYSCALLS_H
#ifndef _SYSCALL_H
# error "Never use <bits/syscalls.h> directly; include <sys/syscall.h> instead."
#endif


#ifndef __ASSEMBLER__

#define INTERNAL_SYSCALL_NCS(name, err, nr, args...)                    \
        ({                                                              \
                LOAD_ARGS_##nr (args);                                  \
                register int __ret __asm__("r1");                       \
                register int _scno __asm__("r8") = name;                \
                __asm__ __volatile__("scall"                            \
                              : "=r" (__ret)                            \
                              :  "r"(_scno) ASM_ARGS_##nr               \
                              : __SYSCALL_CLOBBERS );                   \
                __ret;                                                  \
        })

/* original port had ret >= -125 ?! */
#define LOAD_ARGS_0() do { } while(0)
#define ASM_ARGS_0
#define LOAD_ARGS_1(a1)                                 \
	int _a1 = (int)(a1);				\
	LOAD_ARGS_0();					\
	register int __a1 __asm__("r1") = _a1
#define ASM_ARGS_1      ASM_ARGS_0, "0"(__a1)
#define LOAD_ARGS_2(a1, a2)                             \
	int _a2 = (int)(a2);				\
	LOAD_ARGS_1(a1);				\
	register int __a2 __asm__("r2") = _a2
#define ASM_ARGS_2      ASM_ARGS_1, "r"(__a2)
#define LOAD_ARGS_3(a1, a2, a3)                         \
	int _a3 = (int)(a3);				\
	LOAD_ARGS_2(a1, a2);				\
	register int __a3 __asm__("r3") = _a3
#define ASM_ARGS_3      ASM_ARGS_2, "r"(__a3)
#define LOAD_ARGS_4(a1, a2, a3, a4)                     \
	int _a4 = (int)(a4);				\
	LOAD_ARGS_3(a1, a2, a3);			\
	register int __a4 __asm__("r4") = _a4
#define ASM_ARGS_4      ASM_ARGS_3, "r"(__a4)
#define LOAD_ARGS_5(a1, a2, a3, a4, a5)                 \
	int _a5 = (int)(a5);				\
	LOAD_ARGS_4(a1, a2, a3, a4);			\
	register int __a5 __asm__("r5") = _a5
#define ASM_ARGS_5      ASM_ARGS_4, "r"(__a5)
#define LOAD_ARGS_6(a1, a2, a3, a4, a5, a6)             \
	int _a6 = (int)(a6);				\
	LOAD_ARGS_5(a1, a2, a3, a4, a5);		\
	register int __a6 __asm__("r6") = _a6
#define ASM_ARGS_6      ASM_ARGS_5, "r"(__a6)

#define __SYSCALL_CLOBBERS

#endif /* __ASSEMBLER__ */
#endif /* _BITS_SYSCALLS_H */
