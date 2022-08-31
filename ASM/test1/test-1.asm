assume cs:codesg

codesg segment
    mov ah, 00H
    mov bh, 00H
    mov ch, 00H
    mov dh, 00H

    mov al, 0f0H
    mov bl, 0f0H
    mov cl, 0f0H
    mov dl, 0f0H

    add bx, ax
    add cx, bx
    add dx, cx

    mov ax, 4c00h
    int 21H
codesg ends

end