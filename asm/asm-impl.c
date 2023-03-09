#include "asm.h"
#include <string.h>

#ifdef DEBUG
  #define debug(fmt,...) printf(fmt,__VAR_ARGS__)
#else
  #define debug(fmt,...) 
#endif


// 返回有符号 64 位整数 a + b 的数值
int64_t asm_add(int64_t a, int64_t b) {
    int64_t sum = 0;
    __asm__ __volatile__ (
        "addl %%ebx,%%eax  ;\n"
        :"=a"(sum)
        :"a"(a),"b"(b),"ir"(sum)
        :
    );
    debug("a = %ld , b = %ld , a+b = %ld\n", a , b, sum);
    return sum;
}

// 返回无符号 64 位整数 x 二进制表示中 1 的数量
int asm_popcnt(uint64_t x) {
  int s = 0;
    __asm__ __volatile__(
        "xor       %%rcx,%%rcx      ;\n"
        "start:\t  cmp %%rcx,64     ;\n\t"
        "          jg end           ;\n\t"
        "          test %%rax,1     ;\n\t"
        "          jne plus         ;\n"
        "plus:\t   inc %%rdx        ;\n\t"
        "          shr %%rax,$0x00000001      ;\n"
        "end:\t                     ;\n"
        :"=d"(s)
        :"a"(x),"d"(s)
        :"cc"
    ); 

  for (int i = 0; i < 64; i++) {
    if ((x >> i) & 1) s++;
  }
  return s;
}
// C 标准库中的 memcpy，用于复制两段不相交的内存
void *asm_memcpy(void *dest, const void *src, size_t n) {
    __asm__ __volatile__(
        "rep movsb" 
        :"=D"(dest),"=S"(src),"=c"(n)
        :"0"(dest),"1"(src),"2"(n)
        :"memory"
    );
  //return memcpy(dest, src, n);
}



int asm_setjmp(asm_jmp_buf env) {
  return setjmp(env);
}

void asm_longjmp(asm_jmp_buf env, int val) {
  longjmp(env, val);
}
