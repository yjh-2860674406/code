data segment
    STR db "CAN YOU DEBUG$"
    SLEN equ $-S
    DEBUG db "debug$"
    DELEN equ $-DEBUG
    H db 0ah, 0dh, '$'
    YES db "YES$"
    NO db "NO$"
data ends

assume cs:code, ds:data

code segment

start:
    mov ax, data
    mov ds, ax
    mov es, ax
    mov ax, 0

    mov cx, DELEN

    mov ah, 09H
    lea dx, STR
    int 21H

    mov ah, 09H
    lea dx, H
    int 21H

    mov ah, 09H
    lea dx, DEBUG
    int 21H

    mov ah, 09H
    lea dx, H
    int 21H

    mov ax, 0

    lea di, STR
    lea si, DEBUG    
BACK1:
    push si
    push di
    cld
    repz cmpsb 
    je HE
    jmp HNE

HNE:
    inc ax
    cmp ax, SLEN    
    jz RES  
    pop di
    pop si
    inc di
    mov cx, DELEN
    jmp BACK1

HE:
    mov ah, 09H
    lea dx, YES
    int 21H

    mov ah, 09H
    lea dx, H
    int 21H

    mov ax, 4c00H
    int 21H

RES:
    mov ah, 09H
    lea dx, NO
    int 21H

    mov ah, 09H
    lea dx, H
    int 21H

    mov ax, 4c00H
    int 21H

code ends
end start