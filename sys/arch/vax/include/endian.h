/*	$OpenBSD: endian.h,v 1.10 2000/04/26 03:08:41 bjc Exp $	*/

/*-
 * Copyright (c) 1997 Niklas Hallqvist.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Niklas Hallqvist.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _VAX_ENDIAN_H_
#define _VAX_ENDIAN_H_

#ifdef	__GNUC__

#define	__swap32md(x) ({						\
	u_int32_t __swap32md_y, __swap32md_x = (x);			\
									\
	__asm ("rotl $-8, %1, %0; insv %0, $16, $8, %0; "		\
	    "rotl $8, %1, r1; movb r1, %0" :				\
	    "&=r" (__swap32md_y) : "r" (__swap32md_x) : "r1", "cc");	\
	__swap32md_y;							\
})

#define __swap16md(x) ({						\
	u_int16_t __swap16md_y, __swap16md_x = (x);			\
									\
	__asm ("rotl $8, %1, %0; rotl $-8, %1, r1; movb r1, %0; "	\
	    "movzwl %0, %0" :						\
	    "&=r" (__swap16md_y) : "r" (__swap16md_x) : "r1", "cc");	\
	__swap16md_y;							\
})

/* Tell sys/endian.h we have MD variants of the swap macros.  */
#ifdef notyet
#define MD_SWAP
#endif

#endif /* __GNUC__ */

#define BYTE_ORDER LITTLE_ENDIAN
#include <sys/endian.h>

#endif /* _VAX_ENDIAN_H_ */
