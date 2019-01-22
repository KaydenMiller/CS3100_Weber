	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"Welcome to CS 3100!"
.LC1:
	.string	"Creating a new stack."
.LC2:
	.string	"Pushing 'M' onto the stack."
.LC3:
	.string	"Pushing 'O' onto the stack."
.LC4:
	.string	"Pushing 'P' onto the stack."
	.align 8
.LC5:
	.string	"Popping, the result should be a 'P': %c\n"
	.align 8
.LC6:
	.string	"Popping, the result should be a 'O': %c\n"
	.align 8
.LC7:
	.string	"Popping, the result should be a 'M': %c\n"
	.align 8
.LC8:
	.string	"Popping, the result should be an empty space and I should have just gotten an error: %c\n"
	.align 8
.LC9:
	.string	"Checking to see if the stack is empty now."
	.align 8
.LC10:
	.string	"The stack is empty. Now I am going to call FreeStack on it."
	.align 8
.LC11:
	.string	"Oh, dear. We have a problem. The stack should be empty now. I wonder, can I call FreeStack on it anyway?"
.LC12:
	.string	"Creating another stack."
	.align 8
.LC13:
	.string	"(PASS) The stack is empty. That is good."
	.align 8
.LC14:
	.string	"(FAIL) The stack is not empty. That is not good."
	.align 8
.LC15:
	.string	"Filling the stack up with information."
	.align 8
.LC16:
	.string	"(FAIL) The stack is empty. That is not good."
	.align 8
.LC17:
	.string	"(PASS) The stack is not empty. That is good."
	.align 8
.LC18:
	.string	"Can we free a non-empty stack? Let's try. We should get an error."
	.align 8
.LC19:
	.string	"Hopefully that caused a problem. Let's empty the stack then try to free it."
	.align 8
.LC20:
	.string	"What happens when we Pop from an empty stack? We should get an error:"
.LC21:
	.string	"Creating a third stack."
	.align 8
.LC22:
	.string	"Now let's empty it and print out the result: (It should be \"dooG\"):"
	.align 8
.LC23:
	.string	"\nNow, let's free the stack and be finished."
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	call	NewStack@PLT
	movq	%rax, -48(%rbp)
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movq	-48(%rbp), %rax
	movl	$77, %esi
	movq	%rax, %rdi
	call	Push@PLT
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	movq	-48(%rbp), %rax
	movl	$79, %esi
	movq	%rax, %rdi
	call	Push@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	movq	-48(%rbp), %rax
	movl	$80, %esi
	movq	%rax, %rdi
	call	Push@PLT
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC9(%rip), %rdi
	call	puts@PLT
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	IsEmpty@PLT
	movl	%eax, -52(%rbp)
	cmpl	$1, -52(%rbp)
	jne	.L2
	leaq	.LC10(%rip), %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
.L3:
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	FreeStack@PLT
	movb	$82, -15(%rbp)
	movb	$65, -14(%rbp)
	movb	$67, -13(%rbp)
	movb	$69, -12(%rbp)
	movb	$67, -11(%rbp)
	movb	$65, -10(%rbp)
	movb	$82, -9(%rbp)
	leaq	.LC12(%rip), %rdi
	call	puts@PLT
	call	NewStack@PLT
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	IsEmpty@PLT
	movl	%eax, -52(%rbp)
	cmpl	$1, -52(%rbp)
	jne	.L4
	leaq	.LC13(%rip), %rdi
	call	puts@PLT
	jmp	.L5
.L4:
	leaq	.LC14(%rip), %rdi
	call	puts@PLT
.L5:
	leaq	.LC15(%rip), %rdi
	call	puts@PLT
	movl	$0, -56(%rbp)
	jmp	.L6
.L7:
	movl	-56(%rbp), %eax
	cltq
	movzbl	-15(%rbp,%rax), %eax
	movsbl	%al, %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	Push@PLT
	addl	$1, -56(%rbp)
.L6:
	cmpl	$6, -56(%rbp)
	jle	.L7
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	IsEmpty@PLT
	movl	%eax, -52(%rbp)
	cmpl	$1, -52(%rbp)
	jne	.L8
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	jmp	.L9
.L8:
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
.L9:
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	FreeStack@PLT
	leaq	.LC19(%rip), %rdi
	call	puts@PLT
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	EmptyStack@PLT
	leaq	.LC20(%rip), %rdi
	call	puts@PLT
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movb	%al, -58(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	FreeStack@PLT
	leaq	.LC21(%rip), %rdi
	call	puts@PLT
	call	NewStack@PLT
	movq	%rax, -32(%rbp)
	movb	$71, -19(%rbp)
	movb	$111, -18(%rbp)
	movb	$111, -17(%rbp)
	movb	$100, -16(%rbp)
	leaq	.LC15(%rip), %rdi
	call	puts@PLT
	movl	$0, -56(%rbp)
	jmp	.L10
.L11:
	movl	-56(%rbp), %eax
	cltq
	movzbl	-19(%rbp,%rax), %eax
	movsbl	%al, %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	Push@PLT
	addl	$1, -56(%rbp)
.L10:
	cmpl	$3, -56(%rbp)
	jle	.L11
	leaq	.LC22(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -56(%rbp)
	jmp	.L12
.L13:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	Pop@PLT
	movb	%al, -57(%rbp)
	movsbl	-57(%rbp), %eax
	movl	%eax, %edi
	call	putchar@PLT
	addl	$1, -56(%rbp)
.L12:
	cmpl	$3, -56(%rbp)
	jle	.L13
	leaq	.LC23(%rip), %rdi
	call	puts@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	FreeStack@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L15
	call	__stack_chk_fail@PLT
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
