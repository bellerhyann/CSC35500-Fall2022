	section	.text
	global	_start
	extern	printChar

_start:
	mov	al, '@'		; put any character you want into al
	call 	printChar

	mov	rax, 1
	mov	rbx, 0
	int 	0x80
	

	
