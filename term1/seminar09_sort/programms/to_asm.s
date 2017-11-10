	.file	"to_asm.c"
	.text
	.p2align 4,,15
	.globl	add7
	.type	add7, @function
add7:
.LFB24:
	.cfi_startproc
	leal	7(%rdi), %eax
	ret
	.cfi_endproc
.LFE24:
	.size	add7, .-add7
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	movl	$49, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	jmp	__printf_chk
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
