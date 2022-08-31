dataseg segment

dataseg ends

stackseg segment
    db 218 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg

    move macro doprnd, soprnd
    push ax
    mov ax, soprnd ; soprnd -> ax -> doprnd
    mov doprnd, ax
    pop ax
    endm

    start:
    mov ax, dataseg
    mov ds, ax
    mov ax, stackseg
    mov ss, ax

    mov bx, 10
    mov cx, 15
    move bx, cx
       
codeseg ends
end start