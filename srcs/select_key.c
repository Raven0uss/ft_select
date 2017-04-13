/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:01:42 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/13 20:00:14 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_list				*uon_line(int mode, t_list *elem, t_winsize *ws)
{
	if (mode)
	{
		tputs(tgetstr("mr", NULL), 1, tc_out);
		ft_putstr(elem->content);
		tputs(tgetstr("me", NULL), 1, tc_out);
		elem->select = 1;
	}
	else
	{
		elem->select = 0;
		ft_putstr(elem->content);
	}
	tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	return (elem);
}

t_list	*evkey_select(char *buff, t_winsize *ws, t_list **lst, t_list *elem)
{
	if ((int)buff[1] == 0)
	{
		if (!elem->select)
			elem = uon_line(1, elem, ws);
		else
			elem = uon_line(0, elem, ws);
		return (elem);
	}
	return (NULL);
}
