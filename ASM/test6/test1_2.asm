dataseg segment
    BINARY dw 1100101000101111b ; CA2F
dataseg ends

stackseg segment
    db 256 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg
    start:
    mov ax, dataseg
    mov ds, ax        ; 设置段寄存器
    mov ax, stackseg
    mov ss, ax
    mov ax, 0         

    lea bx, BINARY     

    push [bx]         ; 获取16位
    call getHex       ; 调用子程序输出

    mov ax, 4c00h
    int 21H

    getHex proc
    mov bp, sp
    mov dx, [bp+2]
    push dx
    mov ah, 02h
    
    mov dl, dh
    and dl, 0f0h
    shr dl, 4
    call getChar          
    int 21H       ; 输出高8位中的高4位
    
    mov dl, dh    
    and dl, 0fh
    call getChar
    int 21H       ; 输出高8位中的低4位

    pop dx
    mov dh, dl
    and dl, 0f0h
    shr dl, 4
    call getChar
    int 21H       ; 输出低8位中的高4位
   
    mov dl, dh
    and dl, 0fh
    call getChar
    int 21H       ; 输出低8位中的低4位
    ret
    endp

    getChar proc  ; 将十六进制数字转换成字符
    cmp dl, 9
    ja abort 
    jna noabort
    return:
    ret
    endp

    abort:
    add dl, 37h
    jmp return

    noabort:
    or dl, 30h
    jmp return

codeseg ends
end start