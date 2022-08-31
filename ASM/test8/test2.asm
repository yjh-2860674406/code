dataseg segment
    FAULT db 0                                                    ; 标志
    FOREVER db "Forever error", 0ah, 0dh, '$'   ; 永久故障输出
    TEMP db "Temp error", 0ah, 0dh, '$'             ; 暂时故障输出
dataseg ends

stackseg segment
    db 128 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg    
    start:
    mov ax, dataseg
    mov ds, ax
    mov ax, stackseg
    mov ss, ax

    cli
    ; 安装中断处理程序，中断号为9
    mov ax, codeseg
    mov ds, ax
    mov dx, offset judge
    mov al, 9
    mov ah, 25h
    int 21H
    mov ax, dataseg       ; 恢复数据段
    mov ds, ax
    sti

    mov al, 80h      
    ; 设置端口数据，调用中断
    out 20h, al       
    int 9

    cmp FAULT, 0ffh   ; 比较 fault 判断是否为永久故障
    jz yes                     
    lea dx, Temp          ; 暂时故障

    back:
    mov ah, 09h           ; 输出故障类型
    int 21H

    mov ah, 4ch
    int 21H

    yes:                        ; 永久故障
    lea dx, Forever
    jmp back


    judge proc
    ; 判断是否为永久故障
    push ax 

    call delay  ; 延迟 1s
    in al, 20h  ; 获取端口的值
    test al, 80h ; 比较是否第 7 位为1
    jz return     ; 不是则直接返回
    mov FAULT, 0ffh ; 是，将 fault 设置为全1
    jmp return  ; 返回

    delay proc
    ; 延迟1s
    push ax
    push cx
    push dx

    ; 1s = 1000000us = 0f4240hus
    mov ah,86h
    mov cx,0fh
    mov dx,4240h    
    int 15h 

    pop dx
    pop cx
    pop ax
    ret
    endp

    return:
    pop ax
    iret
    endp
codeseg ends
end start