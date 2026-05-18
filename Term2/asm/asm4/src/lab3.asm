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

includelib mylib.lib

shaker_sort PROTO :DWORD, :DWORD

GENERATE_ARRAY MACRO maxVal, arrLen, arrAddr
    LOCAL gen_loop, gen_char, rdrand_retry
    
    mov ecx, arrLen
    mov esi, arrAddr
    
gen_loop:
    push ecx
    push esi
    
    lea edi, rand_buf
    mov ecx, 4
    
gen_char:
    push ecx
    
rdrand_retry:
    db 0Fh, 0C7h, 0F0h
    jnc rdrand_retry
    
    xor edx, edx
    mov ecx, 94
    div ecx
    add edx, 33
    
    mov al, dl
    stosb
    
    pop ecx
    loop gen_char
    
    mov byte ptr [edi], 0
    
    invoke atodw, addr rand_buf
    
    xor edx, edx
    mov ecx, maxVal
    inc ecx
    div ecx
    mov eax, edx
    
    pop esi
    mov [esi], eax
    add esi, 4
    
    pop ecx
    loop gen_loop
ENDM

.data
    arr         dd 20 dup(?)
    arrSize     dd 20
    maxValue    dd 420
    
    rand_buf    db 5 dup(?)
    
    str_original    db "Original array:", 13, 10, 0
    str_sorted      db 13, 10, "Sorted array:", 13, 10, 0
    str_format_num  db "%d ", 0
    str_format_last db "%d", 13, 10, 0
    str_newline     db 13, 10, 0

.code
print_array PROC uses ecx esi, arrLen:DWORD, arrAddr:DWORD
    mov ecx, arrLen
    mov esi, arrAddr
    
print_loop_func:
    push ecx
    
    mov eax, [esi]
    
    cmp ecx, 1
    jg print_space_func
    
    invoke crt_printf, addr str_format_last, eax
    jmp print_next_func
    
print_space_func:
    invoke crt_printf, addr str_format_num, eax
    
print_next_func:
    add esi, 4
    pop ecx
    loop print_loop_func
    
    ret
print_array ENDP

main PROC
    GENERATE_ARRAY maxValue, arrSize, offset arr
    
    invoke crt_printf, addr str_original
    invoke print_array, arrSize, offset arr
    
    invoke shaker_sort, arrSize, offset arr
    
    invoke crt_printf, addr str_sorted
    invoke print_array, arrSize, offset arr
    invoke crt_printf, addr str_newline
    
    inkey "Press any key to exit..."
    invoke ExitProcess, 0
    
main ENDP
end main