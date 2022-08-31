; 最多只能算到 2^16 大概 在 10^5 左右
dataseg segment
    INPUTX db "Please input a nums as x (two num) ：", 0ah, 0dh, '$'
    INPUTN db "Please input a nums as n (two num) ：", 0ah, 0dh, '$'
    H db 0ah, 0dh, '$'
    BCD 5 dup(0), 0ah, 0dh, '$'
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

    lea dx, INPUTX    ; 提示输入x
    call outputStr

    call getNum          ; bl -> x
    mov bl, al

    lea dx, H               ; 换行
    call outputStr

    lea dx, INPUTN    ; 提示输入n
    call outputStr
    
    call getNum           ; al -> n

    lea dx, H                ; 换行
    call outputStr

    mov cl, al
    mov dl, bl
    mov dh, 0
    ; 参数：cl -> n, dx -> x
    call getPow             ; 递归求幂

    call outputNum       ; 获得十进制

    lea dx, BCD             ; 输出十进制            
    call outputStr

    mov ax, 4c00h
    int 21H

    outputNum proc
    ; 将十六进制以十进制的形式输出
    ; 参数：ax
    push ax
    push bx
    push cx
    push dx
    pushf

    mov bx, 10000   ; 一开始的除数
    mov cx, 10         ; 用来将除数降级 10000->1000->100->10->1
    mov di, 0           ; 用大端法存储
    mov dx, 0

    again:
    div bx         
    or al, 30h          ; 获得万位，千位，百位，十位，个位
    mov BCD[di], al ; 送到数据段中
    push dx             ; 存储余数
    mov ax, bx        ; 将除数赋值给ax
    mov dx, 0
    div cx               ; 获得新的除数
    mov bx, ax        ; 更新除数
    pop ax              ; 将栈中的余数赋值给ax
    inc di                ; 偏移量++
    cmp di, 5          ; 5位数
    jnz again

    popf
    pop dx
    pop cx
    pop bx
    pop ax
    ret
    endp

    getPow proc 
    ; 参数：cl -> n, dx -> x
    ; 返回：ax -> x^n

    cmp cl, 1      ; if (cl == 1) return ax=x
    jz BACK
                       ; else
    dec cl          
    call getPow  ; ax -> getPow(x, n-1)
    push dx       
    mul dx         ; ax *= x
    pop dx

    RETURN:
    ret              ; return x
    BACK:
    mov ax, dx
    jmp RETURN
    endp

    outputStr proc
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
    push dx
    mov ah, 01
    int 21H         ; 输入 -> al

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