.global _start

_start:
	
	ldr	r0, =0xE2700000				
	mov	r1, #0
	str	r1, [r0]

	ldr	sp, =0xD0037D80	

	bl	main			

halt:
	b halt

