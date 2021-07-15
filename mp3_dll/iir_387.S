	.file	"iir.c"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	rnd_k_p
	.def	rnd_k_p;	.scl	2;	.type	32;	.endef
	.seh_proc	rnd_k_p
rnd_k_p:
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	mov	eax, DWORD PTR ar_already_k_p.91037[rip]
	mov	esi, ecx
	mov	ebx, edx
	test	eax, eax
	je	.L4
.L2:
	call	genrand
	sub	ebx, esi
	lea	ecx, 1[rbx]
	cdq
	idiv	ecx
	mov	eax, edx
	sar	eax, 31
	xor	edx, eax
	sub	edx, eax
	lea	eax, [rdx+rsi]
	add	rsp, 40
	pop	rbx
	pop	rsi
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	call	[QWORD PTR __imp_GetTickCount[rip]]
	mov	ecx, eax
	call	sgenrand
	mov	DWORD PTR ar_already_k_p.91037[rip], 1
	jmp	.L2
	.seh_endproc
	.p2align 4
	.globl	round_trick
	.def	round_trick;	.scl	2;	.type	32;	.endef
	.seh_proc	round_trick
round_trick:
	sub	rsp, 24
	.seh_stackalloc	24
	.seh_endprologue
	movss	DWORD PTR 8[rsp], xmm0
	fld	DWORD PTR 8[rsp]
	fadd	DWORD PTR .LC0[rip]
	fstp	QWORD PTR 8[rsp]
	cvttsd2si	eax, QWORD PTR 8[rsp]
	add	rsp, 24
	ret
	.seh_endproc
	.p2align 4
	.globl	init_iir
	.def	init_iir;	.scl	2;	.type	32;	.endef
	.seh_proc	init_iir
init_iir:
	push	rdi
	.seh_pushreg	rdi
	.seh_endprologue
	lea	rdi, iir_cforiginal10_fixed[rip]
	movabs	rax, 8589934593
	movq	xmm0, rdi
	mov	QWORD PTR 3121288[rcx], rax
	mov	rdx, rcx
	movabs	rax, 4294967306
	lea	rdi, 3127528[rcx]
	mov	QWORD PTR 3130496[rcx], rax
	and	rdi, -8
	lea	rax, iir_cforiginal10[rip]
	mov	DWORD PTR 3121296[rcx], 0
	movq	xmm1, rax
	xor	eax, eax
	mov	DWORD PTR 3130808[rcx], 0
	punpcklqdq	xmm0, xmm1
	mov	QWORD PTR 3127520[rcx], 0
	mov	QWORD PTR 3130488[rcx], 0
	movups	XMMWORD PTR 3121552[rcx], xmm0
	sub	ecx, edi
	add	ecx, 3130496
	shr	ecx, 3
	rep stosq
	lea	rdi, 3124552[rdx]
	mov	ecx, edx
	mov	QWORD PTR 3124544[rdx], 0
	mov	QWORD PTR 3127512[rdx], 0
	and	rdi, -8
	sub	ecx, edi
	add	ecx, 3127520
	shr	ecx, 3
	rep stosq
	lea	rdi, 3123064[rdx]
	mov	ecx, edx
	mov	QWORD PTR 3123056[rdx], 0
	mov	QWORD PTR 3124536[rdx], 0
	and	rdi, -8
	sub	ecx, edi
	add	ecx, 3124544
	shr	ecx, 3
	rep stosq
	lea	rdi, 3121576[rdx]
	mov	QWORD PTR 3121568[rdx], 0
	mov	QWORD PTR 3123048[rdx], 0
	and	rdi, -8
	sub	edx, edi
	lea	ecx, 3123056[rdx]
	shr	ecx, 3
	rep stosq
	pop	rdi
	ret
	.seh_endproc
	.p2align 4
	.globl	amanda_fix_dithering
	.def	amanda_fix_dithering;	.scl	2;	.type	32;	.endef
	.seh_proc	amanda_fix_dithering
amanda_fix_dithering:
	.seh_endprologue
	ret
	.seh_endproc
	.p2align 4
	.globl	iir
	.def	iir;	.scl	2;	.type	32;	.endef
	.seh_proc	iir
iir:
	push	r15
	.seh_pushreg	r15
	push	r14
	.seh_pushreg	r14
	push	r13
	.seh_pushreg	r13
	push	r12
	.seh_pushreg	r12
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	lea	rdi, iir_cforiginal10_fixed[rip]
	xor	r15d, r15d
	movabs	rax, 4294967306
	movq	xmm0, rdi
	mov	QWORD PTR 3130496[rcx], rax
	mov	rbx, rcx
	mov	rbp, rdx
	mov	r14d, r9d
	lea	rax, iir_cforiginal10[rip]
	cmp	r9d, 1
	mov	DWORD PTR 128[rsp], r8d
	movq	xmm1, rax
	mov	eax, r8d
	setne	r15b
	mov	DWORD PTR 3130808[rcx], 0
	punpcklqdq	xmm0, xmm1
	sar	eax
	add	r15d, 1
	mov	DWORD PTR 20[rsp], eax
	movups	XMMWORD PTR 3121552[rcx], xmm0
	test	eax, eax
	jle	.L10
	movsx	rax, r15d
	fld	QWORD PTR .LC2[rip]
	xor	r12d, r12d
	fld	QWORD PTR .LC3[rip]
	add	rax, rax
	mov	r9d, DWORD PTR 3121296[rcx]
	mov	edi, DWORD PTR 3121288[rcx]
	mov	QWORD PTR 24[rsp], rax
	mov	esi, DWORD PTR 3121292[rcx]
	lea	eax, -1[r14]
	lea	r13, 3121304[rcx+rax*4]
	.p2align 4,,10
	.p2align 3
.L11:
	test	r14d, r14d
	jle	.L20
	movsx	rax, r9d
	fld	QWORD PTR .LC4[rip]
	movsx	rcx, esi
	mov	r11, rbp
	mov	DWORD PTR 16[rsp], r9d
	lea	rdx, [rbx+rax*8]
	movsx	rax, edi
	lea	r8, [rbx+rcx*8]
	lea	rax, [rbx+rax*8]
	lea	rcx, 3121300[rbx]
.L15:
	movzx	r10d, WORD PTR [r11]
	mov	WORD PTR 8[rsp], r10w
	fild	WORD PTR 8[rsp]
	sar	r10w, 2
	fild	WORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3127520[rdx]
	fld	QWORD PTR 3127520[rax]
	fsubr	st, st(2)
	fmul	st, st(5)
	fld	QWORD PTR 3127544[r8]
	fmul	st, st(5)
	faddp	st(1), st
	fld	QWORD PTR 3127544[rax]
	fmul	st, st(4)
	fsubp	st(1), st
	fst	QWORD PTR 3127544[rdx]
	fmul	DWORD PTR [rcx]
	fadd	DWORD PTR .LC5[rip]
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3127616[rdx]
	fld	QWORD PTR 3127616[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC6[rip]
	fld	QWORD PTR .LC7[rip]
	fmul	QWORD PTR 3127640[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC8[rip]
	fmul	QWORD PTR 3127640[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3127640[rdx]
	fmul	DWORD PTR 8[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3127712[rdx]
	fld	QWORD PTR 3127712[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC9[rip]
	fld	QWORD PTR .LC10[rip]
	fmul	QWORD PTR 3127736[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC11[rip]
	fmul	QWORD PTR 3127736[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3127736[rdx]
	fmul	DWORD PTR 16[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3127808[rdx]
	fld	QWORD PTR 3127808[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC12[rip]
	fld	QWORD PTR .LC13[rip]
	fmul	QWORD PTR 3127832[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC14[rip]
	fmul	QWORD PTR 3127832[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3127832[rdx]
	fmul	DWORD PTR 24[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3127904[rdx]
	fld	QWORD PTR 3127904[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC15[rip]
	fld	QWORD PTR .LC16[rip]
	fmul	QWORD PTR 3127928[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC17[rip]
	fmul	QWORD PTR 3127928[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3127928[rdx]
	fmul	DWORD PTR 32[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3128000[rdx]
	fld	QWORD PTR 3128000[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC18[rip]
	fld	QWORD PTR .LC19[rip]
	fmul	QWORD PTR 3128024[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC20[rip]
	fmul	QWORD PTR 3128024[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3128024[rdx]
	fmul	DWORD PTR 40[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3128096[rdx]
	fld	QWORD PTR 3128096[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC21[rip]
	fld	QWORD PTR .LC22[rip]
	fmul	QWORD PTR 3128120[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC23[rip]
	fmul	QWORD PTR 3128120[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3128120[rdx]
	fmul	DWORD PTR 48[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3128192[rdx]
	fld	QWORD PTR 3128192[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC24[rip]
	fld	QWORD PTR .LC25[rip]
	fmul	QWORD PTR 3128216[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC26[rip]
	fmul	QWORD PTR 3128216[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3128216[rdx]
	fmul	DWORD PTR 56[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3128288[rdx]
	fld	QWORD PTR 3128288[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC27[rip]
	fld	QWORD PTR .LC28[rip]
	fmul	QWORD PTR 3128312[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC29[rip]
	fmul	QWORD PTR 3128312[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3128312[rdx]
	fmul	DWORD PTR 64[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fstp	QWORD PTR 3128384[rdx]
	fxch	st(1)
	fsub	QWORD PTR 3128384[rax]
	fmul	QWORD PTR .LC30[rip]
	fld	QWORD PTR .LC31[rip]
	fmul	QWORD PTR 3128408[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC32[rip]
	fmul	QWORD PTR 3128408[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3128408[rdx]
	fmul	DWORD PTR 72[rcx]
	faddp	st(1), st
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	mov	WORD PTR 8[rsp], r10w
	fild	WORD PTR 8[rsp]
	faddp	st(1), st
	fadd	DWORD PTR .LC0[rip]
	fstp	QWORD PTR 8[rsp]
	cvttsd2si	r10d, QWORD PTR 8[rsp]
	cmp	r10d, -32768
	jge	.L12
	mov	r9d, -32768
	mov	WORD PTR [r11], r9w
.L13:
	add	rcx, 4
	add	r11, 2
	add	rdx, 48
	add	rax, 48
	add	r8, 48
	cmp	rcx, r13
	jne	.L15
	fstp	st(0)
	mov	r9d, DWORD PTR 16[rsp]
.L20:
	add	r9d, 1
	add	esi, 1
	add	edi, 1
	mov	DWORD PTR 3121296[rbx], r9d
	mov	DWORD PTR 3121292[rbx], esi
	mov	DWORD PTR 3121288[rbx], edi
	cmp	r9d, 3
	je	.L23
	cmp	esi, 3
	je	.L24
	mov	DWORD PTR 3121288[rbx], 0
	xor	edi, edi
.L17:
	add	r12d, r15d
	add	rbp, QWORD PTR 24[rsp]
	cmp	DWORD PTR 20[rsp], r12d
	jg	.L11
	fstp	st(0)
	fstp	st(0)
.L10:
	mov	eax, DWORD PTR 128[rsp]
	add	rsp, 40
	pop	rbx
	pop	rsi
	pop	rdi
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	cmp	r10d, 32768
	mov	r9d, 32767
	cmovge	r10d, r9d
	mov	WORD PTR [r11], r10w
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L23:
	mov	DWORD PTR 3121296[rbx], 0
	xor	r9d, r9d
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L24:
	mov	DWORD PTR 3121292[rbx], 0
	xor	esi, esi
	jmp	.L17
	.seh_endproc
	.p2align 4
	.globl	configequalizer
	.def	configequalizer;	.scl	2;	.type	32;	.endef
	.seh_proc	configequalizer
configequalizer:
	sub	rsp, 56
	.seh_stackalloc	56
	movaps	XMMWORD PTR [rsp], xmm6
	.seh_savexmm	xmm6, 0
	movaps	XMMWORD PTR 16[rsp], xmm7
	.seh_savexmm	xmm7, 16
	movaps	XMMWORD PTR 32[rsp], xmm8
	.seh_savexmm	xmm8, 32
	.seh_endprologue
	movdqa	xmm6, XMMWORD PTR .LC33[rip]
	movaps	xmm2, XMMWORD PTR .LC34[rip]
	xor	eax, eax
	movd	xmm3, DWORD PTR 104[rsp]
	movd	xmm1, DWORD PTR 120[rsp]
	movd	xmm7, DWORD PTR 144[rsp]
	movaps	xmm8, XMMWORD PTR 32[rsp]
	punpckldq	xmm3, xmm3
	punpckldq	xmm1, xmm1
	punpckldq	xmm7, xmm7
	movd	xmm5, edx
	movd	xmm0, r8d
	movd	xmm4, r9d
	punpckldq	xmm0, xmm0
	punpckldq	xmm5, xmm5
	punpckldq	xmm4, xmm4
	punpcklqdq	xmm5, xmm0
	movd	xmm0, DWORD PTR 96[rsp]
	paddd	xmm5, xmm6
	cvtdq2ps	xmm5, xmm5
	divps	xmm5, xmm2
	punpckldq	xmm0, xmm0
	punpcklqdq	xmm4, xmm0
	movd	xmm0, DWORD PTR 112[rsp]
	paddd	xmm4, xmm6
	cvtdq2ps	xmm4, xmm4
	punpckldq	xmm0, xmm0
	punpcklqdq	xmm3, xmm0
	movd	xmm0, DWORD PTR 128[rsp]
	paddd	xmm3, xmm6
	punpckldq	xmm0, xmm0
	cvtdq2ps	xmm3, xmm3
	punpcklqdq	xmm1, xmm0
	movd	xmm0, DWORD PTR 136[rsp]
	paddd	xmm1, xmm6
	punpckldq	xmm0, xmm0
	cvtdq2ps	xmm1, xmm1
	punpcklqdq	xmm0, xmm7
	paddd	xmm0, xmm6
	pxor	xmm6, xmm6
	cvtdq2ps	xmm0, xmm0
	divps	xmm4, xmm2
	movhlps	xmm6, xmm5
	cvtps2pd	xmm7, xmm5
	cvtps2pd	xmm6, xmm6
	divps	xmm3, xmm2
	divps	xmm1, xmm2
	divps	xmm0, xmm2
	movapd	xmm2, XMMWORD PTR .LC35[rip]
	addpd	xmm7, xmm2
	addpd	xmm6, xmm2
	cvtpd2ps	xmm5, xmm7
	cvtpd2ps	xmm6, xmm6
	movlhps	xmm5, xmm6
	cvtps2pd	xmm6, xmm4
	movups	XMMWORD PTR 3121300[rcx], xmm5
	pxor	xmm5, xmm5
	addpd	xmm6, xmm2
	movaps	xmm7, XMMWORD PTR 16[rsp]
	movhlps	xmm5, xmm4
	cvtps2pd	xmm5, xmm5
	addpd	xmm5, xmm2
	cvtpd2ps	xmm4, xmm6
	movaps	xmm6, XMMWORD PTR [rsp]
	cvtpd2ps	xmm5, xmm5
	movlhps	xmm4, xmm5
	cvtps2pd	xmm5, xmm3
	addpd	xmm5, xmm2
	movups	XMMWORD PTR 3121316[rcx], xmm4
	pxor	xmm4, xmm4
	movhlps	xmm4, xmm3
	cvtps2pd	xmm4, xmm4
	addpd	xmm4, xmm2
	cvtpd2ps	xmm3, xmm5
	cvtpd2ps	xmm4, xmm4
	movlhps	xmm3, xmm4
	cvtps2pd	xmm4, xmm1
	addpd	xmm4, xmm2
	movups	XMMWORD PTR 3121332[rcx], xmm3
	pxor	xmm3, xmm3
	movhlps	xmm3, xmm1
	cvtps2pd	xmm3, xmm3
	addpd	xmm3, xmm2
	cvtpd2ps	xmm1, xmm4
	cvtpd2ps	xmm3, xmm3
	movlhps	xmm1, xmm3
	cvtps2pd	xmm3, xmm0
	addpd	xmm3, xmm2
	movups	XMMWORD PTR 3121348[rcx], xmm1
	pxor	xmm1, xmm1
	movhlps	xmm1, xmm0
	cvtps2pd	xmm1, xmm1
	addpd	xmm2, xmm1
	cvtpd2ps	xmm0, xmm3
	cvtpd2ps	xmm2, xmm2
	movlhps	xmm0, xmm2
	movups	XMMWORD PTR 3121364[rcx], xmm0
	add	rsp, 56
	ret
	.seh_endproc
	.p2align 4
	.globl	init_iir____2
	.def	init_iir____2;	.scl	2;	.type	32;	.endef
	.seh_proc	init_iir____2
init_iir____2:
	push	rdi
	.seh_pushreg	rdi
	.seh_endprologue
	lea	rdi, iir_cforiginal10_fixed[rip]
	movabs	rax, 8589934593
	movq	xmm0, rdi
	mov	QWORD PTR 3130840[rcx], rax
	mov	rdx, rcx
	movabs	rax, 4294967306
	lea	rdi, 3137328[rcx]
	mov	QWORD PTR 3140296[rcx], rax
	and	rdi, -8
	lea	rax, iir_cforiginal10[rip]
	mov	DWORD PTR 3130848[rcx], 0
	movq	xmm1, rax
	xor	eax, eax
	mov	DWORD PTR 3140608[rcx], 0
	punpcklqdq	xmm0, xmm1
	mov	QWORD PTR 3137320[rcx], 0
	mov	QWORD PTR 3140288[rcx], 0
	movups	XMMWORD PTR 3131352[rcx], xmm0
	sub	ecx, edi
	add	ecx, 3140296
	shr	ecx, 3
	rep stosq
	lea	rdi, 3134352[rdx]
	mov	ecx, edx
	mov	QWORD PTR 3134344[rdx], 0
	mov	QWORD PTR 3137312[rdx], 0
	and	rdi, -8
	sub	ecx, edi
	add	ecx, 3137320
	shr	ecx, 3
	rep stosq
	lea	rdi, 3132864[rdx]
	mov	ecx, edx
	mov	QWORD PTR 3132856[rdx], 0
	mov	QWORD PTR 3134336[rdx], 0
	and	rdi, -8
	sub	ecx, edi
	add	ecx, 3134344
	shr	ecx, 3
	rep stosq
	lea	rdi, 3131376[rdx]
	mov	QWORD PTR 3131368[rdx], 0
	mov	QWORD PTR 3132848[rdx], 0
	and	rdi, -8
	sub	edx, edi
	lea	ecx, 3132856[rdx]
	shr	ecx, 3
	rep stosq
	pop	rdi
	ret
	.seh_endproc
	.p2align 4
	.globl	iir___2
	.def	iir___2;	.scl	2;	.type	32;	.endef
	.seh_proc	iir___2
iir___2:
	push	r15
	.seh_pushreg	r15
	push	r14
	.seh_pushreg	r14
	push	r13
	.seh_pushreg	r13
	push	r12
	.seh_pushreg	r12
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	lea	rdi, iir_cforiginal10_fixed[rip]
	xor	r15d, r15d
	movabs	rax, 4294967306
	movq	xmm0, rdi
	mov	QWORD PTR 3140296[rcx], rax
	mov	rbx, rcx
	mov	rbp, rdx
	mov	r14d, r9d
	lea	rax, iir_cforiginal10[rip]
	cmp	r9d, 1
	mov	DWORD PTR 128[rsp], r8d
	movq	xmm1, rax
	mov	eax, r8d
	setne	r15b
	mov	DWORD PTR 3140608[rcx], 0
	punpcklqdq	xmm0, xmm1
	sar	eax
	add	r15d, 1
	mov	DWORD PTR 20[rsp], eax
	movups	XMMWORD PTR 3131352[rcx], xmm0
	test	eax, eax
	jle	.L29
	movsx	rax, r15d
	fld	QWORD PTR .LC2[rip]
	xor	r12d, r12d
	fld	QWORD PTR .LC3[rip]
	add	rax, rax
	mov	r9d, DWORD PTR 3130848[rcx]
	mov	edi, DWORD PTR 3130840[rcx]
	mov	QWORD PTR 24[rsp], rax
	mov	esi, DWORD PTR 3130844[rcx]
	lea	eax, -1[r14]
	lea	r13, 3130864[rcx+rax*8]
	.p2align 4,,10
	.p2align 3
.L30:
	test	r14d, r14d
	jle	.L39
	movsx	rax, r9d
	fld	QWORD PTR .LC4[rip]
	movsx	rcx, esi
	mov	r11, rbp
	mov	DWORD PTR 16[rsp], r9d
	lea	rdx, [rbx+rax*8]
	movsx	rax, edi
	lea	r8, [rbx+rcx*8]
	lea	rax, [rbx+rax*8]
	lea	rcx, 3130856[rbx]
.L34:
	movzx	r10d, WORD PTR [r11]
	mov	WORD PTR 8[rsp], r10w
	fild	WORD PTR 8[rsp]
	sar	r10w, 2
	fild	WORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137320[rdx]
	fld	QWORD PTR 3137320[rax]
	fsubr	st, st(2)
	fmul	st, st(5)
	fld	QWORD PTR 3137344[r8]
	fmul	st, st(5)
	faddp	st(1), st
	fld	QWORD PTR 3137344[rax]
	fmul	st, st(4)
	fsubp	st(1), st
	fst	QWORD PTR 3137344[rdx]
	fmul	QWORD PTR [rcx]
	fadd	DWORD PTR .LC5[rip]
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137416[rdx]
	fld	QWORD PTR 3137416[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC6[rip]
	fld	QWORD PTR .LC7[rip]
	fmul	QWORD PTR 3137440[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC8[rip]
	fmul	QWORD PTR 3137440[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3137440[rdx]
	fmul	QWORD PTR 16[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137512[rdx]
	fld	QWORD PTR 3137512[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC9[rip]
	fld	QWORD PTR .LC10[rip]
	fmul	QWORD PTR 3137536[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC11[rip]
	fmul	QWORD PTR 3137536[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3137536[rdx]
	fmul	QWORD PTR 32[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137608[rdx]
	fld	QWORD PTR 3137608[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC12[rip]
	fld	QWORD PTR .LC13[rip]
	fmul	QWORD PTR 3137632[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC14[rip]
	fmul	QWORD PTR 3137632[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3137632[rdx]
	fmul	QWORD PTR 48[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137704[rdx]
	fld	QWORD PTR 3137704[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC15[rip]
	fld	QWORD PTR .LC16[rip]
	fmul	QWORD PTR 3137728[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC17[rip]
	fmul	QWORD PTR 3137728[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3137728[rdx]
	fmul	QWORD PTR 64[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137800[rdx]
	fld	QWORD PTR 3137800[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC18[rip]
	fld	QWORD PTR .LC19[rip]
	fmul	QWORD PTR 3137824[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC20[rip]
	fmul	QWORD PTR 3137824[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3137824[rdx]
	fmul	QWORD PTR 80[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137896[rdx]
	fld	QWORD PTR 3137896[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC21[rip]
	fld	QWORD PTR .LC22[rip]
	fmul	QWORD PTR 3137920[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC23[rip]
	fmul	QWORD PTR 3137920[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3137920[rdx]
	fmul	QWORD PTR 96[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3137992[rdx]
	fld	QWORD PTR 3137992[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC24[rip]
	fld	QWORD PTR .LC25[rip]
	fmul	QWORD PTR 3138016[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC26[rip]
	fmul	QWORD PTR 3138016[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3138016[rdx]
	fmul	QWORD PTR 112[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fst	QWORD PTR 3138088[rdx]
	fld	QWORD PTR 3138088[rax]
	fsubr	st, st(3)
	fmul	QWORD PTR .LC27[rip]
	fld	QWORD PTR .LC28[rip]
	fmul	QWORD PTR 3138112[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC29[rip]
	fmul	QWORD PTR 3138112[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3138112[rdx]
	fmul	QWORD PTR 128[rcx]
	faddp	st(2), st
	fxch	st(1)
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	fxch	st(1)
	fstp	QWORD PTR 3138184[rdx]
	fxch	st(1)
	fsub	QWORD PTR 3138184[rax]
	fmul	QWORD PTR .LC30[rip]
	fld	QWORD PTR .LC31[rip]
	fmul	QWORD PTR 3138208[r8]
	faddp	st(1), st
	fld	QWORD PTR .LC32[rip]
	fmul	QWORD PTR 3138208[rax]
	fsubp	st(1), st
	fst	QWORD PTR 3138208[rdx]
	fmul	QWORD PTR 144[rcx]
	faddp	st(1), st
	fstp	DWORD PTR 8[rsp]
	fld	DWORD PTR 8[rsp]
	mov	WORD PTR 8[rsp], r10w
	fild	WORD PTR 8[rsp]
	faddp	st(1), st
	fadd	DWORD PTR .LC0[rip]
	fstp	QWORD PTR 8[rsp]
	cvttsd2si	r10d, QWORD PTR 8[rsp]
	cmp	r10d, -32768
	jge	.L31
	mov	r9d, -32768
	mov	WORD PTR [r11], r9w
.L32:
	add	rcx, 8
	add	r11, 2
	add	rdx, 48
	add	rax, 48
	add	r8, 48
	cmp	rcx, r13
	jne	.L34
	fstp	st(0)
	mov	r9d, DWORD PTR 16[rsp]
.L39:
	add	r9d, 1
	add	esi, 1
	add	edi, 1
	mov	DWORD PTR 3130848[rbx], r9d
	mov	DWORD PTR 3130844[rbx], esi
	mov	DWORD PTR 3130840[rbx], edi
	cmp	r9d, 3
	je	.L42
	cmp	esi, 3
	je	.L43
	mov	DWORD PTR 3130840[rbx], 0
	xor	edi, edi
.L36:
	add	r12d, r15d
	add	rbp, QWORD PTR 24[rsp]
	cmp	DWORD PTR 20[rsp], r12d
	jg	.L30
	fstp	st(0)
	fstp	st(0)
.L29:
	mov	eax, DWORD PTR 128[rsp]
	add	rsp, 40
	pop	rbx
	pop	rsi
	pop	rdi
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	ret
	.p2align 4,,10
	.p2align 3
.L31:
	cmp	r10d, 32768
	mov	r9d, 32767
	cmovge	r10d, r9d
	mov	WORD PTR [r11], r10w
	jmp	.L32
	.p2align 4,,10
	.p2align 3
.L42:
	mov	DWORD PTR 3130848[rbx], 0
	xor	r9d, r9d
	jmp	.L36
	.p2align 4,,10
	.p2align 3
.L43:
	mov	DWORD PTR 3130844[rbx], 0
	xor	esi, esi
	jmp	.L36
	.seh_endproc
	.p2align 4
	.globl	configequalizer____2
	.def	configequalizer____2;	.scl	2;	.type	32;	.endef
	.seh_proc	configequalizer____2
configequalizer____2:
	sub	rsp, 56
	.seh_stackalloc	56
	movaps	XMMWORD PTR [rsp], xmm6
	.seh_savexmm	xmm6, 0
	movaps	XMMWORD PTR 16[rsp], xmm7
	.seh_savexmm	xmm7, 16
	movaps	XMMWORD PTR 32[rsp], xmm8
	.seh_savexmm	xmm8, 32
	.seh_endprologue
	movdqa	xmm6, XMMWORD PTR .LC33[rip]
	movaps	xmm2, XMMWORD PTR .LC34[rip]
	xor	eax, eax
	movd	xmm3, DWORD PTR 104[rsp]
	movd	xmm1, DWORD PTR 120[rsp]
	movd	xmm7, DWORD PTR 144[rsp]
	movaps	xmm8, XMMWORD PTR 32[rsp]
	punpckldq	xmm3, xmm3
	punpckldq	xmm1, xmm1
	punpckldq	xmm7, xmm7
	movd	xmm5, edx
	movd	xmm0, r8d
	movd	xmm4, r9d
	punpckldq	xmm0, xmm0
	punpckldq	xmm5, xmm5
	punpckldq	xmm4, xmm4
	punpcklqdq	xmm5, xmm0
	movd	xmm0, DWORD PTR 96[rsp]
	paddd	xmm5, xmm6
	cvtdq2ps	xmm5, xmm5
	divps	xmm5, xmm2
	punpckldq	xmm0, xmm0
	punpcklqdq	xmm4, xmm0
	movd	xmm0, DWORD PTR 112[rsp]
	paddd	xmm4, xmm6
	cvtdq2ps	xmm4, xmm4
	punpckldq	xmm0, xmm0
	punpcklqdq	xmm3, xmm0
	movd	xmm0, DWORD PTR 128[rsp]
	paddd	xmm3, xmm6
	cvtdq2ps	xmm3, xmm3
	punpckldq	xmm0, xmm0
	punpcklqdq	xmm1, xmm0
	movd	xmm0, DWORD PTR 136[rsp]
	paddd	xmm1, xmm6
	cvtdq2ps	xmm1, xmm1
	punpckldq	xmm0, xmm0
	punpcklqdq	xmm0, xmm7
	movaps	xmm7, XMMWORD PTR 16[rsp]
	paddd	xmm0, xmm6
	cvtdq2ps	xmm0, xmm0
	divps	xmm4, xmm2
	cvtps2pd	xmm6, xmm5
	divps	xmm3, xmm2
	divps	xmm1, xmm2
	divps	xmm0, xmm2
	movapd	xmm2, XMMWORD PTR .LC35[rip]
	addpd	xmm6, xmm2
	movups	XMMWORD PTR 3130856[rcx], xmm6
	pxor	xmm6, xmm6
	movhlps	xmm6, xmm5
	cvtps2pd	xmm5, xmm4
	addpd	xmm5, xmm2
	cvtps2pd	xmm6, xmm6
	addpd	xmm6, xmm2
	movups	XMMWORD PTR 3130888[rcx], xmm5
	pxor	xmm5, xmm5
	movhlps	xmm5, xmm4
	cvtps2pd	xmm4, xmm3
	addpd	xmm4, xmm2
	movups	XMMWORD PTR 3130872[rcx], xmm6
	cvtps2pd	xmm5, xmm5
	addpd	xmm5, xmm2
	movaps	xmm6, XMMWORD PTR [rsp]
	movups	XMMWORD PTR 3130920[rcx], xmm4
	pxor	xmm4, xmm4
	movhlps	xmm4, xmm3
	cvtps2pd	xmm3, xmm1
	addpd	xmm3, xmm2
	movups	XMMWORD PTR 3130904[rcx], xmm5
	cvtps2pd	xmm4, xmm4
	addpd	xmm4, xmm2
	movups	XMMWORD PTR 3130952[rcx], xmm3
	pxor	xmm3, xmm3
	movhlps	xmm3, xmm1
	cvtps2pd	xmm1, xmm0
	addpd	xmm1, xmm2
	movups	XMMWORD PTR 3130936[rcx], xmm4
	cvtps2pd	xmm3, xmm3
	addpd	xmm3, xmm2
	movups	XMMWORD PTR 3130984[rcx], xmm1
	pxor	xmm1, xmm1
	movhlps	xmm1, xmm0
	movups	XMMWORD PTR 3130968[rcx], xmm3
	cvtps2pd	xmm1, xmm1
	addpd	xmm2, xmm1
	movups	XMMWORD PTR 3131000[rcx], xmm2
	add	rsp, 56
	ret
	.seh_endproc
	.p2align 4
	.globl	init_iir_60
	.def	init_iir_60;	.scl	2;	.type	32;	.endef
	.seh_proc	init_iir_60
init_iir_60:
	push	rdi
	.seh_pushreg	rdi
	.seh_endprologue
	lea	rdi, iir_cforiginal10_fixed[rip]
	movabs	rax, 4294967306
	movq	xmm0, rdi
	mov	QWORD PTR 3120904[rcx], rax
	mov	rdx, rcx
	lea	rax, iir_cforiginal10[rip]
	lea	rdi, 3117936[rcx]
	movq	xmm1, rax
	and	rdi, -8
	xor	eax, eax
	mov	DWORD PTR 3111452[rcx], 1
	mov	QWORD PTR 3111456[rcx], 2
	punpcklqdq	xmm0, xmm1
	mov	DWORD PTR 3121216[rcx], 0
	mov	QWORD PTR 3117928[rcx], 0
	mov	QWORD PTR 3120896[rcx], 0
	movups	XMMWORD PTR 3111960[rcx], xmm0
	sub	ecx, edi
	add	ecx, 3120904
	shr	ecx, 3
	rep stosq
	lea	rdi, 3114960[rdx]
	mov	ecx, edx
	mov	QWORD PTR 3114952[rdx], 0
	mov	QWORD PTR 3117920[rdx], 0
	and	rdi, -8
	sub	ecx, edi
	add	ecx, 3117928
	shr	ecx, 3
	rep stosq
	lea	rdi, 3113472[rdx]
	mov	ecx, edx
	mov	QWORD PTR 3113464[rdx], 0
	mov	QWORD PTR 3114944[rdx], 0
	and	rdi, -8
	sub	ecx, edi
	add	ecx, 3114952
	shr	ecx, 3
	rep stosq
	lea	rdi, 3111984[rdx]
	mov	QWORD PTR 3111976[rdx], 0
	mov	QWORD PTR 3113456[rdx], 0
	and	rdi, -8
	sub	edx, edi
	lea	ecx, 3113464[rdx]
	shr	ecx, 3
	rep stosq
	pop	rdi
	ret
	.seh_endproc
	.p2align 4
	.globl	iir___60
	.def	iir___60;	.scl	2;	.type	32;	.endef
	.seh_proc	iir___60
iir___60:
	push	r15
	.seh_pushreg	r15
	push	r14
	.seh_pushreg	r14
	push	r13
	.seh_pushreg	r13
	push	r12
	.seh_pushreg	r12
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 88
	.seh_stackalloc	88
	.seh_endprologue
	pxor	xmm0, xmm0
	movabs	rax, 4294967306
	movups	XMMWORD PTR 3121248[rcx], xmm0
	mov	rbx, rcx
	movups	XMMWORD PTR 3121264[rcx], xmm0
	movapd	xmm0, XMMWORD PTR .LC36[rip]
	mov	QWORD PTR 3120904[rcx], rax
	lea	rax, iir_cforiginal10_fixed[rip]
	movups	XMMWORD PTR 3111464[rcx], xmm0
	movups	XMMWORD PTR 3111480[rcx], xmm0
	movups	XMMWORD PTR 3111496[rcx], xmm0
	movups	XMMWORD PTR 3111512[rcx], xmm0
	movups	XMMWORD PTR 3111528[rcx], xmm0
	movups	XMMWORD PTR 3111544[rcx], xmm0
	movups	XMMWORD PTR 3111560[rcx], xmm0
	movups	XMMWORD PTR 3111576[rcx], xmm0
	movups	XMMWORD PTR 3111592[rcx], xmm0
	movups	XMMWORD PTR 3111608[rcx], xmm0
	movq	xmm0, rax
	lea	rax, iir_cforiginal10[rip]
	movq	xmm2, rax
	xor	eax, eax
	cmp	r9d, 1
	mov	QWORD PTR 3121280[rcx], 0
	punpcklqdq	xmm0, xmm2
	setne	al
	mov	DWORD PTR 3121216[rcx], 0
	movups	XMMWORD PTR 3111960[rcx], xmm0
	mov	ecx, r8d
	add	eax, 1
	sar	ecx
	mov	DWORD PTR 176[rsp], r8d
	mov	DWORD PTR 184[rsp], r9d
	mov	DWORD PTR 64[rsp], eax
	mov	DWORD PTR 68[rsp], ecx
	test	ecx, ecx
	jle	.L72
	mov	ecx, DWORD PTR 3111452[rbx]
	cdqe
	mov	DWORD PTR 60[rsp], 0
	mov	r13, rdx
	add	rax, rax
	mov	r14d, DWORD PTR 3111460[rbx]
	mov	r15d, DWORD PTR 3111456[rbx]
	lea	r10, .L52[rip]
	mov	DWORD PTR 40[rsp], ecx
	mov	QWORD PTR 72[rsp], rax
	.p2align 4,,10
	.p2align 3
.L49:
	mov	eax, DWORD PTR 184[rsp]
	test	eax, eax
	jle	.L70
	movsx	r8, DWORD PTR 40[rsp]
	movsx	rax, r14d
	movsx	r11, r15d
	xor	ebp, ebp
	lea	r9, 3111464[rbx]
	lea	r12, [rbx+rax*8]
	sub	r11, rax
	sub	r8, rax
.L65:
	fild	WORD PTR 0[r13+rbp*2]
	lea	rcx, iir_cforiginal10[rip]
	mov	rax, r12
	xor	edx, edx
	.p2align 4,,10
	.p2align 3
.L64:
	fst	QWORD PTR 3117928[rax]
	fld	QWORD PTR 3117928[rax+r8*8]
	mov	esi, edx
	fsubr	st, st(1)
	fmul	QWORD PTR 8[rcx]
	fld	QWORD PTR 3117952[rax+r11*8]
	fmul	QWORD PTR 16[rcx]
	faddp	st(1), st
	fld	QWORD PTR [rcx]
	fmul	QWORD PTR 3117952[rax+r8*8]
	fsubp	st(1), st
	fst	QWORD PTR 3117952[rax]
	cmp	edx, 9
	ja	.L50
	mov	edi, edx
	movsx	rdi, DWORD PTR [r10+rdi*4]
	add	rdi, r10
	jmp	rdi
	.section .rdata,"dr"
	.align 4
.L52:
	.long	.L50-.L52
	.long	.L60-.L52
	.long	.L59-.L52
	.long	.L58-.L52
	.long	.L57-.L52
	.long	.L56-.L52
	.long	.L55-.L52
	.long	.L54-.L52
	.long	.L53-.L52
	.long	.L51-.L52
	.text
	.p2align 4,,10
	.p2align 3
.L51:
	fstp	st(1)
	fmul	QWORD PTR 144[r9]
	mov	edx, DWORD PTR 3121284[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	eax, QWORD PTR 48[rsp]
	cmp	eax, edx
	cmovl	eax, edx
	mov	DWORD PTR 3121284[rbx], eax
.L62:
	add	rbp, 1
	add	r9, 8
	add	r12, 48
	cmp	DWORD PTR 184[rsp], ebp
	jg	.L65
.L70:
	add	DWORD PTR 40[rsp], 1
	mov	eax, DWORD PTR 40[rsp]
	add	r14d, 1
	add	r15d, 1
	mov	DWORD PTR 3111460[rbx], r14d
	mov	DWORD PTR 3111456[rbx], r15d
	mov	DWORD PTR 3111452[rbx], eax
	cmp	r14d, 3
	je	.L75
	cmp	r15d, 3
	je	.L76
	mov	DWORD PTR 3111452[rbx], 0
	mov	DWORD PTR 40[rsp], 0
.L67:
	mov	ecx, DWORD PTR 64[rsp]
	add	r13, QWORD PTR 72[rsp]
	add	DWORD PTR 60[rsp], ecx
	mov	eax, DWORD PTR 60[rsp]
	cmp	DWORD PTR 68[rsp], eax
	jg	.L49
	fild	DWORD PTR 3121248[rbx]
.L48:
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121284[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121248[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121256[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121252[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121260[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121256[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121264[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121260[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121268[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121264[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121272[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121268[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121276[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121272[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121280[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121276[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	fild	DWORD PTR 3121284[rbx]
	cvttsd2si	eax, xmm0
	fstp	QWORD PTR 40[rsp]
	fld	DWORD PTR .LC37[rip]
	movsd	xmm1, QWORD PTR 40[rsp]
	mov	DWORD PTR 3121280[rbx], eax
	fstp	QWORD PTR 40[rsp]
	movsd	xmm0, QWORD PTR 40[rsp]
	call	getporf
	cvttsd2si	eax, xmm0
	mov	DWORD PTR 3121284[rbx], eax
	mov	eax, DWORD PTR 176[rsp]
	add	rsp, 88
	pop	rbx
	pop	rsi
	pop	rdi
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	ret
	.p2align 4,,10
	.p2align 3
.L53:
	fmul	QWORD PTR 128[r9]
	mov	edi, DWORD PTR 3121280[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121280[rbx], esi
	.p2align 4,,10
	.p2align 3
.L61:
	add	rdx, 1
	add	rax, 96
	add	rcx, 24
	jmp	.L64
	.p2align 4,,10
	.p2align 3
.L54:
	fmul	QWORD PTR 112[r9]
	mov	edi, DWORD PTR 3121276[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121276[rbx], esi
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L55:
	fmul	QWORD PTR 96[r9]
	mov	edi, DWORD PTR 3121272[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121272[rbx], esi
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L56:
	fmul	QWORD PTR 80[r9]
	mov	edi, DWORD PTR 3121268[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121268[rbx], esi
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L57:
	fmul	QWORD PTR 64[r9]
	mov	edi, DWORD PTR 3121264[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121264[rbx], esi
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L58:
	fmul	QWORD PTR 48[r9]
	mov	edi, DWORD PTR 3121260[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121260[rbx], esi
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L59:
	fmul	QWORD PTR 32[r9]
	mov	edi, DWORD PTR 3121256[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121256[rbx], esi
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L60:
	fmul	QWORD PTR 16[r9]
	mov	edi, DWORD PTR 3121252[rbx]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	esi, QWORD PTR 48[rsp]
	cmp	esi, edi
	cmovl	esi, edi
	mov	DWORD PTR 3121252[rbx], esi
	jmp	.L61
.L50:
	fmul	QWORD PTR [r9]
	fstp	QWORD PTR 48[rsp]
	cvttsd2si	edi, QWORD PTR 48[rsp]
	cmp	edi, DWORD PTR 3121248[rbx]
	cmovl	edi, DWORD PTR 3121248[rbx]
	mov	DWORD PTR 3121248[rbx], edi
	cmp	esi, 9
	jne	.L61
	fstp	st(0)
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L75:
	mov	DWORD PTR 3111460[rbx], 0
	xor	r14d, r14d
	jmp	.L67
	.p2align 4,,10
	.p2align 3
.L76:
	mov	DWORD PTR 3111456[rbx], 0
	xor	r15d, r15d
	jmp	.L67
.L72:
	fldz
	jmp	.L48
	.seh_endproc
.lcomm ar_already_k_p.91037,4,4
	.globl	iir_cf61_fixed
	.section .rdata,"dr"
	.align 32
iir_cf61_fixed:
	.long	268356960
	.long	39247
	.long	536790237
	.long	268396743
	.long	19356
	.long	536829441
	.long	268357384
	.long	39035
	.long	536789435
	.long	268357541
	.long	38957
	.long	536788726
	.long	268317868
	.long	58793
	.long	536747918
	.long	268318213
	.long	58621
	.long	536746804
	.long	268278496
	.long	78479
	.long	536705236
	.long	268278963
	.long	78246
	.long	536703388
	.long	268279335
	.long	78060
	.long	536701172
	.long	268199592
	.long	117931
	.long	536617967
	.long	268200349
	.long	117553
	.long	536614187
	.long	268201024
	.long	117215
	.long	536609023
	.long	268121623
	.long	156916
	.long	536522226
	.long	268042040
	.long	196707
	.long	536433391
	.long	268043223
	.long	196116
	.long	536424229
	.long	267963935
	.long	235760
	.long	536331099
	.long	267884703
	.long	275376
	.long	536235107
	.long	267886491
	.long	274482
	.long	536215258
	.long	267808159
	.long	313648
	.long	536104288
	.long	267649204
	.long	393125
	.long	535908379
	.long	267570968
	.long	432243
	.long	535788827
	.long	267493370
	.long	471042
	.long	535653475
	.long	267335089
	.long	550183
	.long	535430712
	.long	267258219
	.long	588618
	.long	535267461
	.long	267101363
	.long	667046
	.long	534997569
	.long	266945214
	.long	745120
	.long	534696003
	.long	266709298
	.long	863078
	.long	534275941
	.long	266474197
	.long	980629
	.long	533810624
	.long	266239299
	.long	1098078
	.long	533318634
	.long	266005936
	.long	1214759
	.long	532741198
	.long	265693797
	.long	1370829
	.long	531979006
	.long	265383338
	.long	1526058
	.long	531089861
	.long	264994502
	.long	1720476
	.long	529968654
	.long	264527648
	.long	1953903
	.long	528587484
	.long	264061637
	.long	2186909
	.long	527101552
	.long	263599128
	.long	2418163
	.long	525275206
	.long	262979856
	.long	2727799
	.long	523009911
	.long	262364776
	.long	3035339
	.long	520275784
	.long	261520764
	.long	3457345
	.long	516245793
	.long	260601012
	.long	3917221
	.long	511734258
	.long	259763253
	.long	4336101
	.long	506899216
	.long	258700779
	.long	4867338
	.long	500281673
	.long	257643241
	.long	5396107
	.long	493057956
	.long	256365306
	.long	6035074
	.long	483591418
	.long	254947803
	.long	6743826
	.long	471552022
	.long	253241230
	.long	7597112
	.long	456358767
	.long	251404167
	.long	8515644
	.long	437680574
	.long	249366006
	.long	9534724
	.long	414973145
	.long	247349245
	.long	10543105
	.long	390350417
	.long	244928616
	.long	11753419
	.long	358449696
	.long	242194370
	.long	13120542
	.long	318372489
	.long	239093855
	.long	14670800
	.long	269256105
	.long	235653471
	.long	16390992
	.long	210593226
	.long	231973887
	.long	18230784
	.long	142380262
	.long	228401415
	.long	20017020
	.long	72299311
	.long	224281132
	.long	22077161
	.long	-12283765
	.long	220002966
	.long	24216244
	.long	-101892382
	.long	215408490
	.long	26513482
	.long	-198998775
	.long	209961370
	.long	29237042
	.long	-311405941
	.long	205982174
	.long	31226640
	.long	-397603772
	.long	205449920
	.long	31492767
	.long	-453815533
	.globl	iir_cf31_fixed
	.align 32
iir_cf31_fixed:
	.long	268274003
	.long	80726
	.long	536707280
	.long	268275874
	.long	79790
	.long	536707925
	.long	268236058
	.long	99698
	.long	536666109
	.long	268112685
	.long	161385
	.long	536539428
	.long	268032057
	.long	201699
	.long	536453900
	.long	267952789
	.long	241333
	.long	536366637
	.long	267790308
	.long	322573
	.long	536190932
	.long	267629264
	.long	403095
	.long	536010312
	.long	267385424
	.long	525015
	.long	535735907
	.long	267061351
	.long	687052
	.long	535357673
	.long	266740309
	.long	847573
	.long	534958505
	.long	266254114
	.long	1090670
	.long	534350423
	.long	265691609
	.long	1371923
	.long	533589234
	.long	264970946
	.long	1732254
	.long	532540412
	.long	264090706
	.long	2172374
	.long	531175490
	.long	262976222
	.long	2729616
	.long	529272371
	.long	261467910
	.long	3483772
	.long	526464945
	.long	259734367
	.long	4350544
	.long	522818128
	.long	257625792
	.long	5404831
	.long	517740532
	.long	254687880
	.long	6873787
	.long	509589682
	.long	251328247
	.long	8553604
	.long	498804350
	.long	247276311
	.long	10579572
	.long	483341734
	.long	242056268
	.long	13189593
	.long	459937151
	.long	235410490
	.long	16512482
	.long	424214648
	.long	227902872
	.long	20266291
	.long	375633230
	.long	218577036
	.long	24929209
	.long	303647322
	.long	207218395
	.long	30608530
	.long	198713905
	.long	194957517
	.long	36738969
	.long	67432581
	.long	181704187
	.long	43365634
	.long	-93902933
	.long	167752115
	.long	50341670
	.long	-283930397
	.long	165829927
	.long	51302764
	.long	-415873513
	.globl	iir_cf25_fixed
	.align 32
iir_cf25_fixed:
	.long	268275874
	.long	79790
	.long	536707925
	.long	268236058
	.long	99698
	.long	536666109
	.long	268112685
	.long	161385
	.long	536539428
	.long	268032057
	.long	201699
	.long	536453900
	.long	267790308
	.long	322573
	.long	536190932
	.long	267629264
	.long	403095
	.long	536010312
	.long	267385424
	.long	525015
	.long	535735907
	.long	267061351
	.long	687052
	.long	535357673
	.long	266254114
	.long	1090670
	.long	534350423
	.long	265691609
	.long	1371923
	.long	533589234
	.long	264970946
	.long	1732254
	.long	532540412
	.long	264090706
	.long	2172374
	.long	531175490
	.long	261467910
	.long	3483772
	.long	526464945
	.long	259734367
	.long	4350544
	.long	522818128
	.long	257625792
	.long	5404831
	.long	517740532
	.long	254687880
	.long	6873787
	.long	509589682
	.long	247276311
	.long	10579572
	.long	483341734
	.long	242056268
	.long	13189593
	.long	459937151
	.long	235410490
	.long	16512482
	.long	424214648
	.long	227902872
	.long	20266291
	.long	375633230
	.long	207218395
	.long	30608530
	.long	198713905
	.long	194957517
	.long	36738969
	.long	67432581
	.long	181704187
	.long	43365634
	.long	-93902933
	.long	167752115
	.long	50341670
	.long	-283930397
	.long	165829927
	.long	51302764
	.long	-415873513
	.globl	iir_cf21_fixed
	.align 32
iir_cf21_fixed:
	.long	268274881
	.long	80287
	.long	536707701
	.long	268194219
	.long	120618
	.long	536624098
	.long	268114386
	.long	160534
	.long	536539299
	.long	267952789
	.long	241333
	.long	536366637
	.long	267709774
	.long	362840
	.long	536101153
	.long	267385424
	.long	525015
	.long	535735907
	.long	266898051
	.long	768702
	.long	535167116
	.long	266254114
	.long	1090670
	.long	534350423
	.long	265369524
	.long	1532965
	.long	533141419
	.long	264090706
	.long	2172374
	.long	531175490
	.long	262339182
	.long	3048136
	.long	528137099
	.long	259734367
	.long	4350544
	.long	522818128
	.long	256385835
	.long	6024810
	.long	514415390
	.long	251328247
	.long	8553604
	.long	498804350
	.long	244833155
	.long	11801150
	.long	472964815
	.long	235410490
	.long	16512482
	.long	424214648
	.long	223572414
	.long	22431520
	.long	343538009
	.long	207218395
	.long	30608530
	.long	198713905
	.long	189368132
	.long	39533661
	.long	1630645
	.long	167752115
	.long	50341670
	.long	-283930397
	.long	187989315
	.long	40223070
	.long	-456413190
	.globl	iir_cf15_fixed
	.align 32
iir_cf15_fixed:
	.long	268005537
	.long	214959
	.long	536437590
	.long	267747918
	.long	343768
	.long	536174667
	.long	267411534
	.long	511960
	.long	535825404
	.long	266719915
	.long	857770
	.long	535101055
	.long	265598417
	.long	1418519
	.long	533895120
	.long	264070475
	.long	2182490
	.long	532168168
	.long	261447357
	.long	3494049
	.long	529022543
	.long	257526751
	.long	5454352
	.long	523844838
	.long	251215945
	.long	8609755
	.long	514386019
	.long	241393951
	.long	13520752
	.long	496639678
	.long	227487871
	.long	20473792
	.long	464795368
	.long	206053922
	.long	31190766
	.long	399497795
	.long	177548754
	.long	45443350
	.long	278066606
	.long	141471388
	.long	63482033
	.long	59649322
	.long	107883029
	.long	80276213
	.long	-244959426
	.globl	iir_cf10_fixed
	.align 32
iir_cf10_fixed:
	.long	267692260
	.long	371597
	.long	536122402
	.long	266841330
	.long	797062
	.long	535255564
	.long	265145182
	.long	1645136
	.long	533496021
	.long	261783927
	.long	3325764
	.long	529883071
	.long	255297227
	.long	6569114
	.long	522404315
	.long	242802136
	.long	12816659
	.long	506057464
	.long	219523755
	.long	24455850
	.long	468282367
	.long	179468390
	.long	44483532
	.long	377114024
	.long	120423725
	.long	74005865
	.long	162453696
	.long	64964713
	.long	101735371
	.long	-217022329
	.globl	iir_cf08_fixed
	.align 32
iir_cf08_fixed:
	.long	267796666
	.long	319394
	.long	536228720
	.long	266788321
	.long	823567
	.long	535202216
	.long	264240104
	.long	2097675
	.long	532537160
	.long	257850370
	.long	5292542
	.long	525431396
	.long	242802136
	.long	12816659
	.long	506057464
	.long	208691709
	.long	29871873
	.long	447178999
	.long	142487663
	.long	62973896
	.long	256206374
	.long	64964713
	.long	101735371
	.long	-217022329
	.globl	iir_cf06_fixed
	.align 32
iir_cf06_fixed:
	.long	267613607
	.long	410924
	.long	536043491
	.long	265777438
	.long	1329008
	.long	534158674
	.long	259999967
	.long	4217744
	.long	527886300
	.long	242802136
	.long	12816659
	.long	506057464
	.long	194488999
	.long	36973228
	.long	415639099
	.long	99454290
	.long	84490582
	.long	53535027
	.globl	iir_cforiginal10_fixed
	.align 32
iir_cforiginal10_fixed:
	.long	266882570
	.long	776442
	.long	535298466
	.long	263966111
	.long	2234672
	.long	532245407
	.long	260269902
	.long	4082776
	.long	528189750
	.long	252769356
	.long	7833049
	.long	519301549
	.long	242802136
	.long	12816659
	.long	506057464
	.long	198481413
	.long	34977021
	.long	424910744
	.long	146827934
	.long	60803760
	.long	272548910
	.long	83277296
	.long	92579079
	.long	-48700827
	.long	71722302
	.long	98356576
	.long	-139902499
	.long	64964713
	.long	101735371
	.long	-217022329
	.globl	iir_cf61
	.align 32
iir_cf61:
	.long	3247772103
	.long	1072692634
	.long	1544920370
	.long	1059269107
	.long	3715847925
	.long	1073741508
	.long	2402390597
	.long	1072692945
	.long	3926134190
	.long	1058203404
	.long	20443000
	.long	1073741662
	.long	298377021
	.long	1072692638
	.long	3038144369
	.long	1059262321
	.long	3149398446
	.long	1073741505
	.long	1269018410
	.long	1072692639
	.long	3788672562
	.long	1059259810
	.long	4133538318
	.long	1073741502
	.long	1489055667
	.long	1072692329
	.long	4154187692
	.long	1059894585
	.long	2394771949
	.long	1073741343
	.long	197770300
	.long	1072692332
	.long	2972823496
	.long	1059889057
	.long	876145841
	.long	1073741339
	.long	3245321951
	.long	1072692021
	.long	1051106009
	.long	1060317434
	.long	3569809911
	.long	1073741176
	.long	1727981479
	.long	1072692025
	.long	109462508
	.long	1060313700
	.long	2623694668
	.long	1073741169
	.long	1326066966
	.long	1072692028
	.long	3638253769
	.long	1060310723
	.long	4107940808
	.long	1073741160
	.long	1346779566
	.long	1072691405
	.long	3841222276
	.long	1060948670
	.long	4017206030
	.long	1073740835
	.long	990518272
	.long	1072691411
	.long	3606024423
	.long	1060942611
	.long	734263981
	.long	1073740821
	.long	2148341575
	.long	1072691416
	.long	3457401889
	.long	1060937215
	.long	4286526125
	.long	1073740800
	.long	789318111
	.long	1072690796
	.long	3883457105
	.long	1061365665
	.long	4064017957
	.long	1073740461
	.long	1893712450
	.long	1072690174
	.long	1091980181
	.long	1061683998
	.long	4025232025
	.long	1073740114
	.long	2924816774
	.long	1072690183
	.long	1458888253
	.long	1061679267
	.long	624118424
	.long	1073740079
	.long	1055561069
	.long	1072689564
	.long	733553636
	.long	1061996418
	.long	1539930686
	.long	1073739715
	.long	1057911297
	.long	1072688945
	.long	4055842970
	.long	1062260416
	.long	1667691738
	.long	1073739340
	.long	912533166
	.long	1072688959
	.long	2611021342
	.long	1062256841
	.long	3660069260
	.long	1073739262
	.long	1068545246
	.long	1072688347
	.long	1320178214
	.long	1062413504
	.long	1621645511
	.long	1073738829
	.long	1777236082
	.long	1072687105
	.long	293174153
	.long	1062731414
	.long	458149783
	.long	1073738064
	.long	828630841
	.long	1072686494
	.long	2626709262
	.long	1062887886
	.long	462679331
	.long	1073737597
	.long	4112340702
	.long	1072685887
	.long	3805502215
	.long	1063043082
	.long	1661147445
	.long	1073737068
	.long	1655695011
	.long	1072684651
	.long	2820325765
	.long	1063307854
	.long	945774394
	.long	1073736198
	.long	3610185913
	.long	1072684050
	.long	1752209976
	.long	1063384724
	.long	2244224618
	.long	1073735560
	.long	1712538354
	.long	1072682825
	.long	4136848781
	.long	1063541580
	.long	1092336655
	.long	1073734506
	.long	2092489111
	.long	1072681605
	.long	2739260581
	.long	1063697729
	.long	1130818682
	.long	1073733328
	.long	1689350006
	.long	1072679762
	.long	2801227875
	.long	1063933645
	.long	1701664448
	.long	1073731687
	.long	2878386949
	.long	1072677925
	.long	929738018
	.long	1064168746
	.long	3230218707
	.long	1073729869
	.long	2269277826
	.long	1072676090
	.long	795222464
	.long	1064354142
	.long	3929340097
	.long	1073727947
	.long	1613998715
	.long	1072674267
	.long	4077227008
	.long	1064470823
	.long	1322131946
	.long	1073725692
	.long	3417860218
	.long	1072671828
	.long	302353380
	.long	1064626893
	.long	4270252474
	.long	1073722714
	.long	1410233350
	.long	1072669403
	.long	4232962612
	.long	1064782122
	.long	3319096191
	.long	1073719241
	.long	2360642581
	.long	1072666365
	.long	3539080992
	.long	1064976540
	.long	245981862
	.long	1073714862
	.long	1076449855
	.long	1072662718
	.long	4123843852
	.long	1065209967
	.long	3697141274
	.long	1073709466
	.long	2337034571
	.long	1072659077
	.long	2523382725
	.long	1065398094
	.long	1885038799
	.long	1073703662
	.long	827901645
	.long	1072655464
	.long	3571169023
	.long	1065513721
	.long	1189112150
	.long	1073696528
	.long	567155717
	.long	1072650626
	.long	3327006447
	.long	1065668539
	.long	2009334190
	.long	1073687679
	.long	3508567641
	.long	1072645820
	.long	3690528951
	.long	1065822309
	.long	1216246777
	.long	1073676999
	.long	4193575875
	.long	1072639226
	.long	3243949004
	.long	1066033312
	.long	569930093
	.long	1073661257
	.long	1752640094
	.long	1072632041
	.long	4045059122
	.long	1066263250
	.long	4061356259
	.long	1073643633
	.long	1789753714
	.long	1072625496
	.long	1428423424
	.long	1066437241
	.long	276259333
	.long	1073624747
	.long	3591465980
	.long	1072617195
	.long	2666086471
	.long	1066570050
	.long	1230027616
	.long	1073598897
	.long	3537522532
	.long	1072608933
	.long	3529758097
	.long	1066702242
	.long	2758821129
	.long	1073570679
	.long	4109637310
	.long	1072598949
	.long	2965856231
	.long	1066861984
	.long	4204235157
	.long	1073533700
	.long	3069575485
	.long	1072587875
	.long	2426688028
	.long	1067039172
	.long	382264129
	.long	1073486672
	.long	496067013
	.long	1072574543
	.long	652862385
	.long	1067252494
	.long	1868471797
	.long	1073427323
	.long	260389422
	.long	1072560191
	.long	2211707802
	.long	1067466247
	.long	3193762420
	.long	1073354361
	.long	3976104350
	.long	1072544267
	.long	2551047683
	.long	1067593632
	.long	3648353744
	.long	1073265660
	.long	4208802176
	.long	1072528511
	.long	689465074
	.long	1067719680
	.long	1363229932
	.long	1073169478
	.long	3490376968
	.long	1072509600
	.long	2141899440
	.long	1067870969
	.long	539593688
	.long	1073044866
	.long	2225012984
	.long	1072488239
	.long	3674732611
	.long	1068041859
	.long	2302221658
	.long	1072888314
	.long	3197278483
	.long	1072464016
	.long	191431800
	.long	1068235642
	.long	2845445933
	.long	1072696453
	.long	3205278529
	.long	1072437138
	.long	127575543
	.long	1068450666
	.long	2507981537
	.long	1072241355
	.long	4271702685
	.long	1072408391
	.long	93130500
	.long	1068589792
	.long	3448663344
	.long	1071708441
	.long	246099729
	.long	1072380482
	.long	3310424263
	.long	1068701431
	.long	3193500033
	.long	1070677196
	.long	1488215552
	.long	1072348292
	.long	2637000325
	.long	1068830190
	.long	2887544579
	.long	-1079546386
	.long	740785756
	.long	1072314869
	.long	1331824273
	.long	1068963883
	.long	2026384449
	.long	-1076344060
	.long	3578537218
	.long	1072278974
	.long	2865648254
	.long	1069107460
	.long	3999162604
	.long	-1075332875
	.long	884910268
	.long	1072236419
	.long	755326225
	.long	1069277683
	.long	1962976141
	.long	-1074622547
	.long	3165210830
	.long	1072205331
	.long	224418855
	.long	1069402033
	.long	3166440876
	.long	-1074285837
	.long	2180488040
	.long	1072201173
	.long	4162949727
	.long	1069418665
	.long	3980360516
	.long	-1074066260
	.globl	iir_cf31
	.align 32
iir_cf31:
	.long	2788841931
	.long	1072691986
	.long	364173001
	.long	1060353383
	.long	3491922266
	.long	1073741184
	.long	1147753888
	.long	1072692001
	.long	1479368235
	.long	1060338414
	.long	1435475322
	.long	1073741187
	.long	886781109
	.long	1072691690
	.long	2511823416
	.long	1060656940
	.long	4254674153
	.long	1073741023
	.long	1531430933
	.long	1072690726
	.long	1907314355
	.long	1061401417
	.long	610416750
	.long	1073740529
	.long	1920088591
	.long	1072690096
	.long	453021307
	.long	1061723931
	.long	215548699
	.long	1073740195
	.long	721148654
	.long	1072689477
	.long	150421358
	.long	1062041002
	.long	766977970
	.long	1073739854
	.long	3368282711
	.long	1072688207
	.long	1003440717
	.long	1062449207
	.long	3567115227
	.long	1073739167
	.long	2702966114
	.long	1072686949
	.long	3820303844
	.long	1062771294
	.long	1218006436
	.long	1073738462
	.long	2699961105
	.long	1072685044
	.long	2302632974
	.long	1063257519
	.long	1669569704
	.long	1073737390
	.long	3458228304
	.long	1072682512
	.long	4024528795
	.long	1063581592
	.long	3924250238
	.long	1073735912
	.long	2854410647
	.long	1072680004
	.long	4006314007
	.long	1063902634
	.long	2837798609
	.long	1073734353
	.long	1158957208
	.long	1072676206
	.long	3134074775
	.long	1064346734
	.long	1463306600
	.long	1073731978
	.long	2997959806
	.long	1072671811
	.long	1406406557
	.long	1064627987
	.long	4075921270
	.long	1073729004
	.long	2244153458
	.long	1072666181
	.long	2404334967
	.long	1064988318
	.long	4231179789
	.long	1073724907
	.long	2772218194
	.long	1072659304
	.long	1484714500
	.long	1065390827
	.long	1120006525
	.long	1073719576
	.long	3177060047
	.long	1072650597
	.long	1413293599
	.long	1065669448
	.long	864058689
	.long	1073712142
	.long	204009721
	.long	1072638814
	.long	2062199993
	.long	1066046526
	.long	2979976018
	.long	1073701175
	.long	3198369374
	.long	1072625270
	.long	366274028
	.long	1066440852
	.long	1345787279
	.long	1073686930
	.long	2161614439
	.long	1072608797
	.long	4069162862
	.long	1066704423
	.long	4103187839
	.long	1073667095
	.long	293927342
	.long	1072585845
	.long	3886808894
	.long	1067071662
	.long	2993321011
	.long	1073635256
	.long	4025416479
	.long	1072559597
	.long	2156694767
	.long	1067470992
	.long	2126604142
	.long	1073593126
	.long	784382271
	.long	1072527942
	.long	2314732306
	.long	1067724238
	.long	2794871916
	.long	1073532725
	.long	2581190979
	.long	1072487160
	.long	825596875
	.long	1068050491
	.long	2138711524
	.long	1073441301
	.long	1950812288
	.long	1072435240
	.long	1573082650
	.long	1068465852
	.long	2016148963
	.long	1073301760
	.long	815185398
	.long	1072376587
	.long	1034225706
	.long	1068717011
	.long	1314032064
	.long	1073111989
	.long	408081278
	.long	1072303729
	.long	2662498070
	.long	1069008443
	.long	1514000244
	.long	1072830794
	.long	3056008215
	.long	1072214989
	.long	660869029
	.long	1069363401
	.long	1647806235
	.long	1072148548
	.long	2614024596
	.long	1072119201
	.long	3361885401
	.long	1069647036
	.long	394639704
	.long	1070601154
	.long	4134391803
	.long	1072015659
	.long	321150986
	.long	1069854120
	.long	1429245753
	.long	-1076468895
	.long	1730948049
	.long	1071906659
	.long	833071197
	.long	1070072121
	.long	498777617
	.long	-1074729873
	.long	1341429343
	.long	1071891642
	.long	1612288755
	.long	1070102155
	.long	3920502663
	.long	-1074214471
	.globl	iir_cf25
	.align 32
iir_cf25:
	.long	1147753888
	.long	1072692001
	.long	1479368235
	.long	1060338414
	.long	1435475322
	.long	1073741187
	.long	886781109
	.long	1072691690
	.long	2511823416
	.long	1060656940
	.long	4254674153
	.long	1073741023
	.long	1531430933
	.long	1072690726
	.long	1907314355
	.long	1061401417
	.long	610416750
	.long	1073740529
	.long	1920088591
	.long	1072690096
	.long	453021307
	.long	1061723931
	.long	215548699
	.long	1073740195
	.long	3368282711
	.long	1072688207
	.long	1003440717
	.long	1062449207
	.long	3567115227
	.long	1073739167
	.long	2702966114
	.long	1072686949
	.long	3820303844
	.long	1062771294
	.long	1218006436
	.long	1073738462
	.long	2699961105
	.long	1072685044
	.long	2302632974
	.long	1063257519
	.long	1669569704
	.long	1073737390
	.long	3458228304
	.long	1072682512
	.long	4024528795
	.long	1063581592
	.long	3924250238
	.long	1073735912
	.long	1158957208
	.long	1072676206
	.long	3134074775
	.long	1064346734
	.long	1463306600
	.long	1073731978
	.long	2997959806
	.long	1072671811
	.long	1406406557
	.long	1064627987
	.long	4075921270
	.long	1073729004
	.long	2244153458
	.long	1072666181
	.long	2404334967
	.long	1064988318
	.long	4231179789
	.long	1073724907
	.long	2772218194
	.long	1072659304
	.long	1484714500
	.long	1065390827
	.long	1120006525
	.long	1073719576
	.long	204009721
	.long	1072638814
	.long	2062199993
	.long	1066046526
	.long	2979976018
	.long	1073701175
	.long	3198369374
	.long	1072625270
	.long	366274028
	.long	1066440852
	.long	1345787279
	.long	1073686930
	.long	2161614439
	.long	1072608797
	.long	4069162862
	.long	1066704423
	.long	4103187839
	.long	1073667095
	.long	293927342
	.long	1072585845
	.long	3886808894
	.long	1067071662
	.long	2993321011
	.long	1073635256
	.long	784382271
	.long	1072527942
	.long	2314732306
	.long	1067724238
	.long	2794871916
	.long	1073532725
	.long	2581190979
	.long	1072487160
	.long	825596875
	.long	1068050491
	.long	2138711524
	.long	1073441301
	.long	1950812288
	.long	1072435240
	.long	1573082650
	.long	1068465852
	.long	2016148963
	.long	1073301760
	.long	815185398
	.long	1072376587
	.long	1034225706
	.long	1068717011
	.long	1314032064
	.long	1073111989
	.long	3056008215
	.long	1072214989
	.long	660869029
	.long	1069363401
	.long	1647806235
	.long	1072148548
	.long	2614024596
	.long	1072119201
	.long	3361885401
	.long	1069647036
	.long	394639704
	.long	1070601154
	.long	4134391803
	.long	1072015659
	.long	321150986
	.long	1069854120
	.long	1429245753
	.long	-1076468895
	.long	1730948049
	.long	1071906659
	.long	833071197
	.long	1070072121
	.long	498777617
	.long	-1074729873
	.long	1341429343
	.long	1071891642
	.long	1612288755
	.long	1070102155
	.long	3920502663
	.long	-1074214471
	.globl	iir_cf21
	.align 32
iir_cf21:
	.long	2211119203
	.long	1072691993
	.long	3590979492
	.long	1060346352
	.long	1968585849
	.long	1073741186
	.long	1461807306
	.long	1072691363
	.long	2008448104
	.long	1060991651
	.long	3795702815
	.long	1073740859
	.long	2755391708
	.long	1072690739
	.long	2295030486
	.long	1061394615
	.long	2735549746
	.long	1073740528
	.long	721148654
	.long	1072689477
	.long	150421358
	.long	1062041002
	.long	766977970
	.long	1073739854
	.long	2624580875
	.long	1072687578
	.long	2409321658
	.long	1062610275
	.long	553805095
	.long	1073738817
	.long	2699961105
	.long	1072685044
	.long	2302632974
	.long	1063257519
	.long	1669569704
	.long	1073737390
	.long	125444865
	.long	1072681237
	.long	1124771150
	.long	1063744892
	.long	2356508505
	.long	1073735168
	.long	1158957208
	.long	1072676206
	.long	3134074775
	.long	1064346734
	.long	1463306600
	.long	1073731978
	.long	1769558324
	.long	1072669295
	.long	2711000761
	.long	1064789029
	.long	2870665211
	.long	1073727255
	.long	2772218194
	.long	1072659304
	.long	1484714500
	.long	1065390827
	.long	1120006525
	.long	1073719576
	.long	3695211587
	.long	1072645620
	.long	2011160593
	.long	1065828708
	.long	2343911180
	.long	1073707707
	.long	3198369374
	.long	1072625270
	.long	366274028
	.long	1066440852
	.long	1345787279
	.long	1073686930
	.long	1459156604
	.long	1072599110
	.long	2422721658
	.long	1066859418
	.long	519320013
	.long	1073654107
	.long	4025416479
	.long	1072559597
	.long	2156694767
	.long	1067470992
	.long	2126604142
	.long	1073593126
	.long	118737844
	.long	1072508855
	.long	3345208659
	.long	1067876935
	.long	3486694748
	.long	1073492190
	.long	1950812288
	.long	1072435240
	.long	1573082650
	.long	1068465852
	.long	2016148963
	.long	1073301760
	.long	2092463251
	.long	1072342755
	.long	220009532
	.long	1068852338
	.long	1507671015
	.long	1072986617
	.long	3056008215
	.long	1072214989
	.long	660869029
	.long	1069363401
	.long	1647806235
	.long	1072148548
	.long	2293884017
	.long	1072075534
	.long	4002346702
	.long	1069734370
	.long	2234205738
	.long	1064886709
	.long	1730948049
	.long	1071906659
	.long	833071197
	.long	1070072121
	.long	498777617
	.long	-1074729873
	.long	2272970778
	.long	1072064762
	.long	4043993036
	.long	1069755914
	.long	106981602
	.long	-1074056112
	.globl	iir_cf15
	.align 32
iir_cf15:
	.long	1123687777
	.long	1072689889
	.long	217213647
	.long	1061830010
	.long	1452040125
	.long	1073740131
	.long	2647250693
	.long	1072687876
	.long	916495099
	.long	1062533986
	.long	1267946254
	.long	1073739104
	.long	2617993129
	.long	1072685248
	.long	4105007983
	.long	1063206755
	.long	4228801325
	.long	1073737739
	.long	1449631226
	.long	1072679845
	.long	3430606306
	.long	1063923028
	.long	2139766616
	.long	1073734910
	.long	2731177120
	.long	1072671083
	.long	1299245810
	.long	1064674583
	.long	3495370774
	.long	1073730199
	.long	2519485155
	.long	1072659146
	.long	979816023
	.long	1065395885
	.long	3906272343
	.long	1073723453
	.long	2055371710
	.long	1072638653
	.long	2948158491
	.long	1066051664
	.long	1328077225
	.long	1073711166
	.long	3196635752
	.long	1072608023
	.long	393435519
	.long	1066716804
	.long	3859657009
	.long	1073690940
	.long	2480571416
	.long	1072558720
	.long	1629976924
	.long	1067478011
	.long	1676954024
	.long	1073653992
	.long	1058222591
	.long	1072481986
	.long	124153862
	.long	1068091886
	.long	3198548814
	.long	1073584670
	.long	4263267848
	.long	1072373344
	.long	126869850
	.long	1068729980
	.long	3905913023
	.long	1073460278
	.long	1146375452
	.long	1072205892
	.long	4004432783
	.long	1069399790
	.long	1127809539
	.long	1073205210
	.long	2762360325
	.long	1071983195
	.long	3065033798
	.long	1069919048
	.long	2934736832
	.long	1072730869
	.long	939647123
	.long	1071701341
	.long	2415673050
	.long	1070482757
	.long	1373650927
	.long	1070362985
	.long	1472473712
	.long	1071233192
	.long	3558640368
	.long	1070801835
	.long	2231844909
	.long	-1074973807
	.globl	iir_cf10
	.align 32
iir_cf10:
	.long	3360114835
	.long	1072687441
	.long	3100412180
	.long	1062645303
	.long	572863150
	.long	1073738900
	.long	3858282619
	.long	1072680793
	.long	56221527
	.long	1063801613
	.long	216337269
	.long	1073735514
	.long	3181691982
	.long	1072667542
	.long	2532333932
	.long	1064901200
	.long	3575801809
	.long	1073728640
	.long	4012285583
	.long	1072641282
	.long	456456676
	.long	1065967522
	.long	3215187064
	.long	1073714527
	.long	2537232944
	.long	1072590605
	.long	2353369391
	.long	1066995494
	.long	3675812947
	.long	1073685313
	.long	2982544126
	.long	1072492987
	.long	1909306656
	.long	1068003874
	.long	4161634799
	.long	1073621458
	.long	1462895735
	.long	1072311125
	.long	2738495768
	.long	1068978858
	.long	4283477839
	.long	1073473899
	.long	3426987396
	.long	1071998192
	.long	1735959799
	.long	1069889054
	.long	2827934671
	.long	1073117773
	.long	3061923851
	.long	1071429140
	.long	2764005370
	.long	1070703861
	.long	2175333178
	.long	1071865265
	.long	1329331108
	.long	1070529091
	.long	741318975
	.long	1071137135
	.long	4073927548
	.long	-1075192066
	.globl	iir_cf08
	.align 32
iir_cf08:
	.long	1950388228
	.long	1072688257
	.long	3215476547
	.long	1062436491
	.long	1887728204
	.long	1073739315
	.long	3278700837
	.long	1072680379
	.long	1230090269
	.long	1063854622
	.long	2832622988
	.long	1073735305
	.long	3510595756
	.long	1072660471
	.long	3625283390
	.long	1065353477
	.long	1216433254
	.long	1073724895
	.long	81918366
	.long	1072610552
	.long	2983696977
	.long	1066676351
	.long	1678955135
	.long	1073697138
	.long	2982544126
	.long	1072492987
	.long	1909306656
	.long	1068003874
	.long	4161634799
	.long	1073621458
	.long	4222342178
	.long	1072226499
	.long	290500472
	.long	1069317360
	.long	4145545865
	.long	1073391464
	.long	3751794038
	.long	1071709280
	.long	1086166371
	.long	1070466878
	.long	1293566458
	.long	1072597708
	.long	1329331108
	.long	1070529091
	.long	741318975
	.long	1071137135
	.long	4073927548
	.long	-1075192066
	.globl	iir_cf06
	.align 32
iir_cf06:
	.long	1318499248
	.long	1072686827
	.long	1759230296
	.long	1062802609
	.long	3825199634
	.long	1073738591
	.long	1037064117
	.long	1072672482
	.long	2349217909
	.long	1064585072
	.long	1390631960
	.long	1073731229
	.long	3197799475
	.long	1072627345
	.long	374239489
	.long	1066407652
	.long	3705034448
	.long	1073706727
	.long	2982544126
	.long	1072492987
	.long	1909306656
	.long	1068003874
	.long	4161634799
	.long	1073621458
	.long	1324905442
	.long	1072115541
	.long	1645156412
	.long	1069654357
	.long	996763586
	.long	1073268262
	.long	1267273441
	.long	1071101493
	.long	1513756856
	.long	1070867685
	.long	2582166554
	.long	1070171913
	.globl	iir_cforiginal10
	.align 32
iir_cforiginal10:
	.long	340952399
	.long	1072681116
	.long	3601580325
	.long	1063760373
	.long	2723892723
	.long	1073735681
	.long	1056841517
	.long	1072658331
	.long	541847465
	.long	1065421976
	.long	2683799252
	.long	1073723755
	.long	2622089469
	.long	1072629454
	.long	1993059360
	.long	1066346028
	.long	920281997
	.long	1073707913
	.long	2580803951
	.long	1072570856
	.long	1656233279
	.long	1067311478
	.long	2904413181
	.long	1073673193
	.long	2982544126
	.long	1072492987
	.long	1909306656
	.long	1068003874
	.long	4161634799
	.long	1073621458
	.long	168367424
	.long	1072146732
	.long	3958232448
	.long	1069591975
	.long	2563488051
	.long	1073304479
	.long	1015699551
	.long	1071743189
	.long	2263568195
	.long	1070399061
	.long	776798808
	.long	1072709316
	.long	3275612001
	.long	1070848727
	.long	509767719
	.long	1070994068
	.long	3696290340
	.long	-1077462804
	.long	4195986532
	.long	1070668180
	.long	2196974030
	.long	1071084341
	.long	1178140607
	.long	-1075794564
	.long	1329331108
	.long	1070529091
	.long	741318975
	.long	1071137135
	.long	4073927548
	.long	-1075192066
	.globl	iir_cforiginal10_48000
	.align 32
iir_cforiginal10_48000:
	.long	2282807361
	.long	1072681633
	.long	4149020114
	.long	1063694139
	.long	1133042334
	.long	1073735952
	.long	600030147
	.long	1072660507
	.long	254275026
	.long	1065351479
	.long	1701490726
	.long	1073724938
	.long	1027402665
	.long	1072633928
	.long	1483429563
	.long	1066202872
	.long	591823129
	.long	1073710462
	.long	2259224508
	.long	1072579955
	.long	2506537078
	.long	1067165895
	.long	2425421056
	.long	1073678887
	.long	1224266263
	.long	1072507848
	.long	3091060012
	.long	1067884989
	.long	3335288918
	.long	1073631975
	.long	631080972
	.long	1072184800
	.long	1771003698
	.long	1069484159
	.long	2263469150
	.long	1073347315
	.long	273199700
	.long	1071800331
	.long	3748567895
	.long	1070284777
	.long	2534182547
	.long	1072811888
	.long	229352848
	.long	1070962288
	.long	4180200800
	.long	1070937287
	.long	4131713590
	.long	1016568307
	.long	2943314694
	.long	1070761658
	.long	2823309949
	.long	1071037602
	.long	4171658738
	.long	-1076536321
	.long	3774976757
	.long	1070622103
	.long	259995269
	.long	1071107380
	.long	4164969661
	.long	-1075570331
	.align 4
.LC0:
	.long	1056964608
	.align 8
.LC2:
	.long	3601580325
	.long	1063760373
	.align 8
.LC3:
	.long	2723892723
	.long	1073735681
	.align 8
.LC4:
	.long	340952399
	.long	1072681116
	.align 4
.LC5:
	.long	0
	.align 8
.LC6:
	.long	541847465
	.long	1065421976
	.align 8
.LC7:
	.long	2683799252
	.long	1073723755
	.align 8
.LC8:
	.long	1056841517
	.long	1072658331
	.align 8
.LC9:
	.long	1993059360
	.long	1066346028
	.align 8
.LC10:
	.long	920281997
	.long	1073707913
	.align 8
.LC11:
	.long	2622089469
	.long	1072629454
	.align 8
.LC12:
	.long	1656233279
	.long	1067311478
	.align 8
.LC13:
	.long	2904413181
	.long	1073673193
	.align 8
.LC14:
	.long	2580803951
	.long	1072570856
	.align 8
.LC15:
	.long	1909306656
	.long	1068003874
	.align 8
.LC16:
	.long	4161634799
	.long	1073621458
	.align 8
.LC17:
	.long	2982544126
	.long	1072492987
	.align 8
.LC18:
	.long	3958232448
	.long	1069591975
	.align 8
.LC19:
	.long	2563488051
	.long	1073304479
	.align 8
.LC20:
	.long	168367424
	.long	1072146732
	.align 8
.LC21:
	.long	2263568195
	.long	1070399061
	.align 8
.LC22:
	.long	776798808
	.long	1072709316
	.align 8
.LC23:
	.long	1015699551
	.long	1071743189
	.align 8
.LC24:
	.long	509767719
	.long	1070994068
	.align 8
.LC25:
	.long	3696290340
	.long	-1077462804
	.align 8
.LC26:
	.long	3275612001
	.long	1070848727
	.align 8
.LC27:
	.long	2196974030
	.long	1071084341
	.align 8
.LC28:
	.long	1178140607
	.long	-1075794564
	.align 8
.LC29:
	.long	4195986532
	.long	1070668180
	.align 8
.LC30:
	.long	741318975
	.long	1071137135
	.align 8
.LC31:
	.long	4073927548
	.long	-1075192066
	.align 8
.LC32:
	.long	1329331108
	.long	1070529091
	.align 16
.LC33:
	.long	-12
	.long	-12
	.long	-12
	.long	-12
	.align 16
.LC34:
	.long	1114636288
	.long	1114636288
	.long	1114636288
	.long	1114636288
	.align 16
.LC35:
	.long	1161634035
	.long	-1077866226
	.long	1161634035
	.long	-1077866226
	.align 16
.LC36:
	.long	0
	.long	1071644672
	.long	0
	.long	1071644672
	.align 4
.LC37:
	.long	1174011904
	.ident	"GCC: (GNU) 9.2.0"
	.def	genrand;	.scl	2;	.type	32;	.endef
	.def	sgenrand;	.scl	2;	.type	32;	.endef
	.def	getporf;	.scl	2;	.type	32;	.endef
