data segment 
    BINARY dw 46572
    BCD    db 5 dup(0), 0ah, 0dh, '$'
data ends

stack segment
    db 32 dup(0)
stack ends

assume cs:code, ds:data, ss:stack

code segment
start:
    mov ax, data
    mov ds, ax

    mov bx, 10000  ; 一开始的除数
    mov cx, 10     ; 用来将除数降级 10000->1000->100->10->1
    mov di, 0      ; 用大端法存储
    mov ax, BINARY ; 一开始的被除数

again:
    div bx         
    or al, 30h     ; 获得万位，千位，百位，十位，个位
    mov BCD[di], al; 送到数据段中
    push dx        ; 存储余数
    mov ax, bx     ; 将除数赋值给ax
    mov bx, 0
    div cx         ; 获得新的除数
    mov bx, ax     ; 更新除数
    pop ax         ; 将栈中的余数赋值给ax
    inc di         ; 偏移量++
    cmp di, 5      ; 5位数
    jnz again             

    mov ah, 09H    ; 输出
    lea dx, BCD
    int 21H

    mov ah, 4ch
    int 21H
code ends
end start


