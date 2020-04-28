global _ft_strdup
extern _malloc, _ft_strlen, _ft_strcpy

section .text

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je noalloc
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

noalloc:
	mov rax, 1
	pop rdi
	ret
