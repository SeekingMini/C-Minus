SECTION .data
                                                
ReturnMsg: db "Return Value:%i", 10, 0

SECTION .text
extern printf
global factorial
factorial:
push ebp
mov ebp, esp
push ebx
push esi
push edi
sub esp, 16

mov eax, 4
mov [ebp-12], eax
mov eax, 44
mov [ebp-16], eax
mov eax, [ebp+8]
mov ebx, 1
cmp eax, ebx
je Equ0
mov eax, 0
jmp EndEqu0
Equ0:
mov eax, 1
EndEqu0:
cmp eax, 1
jne EndIf1
mov eax, 1

;Print return value
push eax
push ReturnMsg
call printf
add esp, 4
pop eax
pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp
ret

jmp EndIfElse1
EndIf1:
mov eax, [ebp+8]
mov ebx, [ebp+8]
mov ecx, 1
sub ebx, ecx

;Before call
;Save required resgisters
push eax
;Push params
push ebx
call factorial

;After call
;Store return value
mov ebx, eax

;Clear stack of params
add esp, 4

;Restore used resgisters
pop eax

imul eax, ebx

;Print return value
push eax
push ReturnMsg
call printf
add esp, 4
pop eax
pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp
ret

EndIfElse1:
global main
main:
push ebp
mov ebp, esp
push ebx
push esi
push edi
sub esp, 16

