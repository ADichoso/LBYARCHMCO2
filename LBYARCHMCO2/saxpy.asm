section .text

BITS 64
default rel 

global saxpy_asm
   saxpy_asm: ; void saxpy_asm(int N, float A, float X[], float Y[], float Z[])
   push rbp
   mov rbp, rsp
   add rbp, 16
   
   mov r10, [rbp + 32]; Z

   mov rbx, 0
      ; N is in RCX, A is in XMM1, X is in R8, Y is in R9
   loop1:
      vmovss xmm2, [r8 + rbx*4] ; Load X[i] into XMM2
      vmulss xmm2, xmm1 ; XMM1 <- A*X[i]
      vaddss xmm3, xmm2, [r9 + rbx*4] ; XMM3 <- Z[i] = A*X[i] + Y[i]
      movss [r10 + rbx*4], xmm3 ; Store Z[i] back to Z
      inc rbx
      loop loop1
   pop rbp
   ret
