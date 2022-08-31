dataseg segment
    bufX db 10h 
    bufY db 01h
    bufZ db 10h
dataseg ends

assume cs:codeseg, ds:dataseg

codeseg segment 
strat :

    mov ax, dataseg
    mov ds, ax

    mov ax, 0
    mov bl, bufX
    mov cl, bufY
    mov dl, bufZ

    XY:
    cmp bl, cl
    jz e1
    XZ: 
    cmp bl, dl
    jz e2    
    
    res:
    mov ah, 02h
    or  al, 30h
    mov dl, al
    int 21h 
    

    e1:
    inc ax
    jmp XZ

    e2:
    inc ax
    jmp res

codeseg ends
end strat
