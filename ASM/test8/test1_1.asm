dataseg segment
    STR db "DIY int 9", 0ah, 0dh, '$'
dataseg ends

stackseg segment
    db 128 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg
    start:
    mov ax, stackseg
    mov ss, ax
    mov ax, codeseg
    mov ds, ax

    cli

    mov dx, offset introut9
    mov al, 9
    mov ah, 25h
    int 21H

    sti

    mov ax, dataseg
    mov ds, ax
    lea dx,  STR
    int 9
    ; 中断

    mov ax, 4c00h
    int 21H

    introut9 proc      
    ; 自定义的 9 号中断
    ; 输出 "DIY int 9"
    push ax
    pushf

    mov ah, 09h
    int 21H

    popf
    pop ax
    iret
    endp

codeseg ends
end start