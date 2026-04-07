%macro print 2
   mov  rax,  1   ;syscall 1 -- print
   mov  rdi,  1   ;std out device
   mov  rsi,  %1  ;text
   mov  rdx,  %2  ;textlength
   syscall
%endmacro

%macro scanf 1
   mov  rax,  0   ;syscall 0 -- input
   mov  rdi,  0   ;std in device
   mov  rsi,  %1  ;text
   mov  rdx,  128 ;maxlength
   syscall
%endmacro

%macro ret 0
   mov  rax,  60
   mov  rdi,  0
   syscall
%endmacro
