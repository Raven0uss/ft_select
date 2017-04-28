/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:48:17 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 12:46:49 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char	*ret_select(t_list *elem)
{
	int		flag;

	flag = 0;
	elem = ptrto_frst(elem);
	while (elem->next)
    {
		if (elem->select == 1 && ++flag)
		{
			if (flag > 1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(elem->content, 1);
		}
		elem = elem->next;
    }
	if (elem->select == 1 && ++flag)
    {
		if (flag > 1)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(elem->content, 1);
    }
	if (flag)
		ft_putchar_fd('\n', 1);
	return (NULL);
}

void		aff_tc(char *buff)
{
	ft_putnbr((int)buff[0]);
	ft_putchar(' ');
	ft_putnbr((int)buff[1]);
	ft_putchar(' ');
	ft_putnbr((int)buff[2]);
	ft_putchar('\n');
}

void		init_select(t_list *elem, t_data *ws)
{
	tputs(tgetstr("cl", NULL), 1, tc_out);
	tputs(tgetstr("vi", NULL), 1, tc_out);
	tputs(tgetstr("ms", NULL), 1, tc_out);
	ft_aff_lst(elem, ws);
	tputs(tgetstr("ho", NULL), 1, tc_out);
}

void		cursor(t_list *elem, t_data *ws, unsigned char mode)
{
		if (mode)
		{
			tputs(tgetstr("us", NULL), 1, tc_out);
			if (elem->select)
			{
				tputs(tgetstr("mr", NULL), 1, tc_out);
				ft_putstr_fd(elem->content, ws->fd);
				tputs(tgetstr("me", NULL), 1, tc_out);
			}
			else
				ft_putstr_fd(elem->content, ws->fd);
			tputs(tgetstr("ue", NULL), 1, tc_out);
		}
		else
		{
			if (elem->select)
			{
				tputs(tgetstr("mr", NULL), 1, tc_out);
				ft_putstr_fd(elem->content, ws->fd);
				tputs(tgetstr("me", NULL), 1, tc_out);
			}
			else
				ft_putstr_fd(elem->content, ws->fd);
		}
	tputs(tgoto(tgetstr("cm", NULL), 0, ws->cy), 1, tc_out);
}

char		*ft_select(t_list **lst, t_data *ws)
{
	t_list	*elem;
	char	*buff;

	buff = ft_strnew(3);
	elem = *lst;
	init_select(elem, ws);
	cursor(elem, ws, 1);
	while ((int)buff[0] != 10 && (int)buff[0] != 4)
	{
		sigft(ws, elem);
		ft_bzero((void *)buff, sizeof(buff));
		read(0, buff, 3);
		//aff_tc(buff);
		if ((int)buff[0] == 27)
			if ((elem = evkey_arrow(buff, ws, lst, elem)) == NULL)
				break ;
		if ((int)buff[0] == 32) //Space
			if ((elem = evkey_select(buff, ws, lst, elem)) == NULL)
				break ;
		if ((int)buff[0] == 127) //Backspace
		  if ((elem = evkey_delete(ws, lst, elem)) == NULL)
				break ;
		if ((int)buff[0] == 13)
			if (ret_select(elem) == NULL)
				break ;//Enter
	}
	free(buff);
	return (NULL);
}
