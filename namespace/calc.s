	.file	"calc.cpp"
	.text
	.globl	_ZN7IntCalc6resultE
	.data
	.align 4
	.type	_ZN7IntCalc6resultE, @object
	.size	_ZN7IntCalc6resultE, 4
_ZN7IntCalc6resultE:
	.long	10
	.text
	.align 2
	.globl	_ZN7IntCalc4CalcC2Ev
	.type	_ZN7IntCalc4CalcC2Ev, @function
_ZN7IntCalc4CalcC2Ev:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN7IntCalc4CalcC2Ev, .-_ZN7IntCalc4CalcC2Ev
	.globl	_ZN7IntCalc4CalcC1Ev
	.set	_ZN7IntCalc4CalcC1Ev,_ZN7IntCalc4CalcC2Ev
	.align 2
	.globl	_ZN7IntCalc4CalcD2Ev
	.type	_ZN7IntCalc4CalcD2Ev, @function
_ZN7IntCalc4CalcD2Ev:
.LFB4:
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
.LFE4:
	.size	_ZN7IntCalc4CalcD2Ev, .-_ZN7IntCalc4CalcD2Ev
	.globl	_ZN7IntCalc4CalcD1Ev
	.set	_ZN7IntCalc4CalcD1Ev,_ZN7IntCalc4CalcD2Ev
	.align 2
	.globl	_ZN7IntCalc4Calc3addEii
	.type	_ZN7IntCalc4Calc3addEii, @function
_ZN7IntCalc4Calc3addEii:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_ZN7IntCalc4Calc3addEii, .-_ZN7IntCalc4Calc3addEii
	.align 2
	.globl	_ZN7IntCalc4Calc3mulEii
	.type	_ZN7IntCalc4Calc3mulEii, @function
_ZN7IntCalc4Calc3mulEii:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-12(%rbp), %eax
	imull	-16(%rbp), %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	_ZN7IntCalc4Calc3mulEii, .-_ZN7IntCalc4Calc3mulEii
	.align 2
	.globl	_ZN7IntCalc4Calc3divEii
	.type	_ZN7IntCalc4Calc3divEii, @function
_ZN7IntCalc4Calc3divEii:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-12(%rbp), %eax
	cltd
	idivl	-16(%rbp)
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN7IntCalc4Calc3divEii, .-_ZN7IntCalc4Calc3divEii
	.align 2
	.globl	_ZN7IntCalc4Calc3subEii
	.type	_ZN7IntCalc4Calc3subEii, @function
_ZN7IntCalc4Calc3subEii:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-12(%rbp), %eax
	subl	-16(%rbp), %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	_ZN7IntCalc4Calc3subEii, .-_ZN7IntCalc4Calc3subEii
	.globl	_ZN10DoubleCalc6resultE
	.data
	.align 8
	.type	_ZN10DoubleCalc6resultE, @object
	.size	_ZN10DoubleCalc6resultE, 8
_ZN10DoubleCalc6resultE:
	.long	0
	.long	1076101120
	.text
	.align 2
	.globl	_ZN10DoubleCalc4CalcC2Ev
	.type	_ZN10DoubleCalc4CalcC2Ev, @function
_ZN10DoubleCalc4CalcC2Ev:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	_ZN10DoubleCalc4CalcC2Ev, .-_ZN10DoubleCalc4CalcC2Ev
	.globl	_ZN10DoubleCalc4CalcC1Ev
	.set	_ZN10DoubleCalc4CalcC1Ev,_ZN10DoubleCalc4CalcC2Ev
	.align 2
	.globl	_ZN10DoubleCalc4CalcD2Ev
	.type	_ZN10DoubleCalc4CalcD2Ev, @function
_ZN10DoubleCalc4CalcD2Ev:
.LFB14:
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
.LFE14:
	.size	_ZN10DoubleCalc4CalcD2Ev, .-_ZN10DoubleCalc4CalcD2Ev
	.globl	_ZN10DoubleCalc4CalcD1Ev
	.set	_ZN10DoubleCalc4CalcD1Ev,_ZN10DoubleCalc4CalcD2Ev
	.align 2
	.globl	_ZN10DoubleCalc4Calc3addEdd
	.type	_ZN10DoubleCalc4Calc3addEdd, @function
_ZN10DoubleCalc4Calc3addEdd:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	cvttsd2sil	%xmm0, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cvtsi2sdl	%eax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	_ZN10DoubleCalc4Calc3addEdd, .-_ZN10DoubleCalc4Calc3addEdd
	.align 2
	.globl	_ZN10DoubleCalc4Calc3mulEdd
	.type	_ZN10DoubleCalc4Calc3mulEdd, @function
_ZN10DoubleCalc4Calc3mulEdd:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	-16(%rbp), %xmm0
	mulsd	-24(%rbp), %xmm0
	cvttsd2sil	%xmm0, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cvtsi2sdl	%eax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	_ZN10DoubleCalc4Calc3mulEdd, .-_ZN10DoubleCalc4Calc3mulEdd
	.align 2
	.globl	_ZN10DoubleCalc4Calc3divEdd
	.type	_ZN10DoubleCalc4Calc3divEdd, @function
_ZN10DoubleCalc4Calc3divEdd:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	-16(%rbp), %xmm0
	divsd	-24(%rbp), %xmm0
	cvttsd2sil	%xmm0, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cvtsi2sdl	%eax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	_ZN10DoubleCalc4Calc3divEdd, .-_ZN10DoubleCalc4Calc3divEdd
	.align 2
	.globl	_ZN10DoubleCalc4Calc3subEdd
	.type	_ZN10DoubleCalc4Calc3subEdd, @function
_ZN10DoubleCalc4Calc3subEdd:
.LFB19:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	-16(%rbp), %xmm0
	subsd	-24(%rbp), %xmm0
	cvttsd2sil	%xmm0, %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cvtsi2sdl	%eax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	_ZN10DoubleCalc4Calc3subEdd, .-_ZN10DoubleCalc4Calc3subEdd
	.ident	"GCC: (GNU) 9.1.1 20190503 (Red Hat 9.1.1-1)"
	.section	.note.GNU-stack,"",@progbits
