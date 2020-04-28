; method from this thread: https://stackoverflow.com/questions/26783797/repnz-scas-assembly-instruction-specifics

global	_ft_strcmp
_ft_strcmp:
  push rbp
  push rcx
  push r10
  push r9
  push r8

  extern _ft_strlen
  call _ft_strlen
  mov r9, rax     ; len(1st arg) rdi
  mov r8, rdi     ; 1st string
  
  mov rdi, rsi
  call _ft_strlen
  mov r10, rax     ; len(2st arg) rsi
  cmp r9, r10
  cmovb rcx, r9
  cmovae rcx, r10


  mov rdi, r8
  repe	cmpsb 
  jb lower
  ja higher

  xor rax, rax

  pop r8
  pop r9
  pop r10
  pop rcx
  pop rbp
  ret

lower:
  mov rax, 1
  pop r8
  pop r9
  pop r10
  pop rcx
  pop rbp
  ret

higher:
  mov rax, -1
  pop r8
  pop r9
  pop r10
  pop rcx
  pop rbp
  ret

