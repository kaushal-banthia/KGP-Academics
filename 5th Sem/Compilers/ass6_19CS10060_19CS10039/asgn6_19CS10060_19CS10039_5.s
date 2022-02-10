	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"\n\n\n**** Factorial of a numbers ****\n"
.LC1:
	.string	"Enter the number : "
.LC2:
	.string	"The value of n! is: "
.LC3:
	.string	"\n"
	.text	
	.globl	factorial
	.type	factorial, @function
factorial: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$84, %rsp
	movq	%rdi, -20(%rbp)
	movl	$1, %eax
	movl 	%eax, -28(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jle .L2
	jmp .L6
	jmp .L7
.L2: 
	movl	$0, %eax
	movl 	%eax, -32(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl .L3
	jmp .L4
	jmp .L5
.L3: 
	movl	$1, %eax
	movl 	%eax, -36(%rbp)
	negl	-36(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -24(%rbp)
	jmp .L7
.L4: 
	movl	$1, %eax
	movl 	%eax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl 	%eax, -24(%rbp)
.L5: 
	jmp .L7
.L6: 
	movl	$1, %eax
	movl 	%eax, -60(%rbp)
	movl 	-20(%rbp), %eax
	movl 	-60(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -64(%rbp)
	movl 	-64(%rbp), %eax
	movq 	-64(%rbp), %rdi
	call	factorial
	movl	%eax, -68(%rbp)
	movl 	-20(%rbp), %eax
	imull 	-68(%rbp), %eax
	movl 	%eax, -72(%rbp)
	movl	-72(%rbp), %eax
	movl 	%eax, -24(%rbp)
.L7: 
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	factorial, .-factorial
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
	subq	$320, %rsp

	movl	$50, %eax
	movl 	%eax, -228(%rbp)
	movq 	$.LC0, -248(%rbp)
	movl 	-248(%rbp), %eax
	movq 	-248(%rbp), %rdi
	call	printStr
	movl	%eax, -252(%rbp)
	movq 	$.LC1, -256(%rbp)
	movl 	-256(%rbp), %eax
	movq 	-256(%rbp), %rdi
	call	printStr
	movl	%eax, -260(%rbp)
	leaq	-236(%rbp), %rax
	movq 	%rax, -268(%rbp)
	movl 	-268(%rbp), %eax
	movq 	-268(%rbp), %rdi
	call	readInt
	movl	%eax, -272(%rbp)
	movl	-272(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	$.LC2, -280(%rbp)
	movl 	-280(%rbp), %eax
	movq 	-280(%rbp), %rdi
	call	printStr
	movl	%eax, -284(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
	call	factorial
	movl	%eax, -292(%rbp)
	movl	-292(%rbp), %eax
	movl 	%eax, -240(%rbp)
	movl 	-240(%rbp), %eax
	movq 	-240(%rbp), %rdi
	call	printInt
	movl	%eax, -304(%rbp)
	movq 	$.LC3, -308(%rbp)
	movl 	-308(%rbp), %eax
	movq 	-308(%rbp), %rdi
	call	printStr
	movl	%eax, -312(%rbp)
	movl	$0, %eax
	movl 	%eax, -316(%rbp)
	movl	-316(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 19CS10060_19CS10039"
	.section	.note.GNU-stack,"",@progbits
