	section		.data
prompt:	db "Enter a number: "
buff:	resb 51
	
	section		.text		; this is a comment
	global		_start
	extern		printChar
	extern		printRAX
_start:
	; print prompt
	mov		edx, buff-prompt
	mov		ecx, prompt
	mov		eax, 4
	mov		ebx, 1
	int		0x80

	; read from keyboard (stdin=0), no more than 51 bytes (chars)
	mov		eax, 3
	mov		ebx, 0
	mov		ecx, buff
	mov		edx, 51
	int		0x80

	;;  when done with int 0x80, # chars read is in rax
	mov		rcx, rax
	dec		rcx	; skip the newline
	
	mov		rbx, 0	; start at beginning of string read.

	mov		rdx, 0  ; rdx will be sum, initialize to 0
	
nextDigit:
	;;  want 	rdx+= al ;CHALLENGE FOR BREAK !!!! 
	
	;mov		al, [buff+rbx] 
	;call		printChar

	inc 		rbx
	dec 		rcx

	cmp		rcx, 0
	jne		nextDigit

	mov		rax, rdx
	call		printRAX
	
	;  return to linux
	mov		eax, 1
	mov		ebx, 0
	int		0x80
