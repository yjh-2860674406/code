data segment
    BUF db 0f1h, 0c7h, 49h, 38h
    SUM dw 0000h
data ends

assume cs:codeseg, ds:data

codeseg segment
start :
    mov ax, data
    mov ds, ax

    mov ax, 0
    mov cx, 4
    lea bx, BUF

s:  add al, [bx]
    jo  s1
l:  inc bx
    loop s

    test al, 80h
    jz res
    sub ah, 1

res:mov SUM, ax

    mov ax, 4c00h
    int 21H

s1: jc  s2
    add ah, 1
    jmp l

s2: sub ah, 1
    jmp l


codeseg ends
end start