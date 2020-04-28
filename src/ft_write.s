BITS 64     ; http://caswenson.com/2018_02_06_64bit_assembly_language_programming_under_macos_with_nasm.html
DEFAULT REL ; RIP-relative addressing by default

; libc stuff
extern  ___error

section .text

global _ft_write

_ft_write:
        push rbp
        push r12
        push rbx

		cmp rsi, byte 0x0 ; NULL pointer
		jz null
		mov rax, 0x2000004
		syscall
		jc error_exit     ; https://stackoverflow.com/questions/47834513/64-bit-syscall-documentation-for-macos-assembly

        pop rbx
        pop r12
        pop rbp
        ret

error_exit:
        mov  rdi, rax
		call ___error
		mov dword [rax], edi
		mov rax, -1
        pop rbx
        pop r12
        pop rbp
        ret

		
null:
		mov rax, -1 ; return -1 because error
        pop rbx
        pop r12
        pop rbp
        ret

