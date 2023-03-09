#include <stdint.h>
#include <stddef.h>

// TODO: replace with your definition
#include <setjmp.h> // remove this
#define asm_jmp_buf jmp_buf

struct jmp_buf{
    
};


//   {
//     /* NOTE: The machine-dependent definitions of `__sigsetjmp'
//        assume that a `jmp_buf' begins with a `__jmp_buf' and that
//        `__mask_was_saved' follows it.  Do not move these members
//        or add others before it.  */
//     __jmp_buf __jmpbuf;		/* Calling environment.  */
//     int __mask_was_saved;	/* Saved the signal mask?  */
//     __sigset_t __saved_mask;	/* Saved signal mask.  */
//   };







int64_t asm_add(int64_t a, int64_t b);
int     asm_popcnt(uint64_t x);
void   *asm_memcpy(void *dest, const void *src, size_t n);
int     asm_setjmp(asm_jmp_buf env);
void    asm_longjmp(asm_jmp_buf env, int val);
