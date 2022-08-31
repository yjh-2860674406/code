assume cs : codesg

datasg segment
dw 0h, 0h
datasg ends

codesg segment 
start :
    mov ax, datasg
    mov ds, ax
    mov bx, 0h
    mov ax, 0001h;低位
    mov dx, 8000h;高位

    neg dx        ;求补
    neg ax        ;求补
    sbb dx,0      ;如果 ax 求补借位了 dx 就自减1
    
    mov [bx], ax  ;A 为 ds:0
    inc bx        ;bx 自增两次
    inc bx          
    mov [bx], dx

s : mov ax,4c00h
    int 21h

codesg ends
end start