/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:57:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:41:23 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// ====
// == Partie Obligatoire ==
// ==== [ToDo] ====
// [??]| Environnement vide (Pour le moment aucun comportement...)
// ====
// == Partie Bonus ==
// ====
// 1 [OK]- HOME et END, Debut et fin de liste
// 2 [OK]- Selection + suppression multiple
// 3 [KO]- Navigation gauche droite lorsque terminal trop petit
// 4 [KO]- Interface
// 5 [KO]- Recherche Dynamique
// ====
// ==== [ft_select - 99% - 40% ] ====
// Notes :
// 
// ====

int					tc_out(int c)
{
	int				fd;

	if ((fd = open("/dev/tty", O_RDWR)) == -1)
	{
		ft_putendl_fd("Error: Can't open /dev/tty.", 2);
		exit(-1);
	}
	ft_putchar_fd((char)c, fd);
	close(fd);
	return (1);
}

void			tc_end(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("cl", NULL), 1, tc_out);
	tputs(tgetstr("ve", NULL), 1, tc_out);
}

unsigned char					ws_init(unsigned int n)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	((t_data *)keepmem())->y = n - 1;
	((t_data *)keepmem())->wx = (unsigned int)w.ws_col;
	((t_data *)keepmem())->wy = (unsigned int)w.ws_row;
	((t_data *)keepmem())->cx = 0;
	((t_data *)keepmem())->cy = 0;
	return (1);
}

unsigned char			tc_init(struct termios *term)
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
	char			*ret;

	if (ac == 1)
		return (0);
	if (!tc_init(&term) || !ws_init((unsigned int)(ac - 1)))
		return (-1);
	((t_data *)keepmem())->term = &term;
	((t_data *)keepmem())->lst = lst_creator(av, ac);
	if ((((t_data *)keepmem())->fd = open("/dev/tty", O_RDWR)) == -1)
		return (-1);
	ft_select();
	close(((t_data *)keepmem)->fd);
	tc_end(&term);
	return (0);
}
