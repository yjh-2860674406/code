dataseg segment
    STRBIG      db "ABDEFGHIJKLMNOPQRSTUVWXYZ", 0ah, 0dh, '$'
    STRSMALL db "abcdefghijklmnopqrstuvwxyz", 0ah, 0dh, '$'
dataseg ends

stackseg segment
    db 218 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg

    movestr macro strN, dstr, sstr
    push cx
    push ax
    ; 保持现场
    mov cx, strN ; 循环次数
    lea si, sstr     ; 起始地址
    lea di, dstr    ; 起始地址
    l:
    mov al, [si]    ; [si] -> al -> di
    mov [di], al
    inc di            ; di++
    inc si            ; si++
    loop l                         
    ; 恢复现场
    pop ax
    pop cx
    endm

    start:
    mov ax, dataseg
    mov ds, ax
    mov es, ax
    mov ax, stackseg
    mov ss, ax

    movestr 10, STRSMALL, STRBIG
       
codeseg ends
end start