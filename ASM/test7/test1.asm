dataseg segment
    INPUTN db "Please input a num as len of string (two num)：", 0ah, 0dh, '$'
    INPUTSTR db "Please input a string：", 0ah, 0dh, '$'
    STR db 256 dup(0)
    H db 0ah, 0dh, '$'
dataseg ends

stackseg segment
    db 256 dup(0)
stackseg ends

codeseg segment
    start:
    assume cs:codeseg, ds:dataseg, ss:stackseg
    mov ax, dataseg
    mov ds, ax
    mov ax, stackseg
    mov ss, ax

    lea dx, INPUTN
    call Input            ; 提示输入字符串长度

    call getNum        ; 获取字符串长度的输入
    mov cx, ax
    lea dx, H
    call Input            ; 换行

    lea dx, INPUTSTR
    call Input          ; 提示输入字符串

    lea di, STR        ; 传递参数
    call getStr        ; 调用函数
    lea dx, H
    call Input          ; 换行

    lea dx, STR
    call Input          ; 输出结果
    lea dx, H
    call Input          ; 换行

    mov ax, 4c00h
    int 21H

    getChar proc
    ; 获取字符
    ; 参数：di -> &char
    ; 返回：无
    push ax

    mov ah, 01
    int 21H
    mov [di], al

    pop ax
    ret
    endp

    getStr proc
    ; 获取字符串
    ; 参数：cx -> strlen, di -> &string
    ; 返回：无

    L:
    call getChar  ; 调用获取字符函数
    inc di
    loop L

    mov [di], '$'
    ret
    endp

    Input proc
    ; 输出字符串
    push ax
    mov ah, 09
    int 21H
    pop ax
    ret
    endp

    getNum proc
    ; 获取两个字符输入，并转换成数字
    ; 参数：无
    ; 返回：ax -> num
    mov ah, 01
    int 21H         ; 输入 -> al

    push dx
    mov dh, 0     
    mov dl, 10
    sub al, 30h   ; ASCII -> 数字
    mul dl           ; dl *= 10 ( 十位上的数字 )
    mov dl, al
   
    mov ah, 01    ; 输入 -> al
    int 21H         
    sub al, 30h   ; ASCII -> 数字
    add dl, al         
    mov ax, dx    
    pop dx
    ret
    endp

codeseg ends
end start