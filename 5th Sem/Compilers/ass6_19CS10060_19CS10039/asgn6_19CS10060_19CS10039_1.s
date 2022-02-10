	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"\n\n\n********* Multiplying two numbers a and b *********\n"
.LC1:
	.string	"a = "
.LC2:
	.string	"b = "
.LC3:
	.string	"Product = "
.LC4:
	.string	"\n"
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
	subq	$140, %rsp

	movl	$10, %eax
	movl 	%eax, -40(%rbp)
	negl	-40(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -36(%rbp)
	leaq	-36(%rbp), %rax
	movq 	%rax, -52(%rbp)
	movl	-52(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movq 	$.LC0, -64(%rbp)
	movl 	-64(%rbp), %eax
	movq 	-64(%rbp), %rdi
	call	printStr
	movl	%eax, -68(%rbp)
	movq 	$.LC1, -72(%rbp)
	movl 	-72(%rbp), %eax
	movq 	-72(%rbp), %rdi
	call	printStr
	movl	%eax, -76(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
	call	readInt
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	$.LC2, -92(%rbp)
	movl 	-92(%rbp), %eax
	movq 	-92(%rbp), %rdi
	call	printStr
	movl	%eax, -96(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
	call	readInt
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	movl 	%eax, -28(%rbp)
	movq 	$.LC3, -108(%rbp)
	movl 	-108(%rbp), %eax
	movq 	-108(%rbp), %rdi
	call	printStr
	movl	%eax, -112(%rbp)
	movl 	-24(%rbp), %eax
	imull 	-28(%rbp), %eax
	movl 	%eax, -120(%rbp)
	movl 	-120(%rbp), %eax
	movq 	-120(%rbp), %rdi
	call	printInt
	movl	%eax, -124(%rbp)
	movq 	$.LC4, -128(%rbp)
	movl 	-128(%rbp), %eax
	movq 	-128(%rbp), %rdi
	call	printStr
	movl	%eax, -132(%rbp)
	movl	$0, %eax
	movl 	%eax, -136(%rbp)
	movl	-136(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by 19CS10060_19CS10039"
	.section	.note.GNU-stack,"",@progbits
