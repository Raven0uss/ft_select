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
	struct termios	*term;
}					t_data;

void				sigft();
t_list				*lst_creator(char **av, int ac);
void				ft_aff_lst(t_list *lst, t_data *ws);
char				*ft_select(t_data *ws);
t_list				*evkey_arrow(char *buff, t_data *ws, t_list *elem);
t_list				*evkey_select(char *buff, t_data *ws, t_list *elem);
int					tc_out(int c);
t_list				*ptrto_frst(t_list *elem);
t_list				*ptrto_last(t_list *elem);
t_list				*evkey_delete(t_data *ws, t_list *elem);
void				init_select(t_list *elem, t_data *ws);
t_list				*down(t_data *ws, t_list *elem);
t_list				*up(t_data *ws, t_list *elem);
void				cursor(t_list *elem, t_data *ws, unsigned char mode);
void				env_init(char **envp);
void				*keepmem(void);

#endif



















