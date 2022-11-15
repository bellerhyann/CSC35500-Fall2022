	section	.data
lbl:	resb	0x1		;trying to print 1 char as a string

	section	.text
	global	printChar

printChar:
	;;  get AL into the string starting at lbl
	mov	[lbl], al

	;; print out string
	mov	eax, 4		;Linux syscall #4 is print string
	mov	ebx, 1		;tell Linux syscall where to print (1=stdout)
	mov	ecx, lbl	;store address of string for Linux syscall
	mov	edx, 1		; print 1 character
	int	0x80 		;ask Linux to do something for me

	;; holy printing, batman! We're done!
	
	ret
