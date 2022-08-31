assume cs:codeseg,ds:dataseg,ss:stackseg

dataseg segment
    o db "Please Input a String：", 0dh, 0ah, '$'
    i db 100, 0, 100 dup(0)
    e db 0dh, 0ah, '$'
dataseg ends

stackseg segment
    dw 0, 0
stackseg ends

codeseg segment
start:
    mov ax, dataseg
    mov ds, ax
    mov ax, stackseg
    mov ss, ax
    mov dx, offset o ; 输出提示
    mov ah, 09h
    int 21H

    lea dx, i        ; 输入字符串
    mov ah, 0Ah
    int 21H

    mov bx, dx
    inc bx

    mov cx, 0
    mov cl, [bx] ; 字符串长度 
    inc bx

    l1:          ; 第一层循环
    push cx      ; 保持cx
    sub cx, 1      
    cmp cx, 0
    jz res  
    mov si, bx   ; bx 为 i; 第一层循环
    inc si       ; j = i+1
    mov al, [bx] ; min = nums[i] 初始化min
    mov di, bx   ; index = i 用来存储最小值下标
    l2:          ; 第二层循环
    cmp [si], al ; if (nums[j] < min)  
    jb below     
    continue:    
    inc si       ; j++
    loop l2
    mov ah, [bx] ; min 为最小值，index为其下标
    mov [di], ah ; nums[i] = min
    mov [bx], al ; nums[index] = nums[i]
    inc bx       ; i++
    pop cx       ; 恢复cx
    loop l1
   
    res:
    lea di, i     ; 准备输出相同的值
    inc i
    inc i

    xor cx, cx

    l5:
    inc cx
    mov al, [di]     
    inc di
    cmp al, 0
    jne l5          ; 查找循环多少次,即有多少个相同的值
        
    mov bx, offset i
    inc bx
    inc bx
    
    lea dx, e
    mov ah, 9
    int 21H

    l6:                 ; 输出
    mov dh, 0
    mov dl, [bx]
    inc bx
    mov ah, 2
    int 21H
    loop l6

    mov ah, 9
    lea dx, e
    int 21H

    loop l6

    mov ax, 4c00h
    int 21H

    below:       
    mov al, [si] ; min = nums[j]
    mov di, si   ; index = j
    jmp continue

codeseg ends
end start