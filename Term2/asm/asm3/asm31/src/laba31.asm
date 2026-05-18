.586
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


COORDINATE STRUC
    posX    dw ?
    posY    dw ?
COORDINATE ENDS


.data

    bytesWritten       dd 0

    appTitle           db "Nartov 515", 0

    inputMessage       db "Enter nums: ", 0
    inputMessageLen    equ $ - inputMessage - 2

    matrixout          db "========== Matrix ==========", 13, 10, 0
    matrixoutLen       equ $ - matrixout - 2

    newLine            db 13, 10

    scanfFormat        db "%hd", 0
    printfFormat       db "%10hd", 0

    MATRIX_ROWS        equ 3
    MATRIX_COLS        equ 11


.data?
    inputBuffer        db 9 dup(?)
    inputBufferSize    dd ?
    hConsoleOut        HANDLE ?
    hConsoleIn         HANDLE ?
    consoleCoord       LABEL DWORD
    cursorPos          COORDINATE <?>
    matrix             dd MATRIX_ROWS dup(MATRIX_COLS dup(?))
    rowIndex           dd ?
    colIndex           dd ?


.code

main PROC
    invoke SetConsoleOutputCP, 1251
    invoke SetConsoleCP, 1251
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConsoleOut, eax
    invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConsoleIn, eax
    invoke SetConsoleTitleA, Addr appTitle

    mov cursorPos.posY, 3
    mov rowIndex, 0

    invoke WriteConsole, hConsoleOut, ADDR inputMessage, inputMessageLen, ADDR bytesWritten, 0

    mov ecx, MATRIX_ROWS

row_input_loop:

    push ecx

    mov cursorPos.posX, 0
    mov colIndex, 0

    mov ecx, MATRIX_COLS

col_input_loop:

        mov esi, rowIndex
        imul esi, MATRIX_COLS
        add esi, colIndex

        push ecx

        invoke SetConsoleCursorPosition, hConsoleOut, consoleCoord

        invoke crt_scanf, ADDR scanfFormat, ADDR matrix[esi * 4]

        pop ecx

        mov ax, cursorPos.posX
        add eax, 10
        mov cursorPos.posX, ax

        inc colIndex

        loop col_input_loop

    inc cursorPos.posY

    pop ecx

    inc rowIndex

    loop row_input_loop


    invoke WriteConsole,hConsoleOut, Addr newLine, 2, Addr bytesWritten, 0
    invoke WriteConsole,hConsoleOut, Addr matrixout, matrixoutLen, Addr bytesWritten, 0
    invoke WriteConsole,hConsoleOut, Addr newLine, 2, Addr bytesWritten, 0
    invoke WriteConsole,hConsoleOut, Addr newLine, 2, Addr bytesWritten, 0
    mov rowIndex, 0
    mov ecx, MATRIX_ROWS

row_output_loop:
    push ecx
    mov colIndex, 0
    mov ecx, MATRIX_COLS

col_output_loop:
    mov esi, rowIndex
    imul esi, MATRIX_COLS
    add esi, colIndex
    push ecx
    invoke crt_printf, ADDR printfFormat, matrix[esi * 4]
    pop ecx
    add colIndex, 1
    loop col_output_loop
    invoke WriteConsole, hConsoleOut, ADDR newLine, 2, ADDR bytesWritten, 0



    pop ecx
    inc rowIndex
    loop row_output_loop
    invoke WriteConsole, hConsoleOut, Addr newLine, 2, ADDR bytesWritten, 0
    inkey "Tap to end..."
    invoke ExitProcess, 0

main ENDP

end main
