/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/05/03 18:21:17 by sbelazou         ###   ########.fr       */
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

unsigned char		evkey_delete(void)
{
	unsigned int	flag;

	flag = 0;
	((t_data *)keepmem())->cur = ((t_data *)keepmem())->elem;
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	while (((t_data *)keepmem())->elem->next)
		if (((t_data *)keepmem())->elem->select == 1 && ++flag)
		{
			if ((((t_data *)keepmem())->elem =\
				relinker(((t_data *)keepmem())->elem)) == NULL)
				return (0);
			((t_data *)keepmem())->y--;
		}
		else
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
	if (((t_data *)keepmem())->elem->select == 1 && ++flag)
		if ((((t_data *)keepmem())->elem = relinker(((t_data *)keepmem())->elem)) == NULL || --((t_data *)keepmem())->y == -1)
			return (0);
	if (!flag && ((((t_data *)keepmem())->cur =\
			relinker(((t_data *)keepmem())->cur)) == NULL || --((t_data *)keepmem())->y == -1))
		return (0);
	((t_data *)keepmem())->cy = 0;
	init_select();
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	cursor(1);
	return (1);
}
