dataseg segment

dataseg ends

stackseg segment
    db 218 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg, ds:dataseg, ss:stackseg

    logical macro lop, doprd, soprd
        lop doprd, soprd
    endm

    start:
    mov ax, dataseg
    mov ds, ax
    mov ax, stackseg
    mov ss, ax

    mov ax, 7
    mov bx, 3
       
    logical and, ax, bx

codeseg ends
end start