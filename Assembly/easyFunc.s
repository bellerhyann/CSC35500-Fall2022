	section .text
	global _start
	extern add2ToRAX

_start:
	mov	rax, 5
	call	add2ToRAX

	mov	rax,1
	mov	ebx,1
	int	0x80
	
