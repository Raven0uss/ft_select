/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:57:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/27 17:50:48 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// ====
// == Partie Obligatoire ==
// ==== [ToDo] ====
// [KO] Environnement vide
// [KO] Signaux (Redimension, Ctrl-z + fg)
// [KO] Renvoyer correctement le retour-selection
// ====
// == Partie Bonus ==
// ====
// 1 [OK]- HOME et END, Debut et fin de liste
// 2 [OK]- Selection + suppression multiple
// 3 [KO]- Navigation gauche droite lorsque terminal trop petit
// 4 [KO]- Belle Interface
// 5 [KO]-
// ====
// ==== [ft_select - 85 % ] ====
// ====

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

int					ws_init(t_data *wsize, unsigned int n)
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

int					main(int ac, char **av, char **envp)
{
	struct termios	term;
	t_data			wsize;
	t_list			*lst;
	char			*ret;

	if (ac == 1)
		return (-1);
	env_init(envp);
	if (!tc_init(&term) || !ws_init(&wsize, (unsigned int)(ac - 1)))
		return (-1);
	sigft();
	lst = lst_creator(av, ac);
	wsize.term = &term;
	wsize.fd = 1;
	if ((wsize.fd = open("/dev/tty", O_RDWR)) == -1)
		return (-1);
	if ((ret = ft_select(&lst, &wsize)))
	{
		ft_putstr_fd(ret, 1);
		ft_putchar('\n');
		free(ret);
	}
	close(wsize.fd);
	tc_end(&term);
	return (0);
}
