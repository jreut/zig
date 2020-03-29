/*	$OpenBSD: spr.h,v 1.2 2002/10/27 13:24:26 miod Exp $	*/

/* lib/des/spr.h */
/* Copyright (C) 1995 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 * 
 * This file is part of an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL
 * specification.  This library and applications are
 * FREE FOR COMMERCIAL AND NON-COMMERCIAL USE
 * as long as the following conditions are aheared to.
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.  If this code is used in a product,
 * Eric Young should be given attribution as the author of the parts used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by Eric Young (eay@mincom.oz.au)
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

static const u_int32_t des_SPtrans[8][64]={
{
/* nibble 0 */
0x00820200L, 0x00020000L, 0x80800000L, 0x80820200L,
0x00800000L, 0x80020200L, 0x80020000L, 0x80800000L,
0x80020200L, 0x00820200L, 0x00820000L, 0x80000200L,
0x80800200L, 0x00800000L, 0x00000000L, 0x80020000L,
0x00020000L, 0x80000000L, 0x00800200L, 0x00020200L,
0x80820200L, 0x00820000L, 0x80000200L, 0x00800200L,
0x80000000L, 0x00000200L, 0x00020200L, 0x80820000L,
0x00000200L, 0x80800200L, 0x80820000L, 0x00000000L,
0x00000000L, 0x80820200L, 0x00800200L, 0x80020000L,
0x00820200L, 0x00020000L, 0x80000200L, 0x00800200L,
0x80820000L, 0x00000200L, 0x00020200L, 0x80800000L,
0x80020200L, 0x80000000L, 0x80800000L, 0x00820000L,
0x80820200L, 0x00020200L, 0x00820000L, 0x80800200L,
0x00800000L, 0x80000200L, 0x80020000L, 0x00000000L,
0x00020000L, 0x00800000L, 0x80800200L, 0x00820200L,
0x80000000L, 0x80820000L, 0x00000200L, 0x80020200L,
},{
/* nibble 1 */
0x10042004L, 0x00000000L, 0x00042000L, 0x10040000L,
0x10000004L, 0x00002004L, 0x10002000L, 0x00042000L,
0x00002000L, 0x10040004L, 0x00000004L, 0x10002000L,
0x00040004L, 0x10042000L, 0x10040000L, 0x00000004L,
0x00040000L, 0x10002004L, 0x10040004L, 0x00002000L,
0x00042004L, 0x10000000L, 0x00000000L, 0x00040004L,
0x10002004L, 0x00042004L, 0x10042000L, 0x10000004L,
0x10000000L, 0x00040000L, 0x00002004L, 0x10042004L,
0x00040004L, 0x10042000L, 0x10002000L, 0x00042004L,
0x10042004L, 0x00040004L, 0x10000004L, 0x00000000L,
0x10000000L, 0x00002004L, 0x00040000L, 0x10040004L,
0x00002000L, 0x10000000L, 0x00042004L, 0x10002004L,
0x10042000L, 0x00002000L, 0x00000000L, 0x10000004L,
0x00000004L, 0x10042004L, 0x00042000L, 0x10040000L,
0x10040004L, 0x00040000L, 0x00002004L, 0x10002000L,
0x10002004L, 0x00000004L, 0x10040000L, 0x00042000L,
},{
/* nibble 2 */
0x41000000L, 0x01010040L, 0x00000040L, 0x41000040L,
0x40010000L, 0x01000000L, 0x41000040L, 0x00010040L,
0x01000040L, 0x00010000L, 0x01010000L, 0x40000000L,
0x41010040L, 0x40000040L, 0x40000000L, 0x41010000L,
0x00000000L, 0x40010000L, 0x01010040L, 0x00000040L,
0x40000040L, 0x41010040L, 0x00010000L, 0x41000000L,
0x41010000L, 0x01000040L, 0x40010040L, 0x01010000L,
0x00010040L, 0x00000000L, 0x01000000L, 0x40010040L,
0x01010040L, 0x00000040L, 0x40000000L, 0x00010000L,
0x40000040L, 0x40010000L, 0x01010000L, 0x41000040L,
0x00000000L, 0x01010040L, 0x00010040L, 0x41010000L,
0x40010000L, 0x01000000L, 0x41010040L, 0x40000000L,
0x40010040L, 0x41000000L, 0x01000000L, 0x41010040L,
0x00010000L, 0x01000040L, 0x41000040L, 0x00010040L,
0x01000040L, 0x00000000L, 0x41010000L, 0x40000040L,
0x41000000L, 0x40010040L, 0x00000040L, 0x01010000L,
},{
/* nibble 3 */
0x00100402L, 0x04000400L, 0x00000002L, 0x04100402L,
0x00000000L, 0x04100000L, 0x04000402L, 0x00100002L,
0x04100400L, 0x04000002L, 0x04000000L, 0x00000402L,
0x04000002L, 0x00100402L, 0x00100000L, 0x04000000L,
0x04100002L, 0x00100400L, 0x00000400L, 0x00000002L,
0x00100400L, 0x04000402L, 0x04100000L, 0x00000400L,
0x00000402L, 0x00000000L, 0x00100002L, 0x04100400L,
0x04000400L, 0x04100002L, 0x04100402L, 0x00100000L,
0x04100002L, 0x00000402L, 0x00100000L, 0x04000002L,
0x00100400L, 0x04000400L, 0x00000002L, 0x04100000L,
0x04000402L, 0x00000000L, 0x00000400L, 0x00100002L,
0x00000000L, 0x04100002L, 0x04100400L, 0x00000400L,
0x04000000L, 0x04100402L, 0x00100402L, 0x00100000L,
0x04100402L, 0x00000002L, 0x04000400L, 0x00100402L,
0x00100002L, 0x00100400L, 0x04100000L, 0x04000402L,
0x00000402L, 0x04000000L, 0x04000002L, 0x04100400L,
},{
/* nibble 4 */
0x02000000L, 0x00004000L, 0x00000100L, 0x02004108L,
0x02004008L, 0x02000100L, 0x00004108L, 0x02004000L,
0x00004000L, 0x00000008L, 0x02000008L, 0x00004100L,
0x02000108L, 0x02004008L, 0x02004100L, 0x00000000L,
0x00004100L, 0x02000000L, 0x00004008L, 0x00000108L,
0x02000100L, 0x00004108L, 0x00000000L, 0x02000008L,
0x00000008L, 0x02000108L, 0x02004108L, 0x00004008L,
0x02004000L, 0x00000100L, 0x00000108L, 0x02004100L,
0x02004100L, 0x02000108L, 0x00004008L, 0x02004000L,
0x00004000L, 0x00000008L, 0x02000008L, 0x02000100L,
0x02000000L, 0x00004100L, 0x02004108L, 0x00000000L,
0x00004108L, 0x02000000L, 0x00000100L, 0x00004008L,
0x02000108L, 0x00000100L, 0x00000000L, 0x02004108L,
0x02004008L, 0x02004100L, 0x00000108L, 0x00004000L,
0x00004100L, 0x02004008L, 0x02000100L, 0x00000108L,
0x00000008L, 0x00004108L, 0x02004000L, 0x02000008L,
},{
/* nibble 5 */
0x20000010L, 0x00080010L, 0x00000000L, 0x20080800L,
0x00080010L, 0x00000800L, 0x20000810L, 0x00080000L,
0x00000810L, 0x20080810L, 0x00080800L, 0x20000000L,
0x20000800L, 0x20000010L, 0x20080000L, 0x00080810L,
0x00080000L, 0x20000810L, 0x20080010L, 0x00000000L,
0x00000800L, 0x00000010L, 0x20080800L, 0x20080010L,
0x20080810L, 0x20080000L, 0x20000000L, 0x00000810L,
0x00000010L, 0x00080800L, 0x00080810L, 0x20000800L,
0x00000810L, 0x20000000L, 0x20000800L, 0x00080810L,
0x20080800L, 0x00080010L, 0x00000000L, 0x20000800L,
0x20000000L, 0x00000800L, 0x20080010L, 0x00080000L,
0x00080010L, 0x20080810L, 0x00080800L, 0x00000010L,
0x20080810L, 0x00080800L, 0x00080000L, 0x20000810L,
0x20000010L, 0x20080000L, 0x00080810L, 0x00000000L,
0x00000800L, 0x20000010L, 0x20000810L, 0x20080800L,
0x20080000L, 0x00000810L, 0x00000010L, 0x20080010L,
},{
/* nibble 6 */
0x00001000L, 0x00000080L, 0x00400080L, 0x00400001L,
0x00401081L, 0x00001001L, 0x00001080L, 0x00000000L,
0x00400000L, 0x00400081L, 0x00000081L, 0x00401000L,
0x00000001L, 0x00401080L, 0x00401000L, 0x00000081L,
0x00400081L, 0x00001000L, 0x00001001L, 0x00401081L,
0x00000000L, 0x00400080L, 0x00400001L, 0x00001080L,
0x00401001L, 0x00001081L, 0x00401080L, 0x00000001L,
0x00001081L, 0x00401001L, 0x00000080L, 0x00400000L,
0x00001081L, 0x00401000L, 0x00401001L, 0x00000081L,
0x00001000L, 0x00000080L, 0x00400000L, 0x00401001L,
0x00400081L, 0x00001081L, 0x00001080L, 0x00000000L,
0x00000080L, 0x00400001L, 0x00000001L, 0x00400080L,
0x00000000L, 0x00400081L, 0x00400080L, 0x00001080L,
0x00000081L, 0x00001000L, 0x00401081L, 0x00400000L,
0x00401080L, 0x00000001L, 0x00001001L, 0x00401081L,
0x00400001L, 0x00401080L, 0x00401000L, 0x00001001L,
},{
/* nibble 7 */
0x08200020L, 0x08208000L, 0x00008020L, 0x00000000L,
0x08008000L, 0x00200020L, 0x08200000L, 0x08208020L,
0x00000020L, 0x08000000L, 0x00208000L, 0x00008020L,
0x00208020L, 0x08008020L, 0x08000020L, 0x08200000L,
0x00008000L, 0x00208020L, 0x00200020L, 0x08008000L,
0x08208020L, 0x08000020L, 0x00000000L, 0x00208000L,
0x08000000L, 0x00200000L, 0x08008020L, 0x08200020L,
0x00200000L, 0x00008000L, 0x08208000L, 0x00000020L,
0x00200000L, 0x00008000L, 0x08000020L, 0x08208020L,
0x00008020L, 0x08000000L, 0x00000000L, 0x00208000L,
0x08200020L, 0x08008020L, 0x08008000L, 0x00200020L,
0x08208000L, 0x00000020L, 0x00200020L, 0x08008000L,
0x08208020L, 0x00200000L, 0x08200000L, 0x08000020L,
0x00208000L, 0x00008020L, 0x08008020L, 0x08200000L,
0x00000020L, 0x08208000L, 0x00208020L, 0x00000000L,
0x08000000L, 0x08200020L, 0x00008000L, 0x00208020L,
}};