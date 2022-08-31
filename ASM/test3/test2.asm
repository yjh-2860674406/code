dataseg segment 
    LEDtable db 0c0h, 0f9h, 0a4h, 0b0h, 99h,  92h,  82h, 0f8h
             db 80h,  90h,  88h,  83h,  0c6h, 0c1h, 86h, 8eh
dataseg ends

codeseg segment
start:
    mov ax, dataseg
    mov ds, ax

    mov ah, 01h
    int 21H

    cmp al, 40h
    jb i    
    sub al, 51h

res:
    mov bx, 0h
    mov bl, al
    mov al, [bx]

i:
    sub al, 30h
    jmp res

codeseg ends
end start