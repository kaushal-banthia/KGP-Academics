	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"\n Print diamond pattern  \n"
.LC1:
	.string	"Ennter size of the middle"
.LC2:
	.string	" "
.LC3:
	.string	"*"
.LC4:
	.string	"\n"
.LC5:
	.string	" "
.LC6:
	.string	"*"
.LC7:
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
	subq	$256, %rsp

	movq 	$.LC0, -32(%rbp)
	movl 	-32(%rbp), %eax
	movq 	-32(%rbp), %rdi
	call	printStr
	movl	%eax, -36(%rbp)
	movq 	$.LC1, -40(%rbp)
	movl 	-40(%rbp), %eax
	movq 	-40(%rbp), %rdi
	call	printStr
	movl	%eax, -44(%rbp)
	leaq	-24(%rbp), %rax
	movq 	%rax, -72(%rbp)
	movl 	-72(%rbp), %eax
	movq 	-72(%rbp), %rdi
	call	readInt
	movl	%eax, -76(%rbp)
	movl	-76(%rbp), %eax
	movl 	%eax, -52(%rbp)
	movl	$1, %eax
	movl 	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	movl 	%eax, -64(%rbp)
.L2: 
	movl	-64(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jle .L4
	jmp .L13
.L3: 
	movl	-64(%rbp), %eax
	movl 	%eax, -92(%rbp)
	addl 	$1, -64(%rbp)
	jmp .L2
.L4: 
	movl	$1, %eax
	movl 	%eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movl 	%eax, -48(%rbp)
.L5: 
	movl 	-52(%rbp), %eax
	movl 	-64(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -104(%rbp)
	movl	-48(%rbp), %eax
	cmpl	-104(%rbp), %eax
	jle .L7
	jmp .L8
.L6: 
	movl	-48(%rbp), %eax
	movl 	%eax, -108(%rbp)
	addl 	$1, -48(%rbp)
	jmp .L5
.L7: 
	movq 	$.LC2, -112(%rbp)
	movl 	-112(%rbp), %eax
	movq 	-112(%rbp), %rdi
	call	printStr
	movl	%eax, -116(%rbp)
	jmp .L6
.L8: 
	movl	$1, %eax
	movl 	%eax, -120(%rbp)
	movl	-120(%rbp), %eax
	movl 	%eax, -48(%rbp)
.L9: 
	movl	$2, %eax
	movl 	%eax, -128(%rbp)
	movl 	-128(%rbp), %eax
	imull 	-64(%rbp), %eax
	movl 	%eax, -132(%rbp)
	movl	$1, %eax
	movl 	%eax, -136(%rbp)
	movl 	-132(%rbp), %eax
	movl 	-136(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -140(%rbp)
	movl	-48(%rbp), %eax
	cmpl	-140(%rbp), %eax
	jle .L11
	jmp .L12
.L10: 
	movl	-48(%rbp), %eax
	movl 	%eax, -144(%rbp)
	addl 	$1, -48(%rbp)
	jmp .L9
.L11: 
	movq 	$.LC3, -148(%rbp)
	movl 	-148(%rbp), %eax
	movq 	-148(%rbp), %rdi
	call	printStr
	movl	%eax, -152(%rbp)
	jmp .L10
.L12: 
	movq 	$.LC4, -156(%rbp)
	movl 	-156(%rbp), %eax
	movq 	-156(%rbp), %rdi
	call	printStr
	movl	%eax, -160(%rbp)
	jmp .L3
.L13: 
	movl	$1, %eax
	movl 	%eax, -164(%rbp)
	movl	-164(%rbp), %eax
	movl 	%eax, -64(%rbp)
.L14: 
	movl	$1, %eax
	movl 	%eax, -172(%rbp)
	movl 	-52(%rbp), %eax
	movl 	-172(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -176(%rbp)
	movl	-64(%rbp), %eax
	cmpl	-176(%rbp), %eax
	jle .L16
	jmp .L25
.L15: 
	movl	-64(%rbp), %eax
	movl 	%eax, -180(%rbp)
	addl 	$1, -64(%rbp)
	jmp .L14
.L16: 
	movl	$1, %eax
	movl 	%eax, -184(%rbp)
	movl	-184(%rbp), %eax
	movl 	%eax, -48(%rbp)
.L17: 
	movl	-48(%rbp), %eax
	cmpl	-64(%rbp), %eax
	jle .L19
	jmp .L20
.L18: 
	movl	-48(%rbp), %eax
	movl 	%eax, -192(%rbp)
	addl 	$1, -48(%rbp)
	jmp .L17
.L19: 
	movq 	$.LC5, -196(%rbp)
	movl 	-196(%rbp), %eax
	movq 	-196(%rbp), %rdi
	call	printStr
	movl	%eax, -200(%rbp)
	jmp .L18
.L20: 
	movl	$1, %eax
	movl 	%eax, -204(%rbp)
	movl	-204(%rbp), %eax
	movl 	%eax, -48(%rbp)
.L21: 
	movl	$2, %eax
	movl 	%eax, -212(%rbp)
	movl 	-52(%rbp), %eax
	movl 	-64(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -216(%rbp)
	movl 	-212(%rbp), %eax
	imull 	-216(%rbp), %eax
	movl 	%eax, -220(%rbp)
	movl	$1, %eax
	movl 	%eax, -224(%rbp)
	movl 	-220(%rbp), %eax
	movl 	-224(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -228(%rbp)
	movl	-48(%rbp), %eax
	cmpl	-228(%rbp), %eax
	jle .L23
	jmp .L24
.L22: 
	movl	-48(%rbp), %eax
	movl 	%eax, -232(%rbp)
	addl 	$1, -48(%rbp)
	jmp .L21
.L23: 
	movq 	$.LC6, -236(%rbp)
	movl 	-236(%rbp), %eax
	movq 	-236(%rbp), %rdi
	call	printStr
	movl	%eax, -240(%rbp)
	jmp .L22
.L24: 
	movq 	$.LC7, -244(%rbp)
	movl 	-244(%rbp), %eax
	movq 	-244(%rbp), %rdi
	call	printStr
	movl	%eax, -248(%rbp)
	jmp .L15
.L25: 
	movl	$0, %eax
	movl 	%eax, -252(%rbp)
	movl	-252(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by 19CS10060_19CS10039"
	.section	.note.GNU-stack,"",@progbits
