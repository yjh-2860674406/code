data segment
    BCD1 db 09h, 04h
    BCD2 db 05h, 08h
    BCD3 db 00h, 00h, 00h
data ends

assume cs:codeseg, ds:data

codeseg segment
start :
    mov ax, data
    mov ds, ax

    mov ax, 0

    mov al, BCD1
    add al, BCD2
    aaa

    mov BCD3, al
    mov al, BCD1+1
    adc al, BCD2+1
    aaa

    adc BCD3+2, 0
    mov BCD3+1, al


    mov ax, 4c00h
    int 21H

codeseg ends
end start

