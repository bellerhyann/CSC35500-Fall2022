	section		.data
hello:	db "Hello World!", 0xA
	
	section		.text		; this is a comment
	global		_start
_start:
	mov		edx, 14
	mov		ecx, hello
	mov		eax, 4
	mov		ebx, 1
	int		0x80
	
	mov		eax, 1
	mov		ebx, 0
	int		0x80
