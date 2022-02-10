	.file	"test.c"
	.comm	a,4,4
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1
	.globl	t00
	.data
	.align 4
	.type	t00, @object
	.size	t00, 4
t00:
	.long	1
	.comm	c,1,1
	.globl	d
	.type	d, @object
	.size	d, 1
d:
	.byte	0
	.globl	t01
	.type	t01, @object
	.size	t01, 1
t01:
	.byte	0
	.section	.rodata
.LC0:
	.string	" Called function \n"
.LC1:
	.string	"  Return to function caller\n"
.LC2:
	.string	"\n Multiplication of two numbers:\n\n"
.LC3:
	.string	"\n    Enter first numbers  : "
.LC4:
	.string	"    Enter second numbers : "
.LC5:
	.string	"\n  colling function mult\n"
.LC6:
	.string	"\n  Product is equal to : "
.LC7:
	.string	"\n"
	.text	
	movl	$1, %eax
	movl 	%eax, 0(%rbp)
	movl	0(%rbp), %eax
	movl 	%eax, 0(%rbp)
	movb	$0, 0(%rbp)
	movl	0(%rbp), %eax
	movl 	%eax, 0(%rbp)
	.globl	mult
	.type	mult, @function
mult: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$68, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq 	$.LC0, -36(%rbp)
	movl 	-36(%rbp), %eax
	movq 	-36(%rbp), %rdi
	call	printStr
	movl	%eax, -40(%rbp)
	movl 	-20(%rbp), %eax
	imull 	-16(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	$.LC1, -52(%rbp)
	movl 	-52(%rbp), %eax
	movq 	-52(%rbp), %rdi
	call	printStr
	movl	%eax, -56(%rbp)
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	mult, .-mult
	.globl	main
	.type	main, @function
main: 
.LFB1:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$200, %rsp

	movl	$2, %eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$10, %eax
	movl 	%eax, -76(%rbp)
	movq 	$.LC2, -104(%rbp)
	movl 	-104(%rbp), %eax
	movq 	-104(%rbp), %rdi
	call	printStr
	movl	%eax, -108(%rbp)
	movq 	$.LC3, -112(%rbp)
	movl 	-112(%rbp), %eax
	movq 	-112(%rbp), %rdi
	call	printStr
	movl	%eax, -116(%rbp)
	leaq	-96(%rbp), %rax
	movq 	%rax, -124(%rbp)
	movl 	-124(%rbp), %eax
	movq 	-124(%rbp), %rdi
	call	readInt
	movl	%eax, -128(%rbp)
	movl	-128(%rbp), %eax
	movl 	%eax, -84(%rbp)
	movq 	$.LC4, -136(%rbp)
	movl 	-136(%rbp), %eax
	movq 	-136(%rbp), %rdi
	call	printStr
	movl	%eax, -140(%rbp)
	leaq	-96(%rbp), %rax
	movq 	%rax, -144(%rbp)
	movl 	-144(%rbp), %eax
	movq 	-144(%rbp), %rdi
	call	readInt
	movl	%eax, -148(%rbp)
	movl	-148(%rbp), %eax
	movl 	%eax, -88(%rbp)
	movq 	$.LC5, -156(%rbp)
	movl 	-156(%rbp), %eax
	movq 	-156(%rbp), %rdi
	call	printStr
	movl	%eax, -160(%rbp)
	movl 	-84(%rbp), %eax
	movq 	-84(%rbp), %rdi
movl 	-88(%rbp), %eax
	movq 	-88(%rbp), %rsi
	call	mult
	movl	%eax, -168(%rbp)
	movl	-168(%rbp), %eax
	movl 	%eax, -92(%rbp)
	movq 	$.LC6, -176(%rbp)
	movl 	-176(%rbp), %eax
	movq 	-176(%rbp), %rdi
	call	printStr
	movl	%eax, -180(%rbp)
	movl 	-92(%rbp), %eax
	movq 	-92(%rbp), %rdi
	call	printInt
	movl	%eax, -188(%rbp)
	movq 	$.LC7, -192(%rbp)
	movl 	-192(%rbp), %eax
	movq 	-192(%rbp), %rdi
	call	printStr
	movl	%eax, -196(%rbp)
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 19CS10060_19CS10039"
	.section	.note.GNU-stack,"",@progbits
