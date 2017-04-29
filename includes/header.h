/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:16:53 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:41:30 by sbelazou         ###   ########.fr       */
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
	int				x;
	int				y;
	int				cx;
	int				cy;
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
void				env_init(char **envp);
void				*keepmem(void);
void				tc_end(struct termios *term);
unsigned char				tc_init(struct termios *term);
unsigned char				ws_init(unsigned int n);

#endif



















