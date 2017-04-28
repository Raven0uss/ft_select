/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:39:14 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:40:25 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void			sigrwft(int sig)
{
	(void)sig;
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
}

static void			sigfgft(int sig)
{
	(void)sig;
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
}

static void			sigzft(int sig)
{
	char			z[2];

	(void)sig;
	if (isatty(1))
	{
		z[0] = ((t_data *)keepmem())->term->c_cc[VSUSP];
		z[1] = 0;
		tputs(tgetstr("te", NULL), 1, tc_out);
		tputs(tgetstr("me", NULL), 1, tc_out);
		tputs(tgetstr("cl", NULL), 1, tc_out);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, z);
	}
}

static void			sigcft(int sig)
{
	(void)sig;
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
}

void				sigft()
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
