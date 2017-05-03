/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:16:53 by sbelazou          #+#    #+#             */
/*   Updated: 2017/05/03 17:32:27 by sbelazou         ###   ########.fr       */
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

typedef struct		s_data
{
	int				fd;
	unsigned int				wx;
	unsigned int				wy;
	int				y;
	int				cx;
	int				cy;
  unsigned int		nb_col;
  unsigned int		ylast;
	unsigned int		lencol;
	unsigned int	kx;
	unsigned int	ky;
	t_list *tmp;
	t_list			*cur;
	t_list			*lst;
	 t_list			*elem;
  struct termios	*term;
}					t_data;

void				sigft();
t_list				*lst_creator(char **av, int ac);
void				ft_aff_lst(t_list *lst);
void				ft_select();
unsigned char			evkey_arrow(char *buff);
void				evkey_select(char *buff);
int					tc_out(int c);
t_list				*ptrto_frst(t_list *elem);
t_list				*ptrto_last(t_list *elem);
unsigned char			evkey_delete();
void				init_select();
void				down();
void				up();
void				cursor(unsigned char mode);
void				*keepmem(void);
void				tc_end(struct termios *term);
unsigned char				tc_init(struct termios *term);
unsigned char				ws_init(unsigned int n);
void				fill_lencol();
void				evkey_finder(char *buff);

#endif



















