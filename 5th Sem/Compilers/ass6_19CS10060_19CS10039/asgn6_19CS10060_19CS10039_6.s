	.file	"test.c"
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	10
	.globl	t00
	.data
	.align 4
	.type	t00, @object
	.size	t00, 4
t00:
	.long	10
	.comm	q,4,4
	.comm	c,1,1
	.globl	t01
	.data
	.align 4
	.type	t01, @object
	.size	t01, 4
t01:
	.long	10
	.globl	t02
	.data
	.align 4
	.type	t02, @object
	.size	t02, 4
t02:
	.long	5
	.globl	t03
	.data
	.align 4
	.type	t03, @object
	.size	t03, 4
t03:
	.long	10
	.text	
	movl	$10, %eax
	movl 	%eax, 0(%rbp)
	movl	0(%rbp), %eax
	movl 	%eax, 0(%rbp)
	movl	$10, %eax
	movl 	%eax, 0(%rbp)
	movl	$5, %eax
	movl 	%eax, 0(%rbp)
	movl	$10, %eax
	movl 	%eax, 0(%rbp)
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
	subq	$108, %rsp

	movl	$120, %eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$17, %eax
	movl 	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movb	$0, -69(%rbp)
	movl	-69(%rbp), %eax
	movl 	%eax, -68(%rbp)
	movb	$0, -71(%rbp)
	movl	-71(%rbp), %eax
	movl 	%eax, -70(%rbp)
	movl 	-72(%rbp), %eax
	movl 	-32(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -76(%rbp)
	movl	-76(%rbp), %eax
	movl 	%eax, -40(%rbp)
	movl 	-72(%rbp), %eax
	movl 	-32(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl 	-72(%rbp), %eax
	imull 	-32(%rbp), %eax
	movl 	%eax, -92(%rbp)
	movl	-92(%rbp), %eax
	movl 	%eax, -48(%rbp)
	movl 	-72(%rbp), %eax
	cltd
	idivl 	-32(%rbp)
	movl 	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	movl 	%eax, -52(%rbp)
	movl	$0, %eax
	movl 	%eax, -108(%rbp)
	movl	-108(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by 19CS10060_19CS10039"
	.section	.note.GNU-stack,"",@progbits
