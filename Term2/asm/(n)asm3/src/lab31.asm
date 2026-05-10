;variant
; N = 3
; M = 11


;incls
;remember to clear registers when print
%include "./incls/macro.asm"

struc COORD
   .X resw 1
   .Y resw 1
endstruct

M   equ 11
N   equ 3
CELL equ 10

section .data
   startword   db   "Pls, enter massive"
   startwordlen equ $ - startword
   invite      db   "> "  
   invitelen    equ $ - invite


section .text
   global _start


section .bss
   input_buffer resb 128


_start:
   cld

   mov word [cursor + COORD.X], 0
   mov word [cursor + COORD.Y], 3
   call Enter_matrix
   ret

Enter_matrix:
   prn startword, startwordlen
   prn nl, nllen
   prn invite,    invitelen
