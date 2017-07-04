/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:16:53 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 14:58:48 by sbelazou         ###   ########.fr       */
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
	int				y;
	int				cx;
	int				cy;
	t_list			*tmp;
	t_list			*cur;
	t_list			*elem;
	t_list			*lst;
	int				wx;
	int				wy;
	int				nb_col;
	int				ylast;
	int				lencol;
	int				kx;
	int				ky;
	t_list			*prev;
	t_list			*next;
	t_list			*to_del;
	struct termios	*term;
}					t_data;

void				sigft(void);
t_list				*lst_creator(char **av, int ac);
void				ft_aff_lst(t_list *lst);
void				ft_select(void);
unsigned char		evkey_arrow(char *buff);
void				evkey_select(char *buff);
int					tc_out(int c);
t_list				*ptrto_frst(t_list *elem);
t_list				*ptrto_last(t_list *elem);
unsigned char		evkey_delete(unsigned int flag);
void				init_select(void);
void				down(void);
void				up(void);
void				cursor(unsigned char mode);
void				*keepmem(void);
void				tc_end(struct termios *term);
unsigned char		tc_init(struct termios *term);
unsigned char		ws_init(unsigned int n);
void				fill_lencol(void);
void				evkey_finder(void);
void				right_continue(void);
int					left_begin(void);
void				home_end(signed char key);
void				move_to_col(unsigned char dir);

#endif
