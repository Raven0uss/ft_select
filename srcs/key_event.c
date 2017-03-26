/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 15:39:35 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_list	*right(t_winsize *ws, t_list **lst, t_list *elem)
{
	ft_putendl(">");
	return (elem);
}

static t_list	*left(t_winsize *ws, t_list **lst, t_list *elem)
{
	ft_putendl("<");
	return (elem);
}

static t_list	*down(t_winsize *ws, t_list **lst, t_list *elem)
{
	ft_putendl("v");
	return (elem);
}

static t_list	*up(t_winsize *ws, t_list **lst, t_list *elem)
{
	ft_putendl("^");
	return (elem);
}

t_list				*event_key_arrow(char *buff, t_winsize *ws,
								t_list **lst, t_list *elem)
{
	int	key;

	key = 0;
	if ((int)buff[1] == 0)
		return (NULL);
	else if ((int)buff[1] == 91 && (int)buff[2])
	{
		key = (int)buff[2];
		if (key == 65)
			elem = up(ws, lst, elem);
		else if (key == 66)
			elem = down(ws, lst, elem);
		else if (key == 67)
			elem = right(ws, lst, elem);
		else if (key == 68)
			elem = left(ws, lst, elem);
		else
			return (NULL);
		return (elem);
	}
	return (NULL);
}
