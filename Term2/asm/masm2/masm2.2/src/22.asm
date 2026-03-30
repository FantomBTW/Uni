.586p
.model flat, stdcall
option casemap: none
include C:\masm32\include\windows.inc
include C:\masm32\include\kernel32.inc
includelib C:\masm32\lib\kernel32.lib
include C:\masm32\include\user32.inc
includelib C:\masm32\lib\user32.lib
include C:\masm32\include\masm32.inc  
includelib C:\masm32\lib\masm32.lib   
include C:\masm32\include\msvcrt.inc  
includelib C:\masm32\lib\msvcrt.lib
include C:\masm32\macros\macros.asm


.data
  dwBytes          dd 0
  AppName          db "Nartov 2.2",0  

  messagestart     db "Please, enter X",13,10                  ; Задаём сообщение
  messagesizestart equ $-messagestart

  messageresult     db "ur result is:"                         ; Задаём сообщение
  messagesizeresult equ $-messageresult

  messagebadnum     db "Ur number is out of range or u've got divinity by zero",13,10       ; Задаём сообщение
  messagebadnumsize equ $-messagebadnum

  NewLine db 13,10


.data? 
  xvariable      db 10 dup(?)
  xvariablesize  dd ?           ; определение размера xvariable

  result      db 10 dup(?)
  resultsize  dd ?              ; определение размера result

  hStdOut HANDLE ?              ; определение устройств(переменные)
  hStdIn HANDLE ?


.code
main PROC
  invoke SetConsoleTitleA, Addr AppName

  invoke GetStdHandle, STD_OUTPUT_HANDLE  ; устройство вывода находим
  Mov hStdOut,EAX                         ; перемещение из аккума в переменную устройства вывода
  invoke GetStdHandle, STD_INPUT_HANDLE    
  Mov hStdIn,EAX                          

;начинаем саму программу
  ;предлагаем ввести X
  invoke WriteConsole,hStdOut, Addr messagestart, messagesizestart, Addr dwBytes, 0
  ;и читаем его
  invoke ReadConsole, hStdIn, Addr xvariable, LENGTHOF xvariable, Addr xvariablesize, 0    ;invoke читаем_из_консоли откуда куда сколько

  Lea   ESI,    [xvariable]     ;берём адрес первого символа из переменной
  Add   ESI,    xvariablesize   ;добавляем длину слова
  Sub   ESI,    2               ;берём перевод кареты
  Mov   [ESI],  word ptr 0      ;заменяем перевод кареты концом слова

  invoke atodw, Addr xvariable  ;понимаем слово
  Mov  EBX,  EAX                ;сохраняем в EBX
  
; начинаем неистово как внимательно рассматривать EBX
  Mov  EAX,  EBX                ;take from EBX
  cmp  EAX,  -20
  JL   NUMBAD                   ;out of range

  Mov  EAX,  EBX                ;take from EBX
  cmp  EAX,  50
  JG   NUMBAD                   ;out of range

  ;if Not Lower 18 case 2 from table
  Mov  EAX,  EBX                ;take from EBX
  cmp  EAX,  18
  JL   casetwo                  ;out of range
  JMP  casefour


casetwo:
  Mov  EAX,  EBX      ; EBX = x
  Add  EAX,  3        ; EAX = x+3
  Mov  ECX,  EAX      ; ECX = x+3
  imul EAX,  ECX      ; EAX = (x+3)*(x+3)
  ; we needa save EBX(x) and EAX(chislitel)
  ; feel free to use ECX and EDX
  Mov  ECX,  1        ;ECX = 1
  SUB  ECX,  EBX      ;ECX = 1-x

  cmp  ECX, 0         ;divinity by zero
  JE   NUMBAD
  
  Xor  EDX,  EDX
  idiv ECX         ;idiv do  EAX = EAX/anything   EDX = ostatok

  JMP MATHEND


casefour:
  Mov  EAX,  EBX      ; EBX = x
  Add  EAX,  3        ; EAX = x+3
  Mov  ECX,  EAX      ; ECX = x+3
  imul EAX,  ECX      ; EAX = (x+3)*(x+3)
  imul EAX,  ECX      ; EAX = (x+3)*(x+3) * ECX(still x+3)

  JMP MATHEND


NUMBAD:
  Invoke WriteConsole, hStdOut, Addr messagebadnum, messagebadnumsize, Addr dwBytes, 0
  JMP EndProgram


MATHEND:
; what is our target
; we needa translate EAX and print it so, i'll mov EAX to result by dwtoa and print it
  Invoke dwtoa, EAX, Addr result
; now hot to get resultsize?
  Invoke szLen, Addr result
  Mov resultsize, EAX

  Invoke WriteConsole, hStdOut, Addr messageresult, messagesizeresult, Addr dwBytes, 0
  Invoke WriteConsole, hStdOut, Addr result, resultsize, Addr dwBytes, 0
  Invoke WriteConsole, hStdOut, Addr NewLine, 2, Addr dwBytes, 0
  
  JMP EndProgram


EndProgram:
  ;Invoke WriteConsole,hStdOut, 13,  10, 2, Addr dwBytes, 0
  inkey "Press any key"       ; Press smth
  invoke ExitProcess,0                                            ;return 0 
main ENDP                                                               ; }
end main
