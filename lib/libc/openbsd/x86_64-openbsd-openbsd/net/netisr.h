/*	$OpenBSD: netisr.h,v 1.51 2019/08/06 22:57:54 bluhm Exp $	*/
/*	$NetBSD: netisr.h,v 1.12 1995/08/12 23:59:24 mycroft Exp $	*/

/*
 * Copyright (c) 1980, 1986, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)netisr.h	8.1 (Berkeley) 6/10/93
 */

#ifndef _NET_NETISR_H_
#define _NET_NETISR_H_

/*
 * Each ``pup-level-1'' input queue has a bit in a ``netisr'' status
 * word which is used to de-multiplex a single software
 * interrupt used for scheduling the network code to calls
 * on the lowest level routine of each protocol.
 */
#define	NETISR_IP	2		/* same as AF_INET */
#define	NETISR_TX	3		/* for if_snd processing */
#define	NETISR_PFSYNC	5		/* for pfsync "immediate" tx */
#define	NETISR_ARP	18		/* same as AF_LINK */
#define	NETISR_IPV6	24		/* same as AF_INET6 */
#define	NETISR_ISDN	26		/* same as AF_E164 */
#define	NETISR_PPP	28		/* for PPP processing */
#define	NETISR_PIPEX	27		/* for pipex processing */
#define	NETISR_BRIDGE	29		/* for bridge processing */
#define	NETISR_PPPOE	30		/* for pppoe processing */
#define	NETISR_SWITCH	31		/* for switch dataplane */

#ifndef _LOCORE
#ifdef _KERNEL

#include <sys/task.h>
#include <sys/atomic.h>

extern int	netisr;			/* scheduling bits for network */
extern struct task if_input_task_locked;

void	arpintr(void);
void	pppintr(void);
void	bridgeintr(void);
void	pppoeintr(void);
void	switchintr(void);
void	pfsyncintr(void);
void	pipexintr(void);

#define	schednetisr(anisr)						\
do {									\
	atomic_setbits_int(&netisr, (1 << (anisr)));			\
	task_add(net_tq(0), &if_input_task_locked);			\
} while (/* CONSTCOND */0)

#endif /* _KERNEL */
#endif /*_LOCORE */

#endif /* _NET_NETISR_H_ */