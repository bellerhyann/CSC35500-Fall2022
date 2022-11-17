	section	.text
	global	printRAX
	extern	printChar
printRAX:
	;; back up registers we are going to utilize
	push	rax
	push	rbx
	push	rcx

	
	;; number we want to print is in rax


	cmp	rax, 0x0
	jge	printUnsigned

	;; deal with the "negativeness" of the number
	push	rax
	mov	al, '-'
	call	printChar
	pop	rax
	
	neg	rax
	
printUnsigned:	
	xor	rcx, rcx	; initial count of digits is 0
	
extractNextDigit:	
	;; want to do rax % 10 ...
	mov	rbx, 0xA
	mov	rdx, 0
	div	rbx		; after this, rdx has remainder, rax has quotient

	;;  remember the digit for later processing ...
	push	rdx
	inc	rcx		; saw one more digit to print
	
	cmp	rax, 0x0
	jne	extractNextDigit

printNextDigit:
	;; extract next digit from stack into al
	pop	rax
	
	;; print out the next dogit as a character
	add	al, '0'
	call	printChar

	dec 	rcx
	cmp	rcx, 0
	jne	printNextDigit

	;; restore registers we pushed at start of function
	pop	rcx
	pop	rbx
	pop	rax
	
	ret
