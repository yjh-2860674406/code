assume cs:codeseg
codeseg segment
start :
    mov ax, 1234h

    mov dl, al
    mov cl, al
    mov bl, ah
    mov al, ah

    and dl, 0fh
    and cl, 0f0h
    shr cl, 1
    shr cl, 1
    shr cl, 1
    shr cl, 1
    and bl, 0fh
    and al, 0f0h
    shr al, 1
    shr al, 1
    shr al, 1
    shr al, 1

    mov ax, 4c00h
    int 21H
codeseg ends
end start