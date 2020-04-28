; method from this thread: https://stackoverflow.com/questions/26783797/repnz-scas-assembly-instruction-specifics

  SECTION .text

  extern puts
global	_ft_strcpy
	; char *strcpy(char * dst, const char * src);
_ft_strcpy:
  push	rbp
  mov rax,rdi    ; save dest pointer to return it later

next:
  cmp byte [rsi],0
  je end
  mov cl,[rsi]  
  mov [rdi],cl  
  inc rdi
  inc rsi
  jmp next

end:
  mov [rdi], byte 0

  pop rbp
  ret    


