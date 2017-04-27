/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:39:14 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/27 19:44:57 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	sigrwft(int x)
{
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
	(void)x;
}

static void	sigfgft(int x)
{
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
	(void)x;
}

static void	sigzft(int x)
{
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
	(void)x;
}

void		sigft(t_data *ws, t_list *elem)
{
	void	*sigrw;
	void	*sigfg;
	void	*sigz;

	sigrw = &sigrwft;
	sigfg = &sigfgft;
	sigz = &sigzft;
	signal(SIGWINCH, sigrw);//resize
	signal(SIGTSTP, sigz);//Ctrl-z
	signal(SIGCONT, sigfg); //fg
}
