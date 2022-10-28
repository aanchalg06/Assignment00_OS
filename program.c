section .data
text1 db "Enter number: ", 0
text2 db "Enter string: ", 0
text3 db "Number is: %d", 0x0a, 0
text4 db "String is: %s", 0x0a, 0
format1 db "%d", 0
format2 db "%s", 0
num dq 0
string db ""


section .text
global _start
extern printf
extern scanf
_start:
	;push rbp
	;mov rbp, rsp

	;print text1
	xor eax, eax
	lea rdi, [text1]
	call printf

	;scan number
	mov eax, 0
	lea rdi, [format1]
	lea rsi, [num]
	call scanf
	
	;print number
	lea rdi, [text3]
	mov rsi, [num]
	xor eax, eax
	call printf

	;print text2
	lea rdi, [text2]
	xor eax, eax
	call printf

	;scan string
	mov eax, 0
	lea rdi, [format2]
	lea rsi, [string]
	call scanf

	;print string
	lea rdi, [text4]
	lea rsi, [string]
	xor eax, eax
	call printf

	; exiting
	mov rax, 1
	mov rbx, 0
	int 0x80
