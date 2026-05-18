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
    szPromptSpeed   db "Enter initial speed: ", 0
    szPromptHeight  db "Enter maximum height: ", 0
    szError         db "Erroe...", 13, 10, 0
    
    szFmtTime       db "Flight time: %lf s", 13, 10, 0
    szFmtRange      db "Flight range: %lf m", 13, 10, 0
    szFmtSpeed      db "Speed: %6lf", 13, 10, 0
    szFmtHeight     db "Height: %lf", 13, 10, 0
    
    szWindowTitle   db "Nartov Sergey IVB-515 LR2.3", 0
    
    szInputFormat   db "%6lf", 0
    
    gravity         dq 9.8       ; ускорение свободного падения (м/с²)
    const_one       dq 1.0       ; константа 1.0
    const_two       dq 2.0       ; константа 2.0


.data?
    hConsoleOutput  HANDLE ?     ; дескриптор для вывода
    hConsoleInput   HANDLE ?     ; дескриптор для ввода
    
    sin_alpha       dq ?         ; синус угла
    cos_alpha       dq ?         ; косинус угла
    
    initial_speed   dq ?         ; начальная скорость v0
    max_height      dq ?         ; максимальная высота H
    
    flight_time     dq ?         ; время полёта t
    flight_range    dq ?         ; дальность полёта L

.code

main PROC

    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConsoleOutput, eax
    
    invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConsoleInput, eax

    ; starter speed
    invoke crt_printf, addr szPromptSpeed
    invoke crt_scanf,  addr szInputFormat, addr initial_speed
    
    ; Enter max Height
    invoke crt_printf, addr szPromptHeight
    invoke crt_scanf,  addr szInputFormat, addr max_height

    ; sinα = √(2gH) / (v0)
    ; sinα = sqrt(2 * g * H) / v0
    ;-----------------------------------------------------------------------
    fld     gravity             ; st(0) = g
    fld     max_height          ; st(0) = H, st(1) = g
    fmul    const_two           ; st(0) = 2*H, st(1) = g
    fmulp   st(1), st(0)        ; st(0) = 2*g*H
    fsqrt                       ; st(0) = sqrt(2*g*H)
    fld     initial_speed       ; st(0) = v0, st(1) = sqrt(2*g*H)
    fdivp   st(1), st(0)        ; st(0) = sqrt(2*g*H)/v0 = sinα
    
    ; sinα must be <= 1
    fld     const_one           ; st(0) = 1, st(1) = sinα
    fcomip  st(0), st(1)        ; сравнение 1 и sinα
    jb      error_occurred      ; если sinα > 1 → ошибка
    
    fstp    sin_alpha           ; сохраняем sinα
    
    ;cosα = √(1 - sin²α)
    fld     const_one           ; st(0) = 1
    fld     sin_alpha           ; st(0) = sinα, st(1) = 1
    fld     st(0)               ; st(0) = sinα, st(1) = sinα, st(2) = 1
    fmulp   st(1), st(0)        ; st(0) = sin²α, st(1) = 1
    fsubp   st(1), st(0)        ; st(0) = 1 - sin²α
    fsqrt                       ; st(0) = √(1 - sin²α) = cosα
    fstp    cos_alpha           ; сохраняем cosα
    
    ; Вычисление времени полёта: 
    ;       t = 2 * v0 * sinα / g
    fld     const_two           ; st(0) = 2
    fld     initial_speed       ; st(0) = v0, st(1) = 2
    fmul    sin_alpha           ; st(0) = v0*sinα, st(1) = 2
    fmulp   st(1), st(0)        ; st(0) = 2*v0*sinα
    fdiv    gravity             ; st(0) = 2*v0*sinα/g = t
    fstp    flight_time         ; сохраняем t
    
    invoke crt_printf, addr szFmtTime, flight_time
    
    ; Вычисление дальности полёта:
    ;       L = 2 * v0² * sinα * cosα / g
    fld     sin_alpha           ; st(0) = sinα
    fld     cos_alpha           ; st(0) = cosα, st(1) = sinα
    fmulp   st(1), st(0)        ; st(0) = sinα*cosα
    
    fld     initial_speed       ; st(0) = v0, st(1) = sinα*cosα
    fld     st(0)               ; st(0) = v0, st(1) = v0, st(2) = sinα*cosα
    fmulp   st(1), st(0)        ; st(0) = v0², st(1) = sinα*cosα
    fmulp   st(1), st(0)        ; st(0) = v0²*sinα*cosα
    
    fld     const_two           ; st(0) = 2, st(1) = v0²*sinα*cosα
    fmulp   st(1), st(0)        ; st(0) = 2*v0²*sinα*cosα
    fdiv    gravity             ; st(0) = 2*v0²*sinα*cosα/g = L
    fstp    flight_range        ; сохраняем L
    
    invoke crt_printf, addr szFmtRange, flight_range
    jmp     finish_program
    

error_occurred:
    invoke crt_printf, addr szError
    

finish_program:
    inkey "Press any key for exit..."
    invoke ExitProcess, 0
main ENDP
END main

