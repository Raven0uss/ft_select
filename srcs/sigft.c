/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:39:14 by sbelazou          #+#    #+#             */
/*   Updated: 2017/05/03 18:09:12 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void			sigrwft(int sig)
{
	(void)sig;
	tputs(tgetstr("cl", NULL), 1, tc_out);
	ws_init((unsigned int)((t_data *)keepmem())->y + 1);
	init_select();
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	cursor(1);
}

static void			sigfgft(int sig)
{
	(void)sig;
	tc_init(((t_data *)keepmem())->term);
	ws_init((unsigned int)(((t_data *)keepmem())->y + 1));
	init_select();
	cursor(1);
}

static void			sigzft(int sig)
{
	char			z[2];

	(void)sig;
	if (isatty(1))
	{
		z[0] = ((t_data *)keepmem())->term->c_cc[VSUSP];
		z[1] = 0;
		tputs(tgetstr("cl", NULL), 1, tc_out);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, z);
		tc_end(((t_data *)keepmem())->term);
	}
}

static void			sigcft(int sig)
{
	(void)sig;
	tc_end(((t_data *)keepmem())->term);
	exit(0);
}

void				sigft(void)
{
	void			*sigrw;
	void			*sigfg;
	void			*sigz;
	void			*sigc;

	sigrw = &sigrwft;
	sigfg = &sigfgft;
	sigz = &sigzft;
	sigc = &sigcft;
	signal(SIGWINCH, sigrw);
	signal(SIGTSTP, sigz);
	signal(SIGCONT, sigfg);
	signal(SIGINT, sigcft);
	signal(SIGQUIT, sigcft);
}
