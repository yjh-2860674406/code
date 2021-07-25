assume cs:codes

codes segment

start :
        mov ax,0h
        mov ds,ax
        mov bx,26h
        mov [bx],ax

        mov ax, 4C00H
        int 21H

codes ends

end start