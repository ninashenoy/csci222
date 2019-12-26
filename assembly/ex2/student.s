	.file	"student.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.globl	_ZN7Student12_numStudentsE
	.bss
	.align 4
	.type	_ZN7Student12_numStudentsE, @object
	.size	_ZN7Student12_numStudentsE, 4
_ZN7Student12_numStudentsE:
	.zero	4
	.text
	.align 2
	.globl	_ZN7StudentC2EPKc
	.type	_ZN7StudentC2EPKc, @function
_ZN7StudentC2EPKc:
.LFB1523:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	strdup
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movl	_ZN7Student12_numStudentsE(%rip), %eax
	addl	$1, %eax
	movl	%eax, _ZN7Student12_numStudentsE(%rip)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1523:
	.size	_ZN7StudentC2EPKc, .-_ZN7StudentC2EPKc
	.globl	_ZN7StudentC1EPKc
	.set	_ZN7StudentC1EPKc,_ZN7StudentC2EPKc
	.align 2
	.globl	_ZN7StudentD2Ev
	.type	_ZN7StudentD2Ev, @function
_ZN7StudentD2Ev:
.LFB1526:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1526:
	.size	_ZN7StudentD2Ev, .-_ZN7StudentD2Ev
	.globl	_ZN7StudentD1Ev
	.set	_ZN7StudentD1Ev,_ZN7StudentD2Ev
	.align 2
	.globl	_ZN7Student7getNameEv
	.type	_ZN7Student7getNameEv, @function
_ZN7Student7getNameEv:
.LFB1528:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1528:
	.size	_ZN7Student7getNameEv, .-_ZN7Student7getNameEv
	.align 2
	.globl	_ZN7Student14getNumStudentsEv
	.type	_ZN7Student14getNumStudentsEv, @function
_ZN7Student14getNumStudentsEv:
.LFB1529:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	_ZN7Student12_numStudentsE(%rip), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1529:
	.size	_ZN7Student14getNumStudentsEv, .-_ZN7Student14getNumStudentsEv
	.align 2
	.globl	_ZN7Student5setIDEi
	.type	_ZN7Student5setIDEi, @function
_ZN7Student5setIDEi:
.LFB1530:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1530:
	.size	_ZN7Student5setIDEi, .-_ZN7Student5setIDEi
	.globl	_Z5printv
	.type	_Z5printv, @function
_Z5printv:
.LFB1531:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1531:
	.size	_Z5printv, .-_Z5printv
	.section	.rodata
.LC0:
	.string	"Nina"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1532:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	leaq	-48(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	_ZN7StudentC1EPKc
	movl	$0, -20(%rbp)
.L12:
	cmpl	$2, -20(%rbp)
	jg	.L11
	leaq	-48(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZN7Student5setIDEi
	leaq	-48(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZN7Student5setIDEi
	leaq	-48(%rbp), %rax
	movl	$2, %esi
	movq	%rax, %rdi
	call	_ZN7Student5setIDEi
	call	_Z5printv
	call	_Z5printv
	call	_ZN7Student14getNumStudentsEv
	addl	$1, -20(%rbp)
	jmp	.L12
.L11:
	movl	$0, %ebx
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7StudentD1Ev
	movl	%ebx, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1532:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2013:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L16
	cmpl	$65535, -8(%rbp)
	jne	.L16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L16:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2013:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN7Student12_numStudentsE, @function
_GLOBAL__sub_I__ZN7Student12_numStudentsE:
.LFB2014:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2014:
	.size	_GLOBAL__sub_I__ZN7Student12_numStudentsE, .-_GLOBAL__sub_I__ZN7Student12_numStudentsE
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN7Student12_numStudentsE
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 9.1.1 20190503 (Red Hat 9.1.1-1)"
	.section	.note.GNU-stack,"",@progbits
