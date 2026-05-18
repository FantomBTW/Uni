.686p

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
  szAppName db "Nartov Sergey IVB-515 LR2.3",0
  messagestart db "Please, enter X: ",0
  messageresult db "Your result is: %lf",13,10,0
  messagebadnum db "Your number is out of range or you've got division by zero",13,10,0
  inputs db "%lf",0

  three dq 3.0
  one dq 1.0
  neg20 dq -20.0
  fifty dq 50.0
  eighteen dq 18.0

.data? 
  x dq ?
  y dq ?

.code
main PROC

  finit

  invoke SetConsoleTitleA, Addr szAppName

  invoke crt_printf, addr messagestart
  invoke crt_scanf, addr inputs, addr x

  ; Проверяем x >= -20
  fld x           ; st(0) = x
  fld neg20       ; st(0) = -20, st(1) = x
  fcomip st(0), st(1)  ; сравниваем -20 и x (st(0) с st(1))
  ja check_range_failed  ; если -20 > x (т.е. x < -20) то ошибка
  
  ; Проверяем x <= 50
  fld x           ; st(0) = x
  fld fifty       ; st(0) = 50, st(1) = x
  fcomip st(0), st(1)  ; сравниваем 50 и x
  jb check_range_failed  ; если 50 < x (т.е. x > 50) то ошибка
  
  ; ПРОВЕРКА УСЛОВИЯ x < 18 
  fld x           ; st(0) = x
  fld eighteen    ; st(0) = 18, st(1) = x
  fcomip st(0), st(1)  ; сравниваем 18 и x
  ja case_two     ; если 18 > x (т.е. x < 18) то case_two
  jmp case_four   ; иначе case_four
  
check_range_failed:
  jmp bad_range

case_two:
  ; y = (x+3)^2 / (1-x)
  
  ; Проверка на деление на ноль (x = 1)
  fld x
  fld one
  fcomip st(0), st(1)  ; сравниваем x и 1
  je bad_range         ; если x = 1, то ошибка
  
  ; Вычисляем (x+3)^2
  fld x
  fld three
  faddp st(1), st(0)   ; st(0) = x+3
  fld st(0)            
  fmulp st(1), st(0)   ; st(0) = (x+3)^2
  
  ; Вычисляем (1-x)
  fld one
  fld x
  fsubp st(1), st(0)   ; st(0) = 1-x
  
  ; Делим
  fdivp st(1), st(0)   ; st(0) = (x+3)^2 / (1-x)
  fstp y
  
  invoke crt_printf, addr messageresult, y
  jmp EndProgram

case_four:
  ; y = (x+3)^3
  fld x
  fld three
  faddp st(1), st(0)   ; st(0) = x+3
  
  fld st(0)            
  fmulp st(1), st(0)   ; st(0) = (x+3)^2
  
  fld x
  fld three
  faddp st(1), st(0)   ; st(0) = x+3
  fmulp st(1), st(0)   ; st(0) = (x+3)^3
  
  fstp y
  
  invoke crt_printf, addr messageresult, y
  jmp EndProgram

bad_range:
  invoke crt_printf, addr messagebadnum

EndProgram:
  inkey "Press any key for end..."
  invoke ExitProcess, 0

main ENDP
end main
