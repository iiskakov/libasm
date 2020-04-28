; method from this thread: https://stackoverflow.com/questions/26783797/repnz-scas-assembly-instruction-specifics

global	_ft_strlen
	; int strlen(const char *string);
_ft_strlen:
  push rbp
  push rdi
  push r8

  mov   r8, rdi            
  xor   al, al                               
  mov   rcx, -1				; overflowing rcx here so it never reaches 0
                                                     
  repne scasb               ; REPeat while Not Equal [rdi] != al

  sub   rdi, r8            ; length = offset of (rdi - rbx)
  mov   rax, rdi            
  sub   rax,1               ; decrementing 1 for '\0' character

  pop r8
  pop rdi
  pop rbp

  ret                 
