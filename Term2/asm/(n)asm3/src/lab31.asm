;incls
;remember to clear registers when print
%include "./incls/macro.inc"

section .data
   startword   db   "Pls, enter massive"
   startwordlen equ $ - startword

section .text
   global _start

_start:
   print startword, startwordlen
   ret

