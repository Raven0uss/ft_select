/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:02:56 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list				*relinker(t_list *elem)
{
	t_list			*prev;
	t_list			*next;

	prev = elem->prev;
	next = elem->next;
	free(elem->content);
	free(elem);
	if (next == NULL)
	{
		if (prev == NULL)
			return (NULL);
		prev->next = NULL;
		elem = prev;
		return (elem);
	}
	else if (prev == NULL)
	{
		next->prev = NULL;
		elem = next;
		return (elem);
	}
	next->prev = prev;
	prev->next = next;
	elem = next;
	return (elem);
}

t_list				*evkey_delete(t_data *ws, t_list *elem)
{
	unsigned int	flag;

	flag = 0;
	ws->cur = elem;
	elem = ptrto_frst(elem);
	while (elem->next)
		if (elem->select == 1 && ++flag)
		{
			if ((elem = relinker(elem)) == NULL)
				return (NULL);
			ws->y--;
		}
		else
			elem = elem->next;
	if (elem->select == 1 && ++flag)
		if ((elem = relinker(elem)) == NULL || --ws->y == -1)
			return (NULL);
	if (!flag && ((ws->cur = relinker(ws->cur)) == NULL || --ws->y == -1))
		return (NULL);
	ws->cy = 0;
	init_select(elem, ws);
	elem = ptrto_frst(elem);
	cursor(elem, ws, 1);
	return (elem);
}
