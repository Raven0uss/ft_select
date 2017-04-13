/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:57:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/13 17:56:26 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int					tc_out(int c)
{
	ft_putchar((char)c);
	return (0);
}

static void			tc_end(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
	tputs(tgetstr("ve", NULL), 1, tc_out);
}

int					ws_init(t_winsize *wsize, unsigned int n)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	//if ((wsize->y = (int)w.ws_col) n)
	//if ((wsize->x = (int)w.ws_row) < 0)
	//	return (0);
	wsize->y = n - 1;
	wsize->x = 0;
	wsize->cx = 0;
	wsize->cy = 0;
	return (1);
}

static int			tc_init(struct termios *term)
{
	char			buff[128];

	if (tgetent(buff, getenv("TERM")) < 1)
		return (0);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	return (1);
}

int					main(int ac, char **av)
{
	struct termios	term;
	t_winsize		wsize;
	t_list			*lst;

	if (ac == 1)
		return (0);
	if (!tc_init(&term) || !ws_init(&wsize, (unsigned int)(ac - 1)))
		return (-1);
	sigft();
	lst = lst_creator(av, ac);
	ft_select(&lst, &term, &wsize);
	tc_end(&term);
	return (0);
}
