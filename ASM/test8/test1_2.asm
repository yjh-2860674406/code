dataseg segment
    STR db "DIY int 9", 0ah, 0dh, '$'
dataseg ends

stackseg segment
    db 128 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg
    start:
    mov ax, stackseg
    mov ss, ax
    mov ax, dataseg
    mov ds, ax
    
    mov cx, offset end9 - offset introut9 
    ; 代码长度
    lea si, introut9 
    ; 源偏移地址                             
    mov ax, 0
    mov es, ax
    ; 目标段设置为 0
    mov di, 200h
    ; 目标偏移地址设置为 200h

    call install 
    ; 调用安装程序
    ; 安装源代码到目标地址上

    call save_old_9
    ; 保持原 9 号中断
    call set_introut9
    ; 修改 9 号中断指向 0:200h

    lea dx, STR
    int 9
    ; 中断

    call  set_old_9
    ; 恢复原 9 号中断

    mov ax, 4c00h
    int 21H

    install proc
    ; 安装程序
    ; 参数 cx -> 代码长度
    ; 参数 es -> 目标段地址
    ; 参数 di -> 目标偏移地址
    ; 参数 si -> 源偏移地址

    push ax        ; 保持ax
    mov ax, ds    
    push ax        ; 保持ds

    mov ax, cs
    mov ds, ax    ; cs -> ax -> ds

    cld
    rep movsb     ; 赋值代码
    
    pop ax           
    mov ds, ax     ; 恢复ds
    pop ax           ; 恢复ax
    ret
    endp

    set_introut9 proc
    ; 修改 9 号中断指向 0:200h
    mov word ptr es:[9*4], 200h
    mov word ptr es:[9*4+2],  0h
    ret
    endp

    save_old_9 proc  
    ; 保持原 9 号中断
    pop ax               ; 保持 call 压栈的 cs
    pop bx               ; 保持 call 压栈的 ip
    push es:[9*4]    ; 将原 9 号中断压栈
    push es:[9*4+2]
    push bx             ; 恢复 ip
    push ax             ; 恢复 cs
    ret
    endp

    set_old_9  proc
    ; 恢复原 9 号中断
    pop ax               ; 保持 call 压栈的 cs
    pop dx               ; 保持 call 压栈的 ip
    pop es:[9*4+2]  ; 恢复原 9 号中断
    pop es:[9*4]
    push dx             ; 恢复 ip
    push ax             ; 恢复 cs
    ret
    endp

    introut9 proc      
    ; 自定义的 9 号中断
    ; 输出 "DIY int 9"
    push ax
    pushf

    mov ax, 0900h
    int 21H

    popf
    pop ax
    iret
    endp
    end9:
    nop

codeseg ends
end start