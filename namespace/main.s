	.file	"main.cpp"
	.text
	.globl	result
	.data
	.align 4
	.type	result, @object
	.size	result, 4
result:
	.long	1000
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA0
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$10, -20(%rbp)
	movl	$10, -20(%rbp)
	movl	$2000, result(%rip)
	movl	$1000, _ZN7IntCalc6resultE(%rip)
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZN7IntCalc4CalcC1Ev
.LEHE0:
	leaq	-24(%rbp), %rax
	movl	$10, %edx
	movl	$10, %esi
	movq	%rax, %rdi
.LEHB1:
	call	_ZN7IntCalc4Calc3addEii
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, _ZN10DoubleCalc6resultE(%rip)
	leaq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10DoubleCalc4CalcC1Ev
.LEHE1:
	movsd	.LC1(%rip), %xmm0
	movq	.LC2(%rip), %rdx
	leaq	-28(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
.LEHB2:
	call	_ZN10DoubleCalc4Calc3addEdd
.LEHE2:
	leaq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10DoubleCalc4CalcD1Ev
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7IntCalc4CalcD1Ev
	movl	$0, %eax
	jmp	.L7
.L6:
	movq	%rax, %rbx
	leaq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10DoubleCalc4CalcD1Ev
	jmp	.L4
.L5:
	movq	%rax, %rbx
.L4:
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7IntCalc4CalcD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L7:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA0:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE0-.LLSDACSB0
.LLSDACSB0:
	.uleb128 .LEHB0-.LFB0
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB0
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L5-.LFB0
	.uleb128 0
	.uleb128 .LEHB2-.LFB0
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L6-.LFB0
	.uleb128 0
	.uleb128 .LEHB3-.LFB0
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE0:
	.text
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	858993459
	.long	1083131699
	.align 8
.LC1:
	.long	0
	.long	1077149696
	.align 8
.LC2:
	.long	0
	.long	1076101120
	.ident	"GCC: (GNU) 9.1.1 20190503 (Red Hat 9.1.1-1)"
	.section	.note.GNU-stack,"",@progbits
