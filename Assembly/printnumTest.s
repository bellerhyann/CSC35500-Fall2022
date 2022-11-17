	section	.text
	global	_start
	extern	printRAX

_start:
	mov	rax, 123456		; put any number you want into RAX
	call 	printRAX

	mov	rax, 1
	mov	rbx, 0
	int 	0x80
	

	
