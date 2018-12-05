00000000  EB63              jmp short 0x65
00000002  90                nop
00000003  D0BC007C          sar byte [si+0x7c00],1
00000007  8EC0              mov es,ax
00000009  8ED8              mov ds,ax
0000000B  BE007C            mov si,0x7c00
0000000E  BF0006            mov di,0x600
00000011  B90002            mov cx,0x200
00000014  FC                cld
00000015  F3A4              rep movsb
00000017  50                push ax
00000018  681C06            push word 0x61c
0000001B  CB                retf
0000001C  FB                sti
0000001D  B90400            mov cx,0x4
00000020  BDBE07            mov bp,0x7be
00000023  807E0000          cmp byte [bp+0x0],0x0
00000027  7C0B              jl 0x34
00000029  0F850E01          jnz near 0x13b
0000002D  83C510            add bp,byte +0x10
00000030  E2F1              loop 0x23
00000032  CD18              int 0x18
00000034  885600            mov [bp+0x0],dl
00000037  55                push bp
00000038  C6461105          mov byte [bp+0x11],0x5
0000003C  C6460302          mov byte [bp+0x3],0x2
00000040  FF00              inc word [bx+si]
00000042  0020              add [bx+si],ah
00000044  0100              add [bx+si],ax
00000046  0000              add [bx+si],al
00000048  0002              add [bp+si],al
0000004A  FA                cli
0000004B  90                nop
0000004C  90                nop
0000004D  F6C280            test dl,0x80
00000050  7502              jnz 0x54
00000052  B280              mov dl,0x80
00000054  EA597C0000        jmp 0x0:0x7c59
00000059  3100              xor [bx+si],ax
0000005B  800100            add byte [bx+di],0x0
0000005E  0000              add [bx+si],al
00000060  0000              add [bx+si],al
00000062  0000              add [bx+si],al
00000064  FF                db 0xff
00000065  FA                cli
00000066  90                nop
00000067  90                nop
00000068  F6C280            test dl,0x80
0000006B  7405              jz 0x72
0000006D  F6C270            test dl,0x70
00000070  7402              jz 0x74
00000072  B280              mov dl,0x80
00000074  EA797C0000        jmp 0x0:0x7c79
00000079  31C0              xor ax,ax
0000007B  8ED8              mov ds,ax
0000007D  8ED0              mov ss,ax
0000007F  BC0020            mov sp,0x2000
00000082  FB                sti
00000083  A0647C            mov al,[0x7c64]
00000086  3CFF              cmp al,0xff
00000088  7402              jz 0x8c
0000008A  88C2              mov dl,al
0000008C  52                push dx
0000008D  BE807D            mov si,0x7d80
00000090  E81701            call 0x1aa
00000093  BE057C            mov si,0x7c05
00000096  B441              mov ah,0x41
00000098  BBAA55            mov bx,0x55aa
0000009B  CD13              int 0x13
0000009D  5A                pop dx
0000009E  52                push dx
0000009F  723D              jc 0xde
000000A1  81FB55AA          cmp bx,0xaa55
000000A5  7537              jnz 0xde
000000A7  83E101            and cx,byte +0x1
000000AA  7432              jz 0xde
000000AC  31C0              xor ax,ax
000000AE  894404            mov [si+0x4],ax
000000B1  40                inc ax
000000B2  8844FF            mov [si-0x1],al
000000B5  894402            mov [si+0x2],ax
000000B8  C7041000          mov word [si],0x10
000000BC  668B1E5C7C        mov ebx,[0x7c5c]
000000C1  66895C08          mov [si+0x8],ebx
000000C5  668B1E607C        mov ebx,[0x7c60]
000000CA  66895C0C          mov [si+0xc],ebx
000000CE  C744060070        mov word [si+0x6],0x7000
000000D3  B442              mov ah,0x42
000000D5  CD13              int 0x13
000000D7  7205              jc 0xde
000000D9  BB0070            mov bx,0x7000
000000DC  EB76              jmp short 0x154
000000DE  B408              mov ah,0x8
000000E0  CD13              int 0x13
000000E2  730D              jnc 0xf1
000000E4  5A                pop dx
000000E5  84D2              test dl,dl
000000E7  0F83D800          jnc near 0x1c3
000000EB  BE8B7D            mov si,0x7d8b
000000EE  E98200            jmp 0x173
000000F1  660FB6C6          movzx eax,dh
000000F5  8864FF            mov [si-0x1],ah
000000F8  40                inc ax
000000F9  66894404          mov [si+0x4],eax
000000FD  0FB6D1            movzx dx,cl
00000100  C1E202            shl dx,byte 0x2
00000103  88E8              mov al,ch
00000105  88F4              mov ah,dh
00000107  40                inc ax
00000108  894408            mov [si+0x8],ax
0000010B  0FB6C2            movzx ax,dl
0000010E  C0E802            shr al,byte 0x2
00000111  668904            mov [si],eax
00000114  66A1607C          mov eax,[0x7c60]
00000118  6609C0            or eax,eax
0000011B  754E              jnz 0x16b
0000011D  66A15C7C          mov eax,[0x7c5c]
00000121  6631D2            xor edx,edx
00000124  66F734            div dword [si]
00000127  88D1              mov cl,dl
00000129  31D2              xor dx,dx
0000012B  66F77404          div dword [si+0x4]
0000012F  3B4408            cmp ax,[si+0x8]
00000132  7D37              jnl 0x16b
00000134  FEC1              inc cl
00000136  88C5              mov ch,al
00000138  30C0              xor al,al
0000013A  C1E802            shr ax,byte 0x2
0000013D  08C1              or cl,al
0000013F  88D0              mov al,dl
00000141  5A                pop dx
00000142  88C6              mov dh,al
00000144  BB0070            mov bx,0x7000
00000147  8EC3              mov es,bx
00000149  31DB              xor bx,bx
0000014B  B80102            mov ax,0x201
0000014E  CD13              int 0x13
00000150  721E              jc 0x170
00000152  8CC3              mov bx,es
00000154  60                pusha
00000155  1E                push ds
00000156  B90001            mov cx,0x100
00000159  8EDB              mov ds,bx
0000015B  31F6              xor si,si
0000015D  BF0080            mov di,0x8000
00000160  8EC6              mov es,si
00000162  FC                cld
00000163  F3A5              rep movsw
00000165  1F                pop ds
00000166  61                popa
00000167  FF265A7C          jmp [0x7c5a]
0000016B  BE867D            mov si,0x7d86
0000016E  EB03              jmp short 0x173
00000170  BE957D            mov si,0x7d95
00000173  E83400            call 0x1aa
00000176  BE9A7D            mov si,0x7d9a
00000179  E82E00            call 0x1aa
0000017C  CD18              int 0x18
0000017E  EBFE              jmp short 0x17e
00000180  47                inc di
00000181  52                push dx
00000182  55                push bp
00000183  42                inc dx
00000184  2000              and [bx+si],al
00000186  47                inc di
00000187  656F              gs outsw
00000189  6D                insw
0000018A  004861            add [bx+si+0x61],cl
0000018D  7264              jc 0x1f3
0000018F  204469            and [si+0x69],al
00000192  736B              jnc 0x1ff
00000194  005265            add [bp+si+0x65],dl
00000197  61                popa
00000198  640020            add [fs:bx+si],ah
0000019B  45                inc bp
0000019C  7272              jc 0x210
0000019E  6F                outsw
0000019F  720D              jc 0x1ae
000001A1  0A00              or al,[bx+si]
000001A3  BB0100            mov bx,0x1
000001A6  B40E              mov ah,0xe
000001A8  CD10              int 0x10
000001AA  AC                lodsb
000001AB  3C00              cmp al,0x0
000001AD  75F4              jnz 0x1a3
000001AF  C3                ret
000001B0  0000              add [bx+si],al
000001B2  0000              add [bx+si],al
000001B4  0000              add [bx+si],al
000001B6  0000              add [bx+si],al
000001B8  13901390          adc dx,[bx+si-0x6fed]
000001BC  0000              add [bx+si],al
