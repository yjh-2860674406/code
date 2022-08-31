assume cs : codesg

datasg segment
NUM dw 2 dup (5, 3 dup (1, 2) , 0)
cnt equ $-NUM
datasg ends

codesg segment 
start :
    mov ax, datasg
    mov ds, ax

    mov ax, cnt

    mov ax,4c00h
    int 21h

codesg ends
end start