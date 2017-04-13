/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:16:53 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/12 19:25:21 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <curses.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "libft/libft.h"

typedef struct	s_winsize
{
	int			x;
	int			y;
	int			cx;
	int			cy;
}				t_winsize;

void			sigft();
t_list			*lst_creator(char **av, int ac);
void			ft_aff_lst(t_list *lst);
void			ft_select(t_list **lst, struct termios *term, t_winsize *ws);
t_list			*evkey_arrow(char *buff, t_winsize *ws,
								t_list **lst, t_list *elem);
t_list			*evkey_select(char *buff, t_winsize *ws,
								  t_list **lst, t_list *elem);
int				tc_out(int c);

#endif
