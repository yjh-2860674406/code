assume cs : codesg

codesg segment
start :

    mov ax, 0h 
    mov bl, 09h 
    mov cl, 09h
    mov al, cl  
    mul bl 
    aam        ; 调整十六进制为非压缩BCD码
    mov dx, ax

    mov ax, 4c00h
    int 21H

codesg ends
end start