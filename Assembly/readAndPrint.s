	section		.data
prompt:	db "Enter a string: "
buff:	resb 100
	
	section		.text		; this is a comment
	global		_start
_start:
	; print prompt
	mov		edx, buff-prompt
	mov		ecx, prompt
	mov		eax, 4
	mov		ebx, 1
	int		0x80

	; read from keyboard (stdin=0), no more than 100 bytes (chars)
	mov		eax, 3
	mov		ebx, 0
	mov		ecx, buff
	mov		edx, 100
	int		0x80

	; print out what we read. 
	mov		edx, eax
	mov		ecx, buff
	mov		eax, 4
	mov		ebx, 1
	int		0x80

	
	;  return to linux
	mov		eax, 1
	mov		ebx, 0
	int		0x80
