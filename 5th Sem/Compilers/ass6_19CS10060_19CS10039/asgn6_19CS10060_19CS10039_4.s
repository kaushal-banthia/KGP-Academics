	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"\n\n\n*********** Finding nth fibonacci number ***********\n"
.LC1:
	.string	"Enter n (n>0) = "
.LC2:
	.string	"nth fibonacci number is 1.\n"
.LC3:
	.string	"nth fibonacci number is "
.LC4:
	.string	".\n"
	.text	
	.globl	main
	.type	main, @function
main: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$164, %rsp

	movl	$1, %eax
	movl 	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movl	$1, %eax
	movl 	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -40(%rbp)
	movq 	$.LC0, -60(%rbp)
	movl 	-60(%rbp), %eax
	movq 	-60(%rbp), %rdi
	call	printStr
	movl	%eax, -64(%rbp)
	movq 	$.LC1, -68(%rbp)
	movl 	-68(%rbp), %eax
	movq 	-68(%rbp), %rdi
	call	printStr
	movl	%eax, -72(%rbp)
	leaq	-24(%rbp), %rax
	movq 	%rax, -80(%rbp)
	movl 	-80(%rbp), %eax
	movq 	-80(%rbp), %rdi
	call	readInt
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	movl 	%eax, -28(%rbp)
	movl	$1, %eax
	movl 	%eax, -92(%rbp)
	movl	-28(%rbp), %eax
	cmpl	-92(%rbp), %eax
	je .L4
	jmp .L2
	jmp .L3
.L2: 
	movl	$2, %eax
	movl 	%eax, -96(%rbp)
	movl	-28(%rbp), %eax
	cmpl	-96(%rbp), %eax
	je .L4
	jmp .L5
.L3: 
	jmp .L10
.L4: 
	movq 	$.LC2, -100(%rbp)
	movl 	-100(%rbp), %eax
	movq 	-100(%rbp), %rdi
	call	printStr
	movl	%eax, -104(%rbp)
	jmp .L10
.L5: 
	movl	$2, %eax
	movl 	%eax, -108(%rbp)
	movl	-108(%rbp), %eax
	movl 	%eax, -52(%rbp)
.L6: 
	movl	-52(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl .L8
	jmp .L9
.L7: 
	movl	-52(%rbp), %eax
	movl 	%eax, -116(%rbp)
	addl 	$1, -52(%rbp)
	jmp .L6
.L8: 
	movl 	-32(%rbp), %eax
	movl 	-40(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -120(%rbp)
	movl	-120(%rbp), %eax
	movl 	%eax, -48(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movl	-48(%rbp), %eax
	movl 	%eax, -40(%rbp)
	jmp .L7
.L9: 
	movq 	$.LC3, -136(%rbp)
	movl 	-136(%rbp), %eax
	movq 	-136(%rbp), %rdi
	call	printStr
	movl	%eax, -140(%rbp)
	movl 	-48(%rbp), %eax
	movq 	-48(%rbp), %rdi
	call	printInt
	movl	%eax, -148(%rbp)
	movq 	$.LC4, -152(%rbp)
	movl 	-152(%rbp), %eax
	movq 	-152(%rbp), %rdi
	call	printStr
	movl	%eax, -156(%rbp)
.L10: 
	movl	$0, %eax
	movl 	%eax, -160(%rbp)
	movl	-160(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by 19CS10060_19CS10039"
	.section	.note.GNU-stack,"",@progbits
