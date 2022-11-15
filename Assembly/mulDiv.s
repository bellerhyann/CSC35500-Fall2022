	section		.data
prompt:	db "Enter a string: "
buff:	resb 100
	
	section		.text		; this is a comment
	global		_start
_start:
	;eax*ebx
	mov	eax, -1
	mov	ebx, 1
	mov	edx, 0x1234
	;; 	mul 	ebx

	;;  eax/ebx
	mov 	eax,-127
	mov	ebx, 10
	xor 	edx, edx 	; neat way to make edx 0 (for unsigned div)
	cdq			; convert eax into [edx:eax] (for signed idiv)
	idiv 	ebx		
	
	;  return to linux
	mov		eax, 1
	mov		ebx, 0
	int		0x80
