

__start:
	mov eax, 1
	mov ebx, 2
	push ebx
	push eax
	pop ebx
	pop eax
	syscall

.message: