data segment
BUF1 db 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
BUF2 db 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
BUF3 db 15 dup(0)
H    db 0ah ,0dh, '$'
data ends

stack segment 
    dw 128 dup(0)
stack ends

assume cs:code, ss:stack, ds:data

code segment 

start:
    mov ax, data
    mov ds, ax

    mov ax, stack 
    mov ss, ax

    lea di, BUF3
    xor bx, bx       
    mov cx, 15
l0:
    push cx          ; bx = i
    mov al, BUF1[bx] ; al = buf1[i]
    inc bx
    mov cx, 20       ; 循环 20 次
    lea si, BUF2     ; si = j

l2:
    mov dl, [si]     ; dl = buf2[j]
    cmp al, dl       
    je l1            ; if (al == dl) 即存在相等的值
    inc si           
    loop l2          ; 找 20 次
    jmp l3           

l1:                  ; buf3[k] = 把值放入buf3中
    mov [di], al
    inc di

l3: 
    pop cx           ; 保存cx
    loop l0          ; 找 15 次
    
    mov cx, 15
    lea di, BUF3     ; 准备输出相同的值

l4: 
    push cx          
    mov al, [di]     ; al = buf3[k]
    inc di
    xor cx, cx
    mov bl, 10

l5:
    xor ah, ah           
    div bl

    push ax
    inc cx
    cmp al, 0
    jne l5          ; 查找循环多少次,即有多少个相同的值

l6:                 ; 输出
    pop DX
    mov dl, DH   
    add dl, 30H
    mov ah, 2
    int 21H
    loop l6

    mov ah, 9
    lea dx, H
    int 21H

    pop cx
    loop l4

    mov ax, 4c00h
    int 21H

code ends
end start