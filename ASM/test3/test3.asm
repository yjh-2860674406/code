codeseg segment 
start:
    
    cmp dx, di
    ja above
    cmp ax, si
    jg greater
    cmp cx, 0
    jz zero    
    cmp ax, di
    jo overflow
    cmp si, ax
    jle less_eq
    cmp di, dx
    jbe below_eq

    mov ax, 4c00h
    int 21H

above:
greater:
zero:
overflow:
less_eq:
below_eq:

codeseg ends
end start