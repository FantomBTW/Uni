.586p
.model flat, stdcall
option casemap: none

.code
shaker_sort PROC uses eax ebx ecx edx esi edi, arrLen:DWORD, arrAddr:DWORD
    LOCAL left:DWORD
    LOCAL right:DWORD
    LOCAL swapped:DWORD
    
    mov left, 0
    mov eax, arrLen
    dec eax
    mov right, eax
    mov swapped, 1
    
sort_loop:
    cmp swapped, 0
    je sort_done
    
    mov swapped, 0
    
    mov ecx, left
    mov edi, arrAddr
    
left_to_right:
    cmp ecx, right
    jge right_to_left_start
    
    mov eax, [edi + ecx*4]
    mov edx, [edi + ecx*4 + 4]
    
    cmp eax, edx
    jge no_swap_right
    
    mov [edi + ecx*4], edx
    mov [edi + ecx*4 + 4], eax
    mov swapped, 1
    
no_swap_right:
    inc ecx
    jmp left_to_right
    
right_to_left_start:
    cmp swapped, 0
    je sort_done
    
    dec right
    
    mov ecx, right
    mov edi, arrAddr
    
right_to_left:
    cmp ecx, left
    jle update_left
    
    mov eax, [edi + ecx*4]
    mov edx, [edi + ecx*4 - 4]
    
    cmp edx, eax
    jge no_swap_left
    
    mov [edi + ecx*4], edx
    mov [edi + ecx*4 - 4], eax
    mov swapped, 1
    
no_swap_left:
    dec ecx
    jmp right_to_left
    
update_left:
    inc left
    jmp sort_loop
    
sort_done:
    ret
shaker_sort ENDP

end