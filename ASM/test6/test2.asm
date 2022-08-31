dataseg segment
    STR db "My name is YJH, I am a student!", 0ah, 0dh, '$'
    SLEN equ $-STR
    GETN db "Please input n :", 0ah, 0dh, '$'
    GETM db "Please input m :", 0ah, 0dh, '$'
    N db 0, 0ah, 0dh, '$'
    M db 0, 0ah, 0dh, '$'
dataseg ends

stackseg segment
    db 256 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg
    start:

    mov ax, dataseg
    mov ds, ax
    mov es, ax
    mov ax, stackseg
    mov ss, ax

    mov al, 0

    mov ah, 09h    ; 输出字符串
    lea dx, STR 
    int 21H     

    mov ah, 09h    ; 输出提醒输入N
    lea dx, GETN
    int 21H

    mov ah, 07h    ; 获得输入N，存于bl中
    int 21H
    lea di, N
    mov [di], al
    sub al, 30h
    mov bl, al

    ; 验证获得的N是否正确
    mov ah, 09h
    lea dx, N
    int 21H

    mov ah, 09h    ; 输出提醒输入M
    lea dx, GETM
    int 21H

    mov ah, 07h    ; 获得输入M，存于bh中
    int 21H
    lea di, M
    mov [di], al
    sub al, 30h
    mov bh, al

    ; 验证获得的M是否正确
    mov ah, 09h
    lea dx, M
    int 21H

    lea di, STR    ; 将要处理的字符串作为参数输入 
    call REMOV     ; 调用函数

    mov ah, 09h    ; 输出处理之后的字符串
    lea dx, STR
    int 21H

    mov ax, 4c00h
    int 21H

    REMOV proc
    mov ah, 0       ; n -> bl -> ax
    mov al, bl
    mov dh, 0       ; m -> bh -> dx
    mov dl, bh

    mov cx, ax      ; 使di为第n个字符开始的地址
    l1:
    inc di
    loop l1
    
    mov cx, SLEN
    sub cx, ax
    sub cx, dx       ; 设置循环次数
    mov si, di       ; 使si为第n+m个字符开始的地址
    add si, dx    
    l2:              ; [si] -> [di]
    mov dl, [si]     
    mov [di], dl
    inc di
    inc si
    loop l2
    ret 
    endp

codeseg ends
end start