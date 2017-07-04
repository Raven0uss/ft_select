/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 15:17:55 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char			*relinker(void)
{
	((t_data *)keepmem())->prev = ((t_data *)keepmem())->elem->prev;
	((t_data *)keepmem())->next = ((t_data *)keepmem())->elem->next;
	if (((t_data *)keepmem())->next == NULL)
	{
		if (((t_data *)keepmem())->prev == NULL)
			return (NULL);
		((t_data *)keepmem())->prev->next = NULL;
		free(((t_data *)keepmem())->elem->content);
		free(((t_data *)keepmem())->elem);
		((t_data *)keepmem())->elem = ((t_data *)keepmem())->prev;
		return ("SUCCESS");
	}
	else if (((t_data *)keepmem())->prev == NULL)
	{
		((t_data *)keepmem())->next->prev = NULL;
		((t_data *)keepmem())->elem = ((t_data *)keepmem())->next;
		return ("SUCCESS");
	}
	((t_data *)keepmem())->next->prev = ((t_data *)keepmem())->prev;
	((t_data *)keepmem())->prev->next = ((t_data *)keepmem())->next;
	free(((t_data *)keepmem())->elem->content);
	free(((t_data *)keepmem())->elem);
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->next;
	return ("SUCCESS");
}

static char			*relinker_cur(void)
{
	((t_data *)keepmem())->prev = ((t_data *)keepmem())->cur->prev;
	((t_data *)keepmem())->next = ((t_data *)keepmem())->cur->next;
	if (((t_data *)keepmem())->next == NULL)
	{
		if (((t_data *)keepmem())->prev == NULL)
			return (NULL);
		((t_data *)keepmem())->prev->next = NULL;
		free(((t_data *)keepmem())->cur->content);
		free(((t_data *)keepmem())->cur);
		((t_data *)keepmem())->cur = ((t_data *)keepmem())->prev;
		return ("SUCCESS");
	}
	else if (((t_data *)keepmem())->prev == NULL)
	{
		((t_data *)keepmem())->next->prev = NULL;
		((t_data *)keepmem())->cur = ((t_data *)keepmem())->next;
		return ("SUCCESS");
	}
	((t_data *)keepmem())->next->prev = ((t_data *)keepmem())->prev;
	((t_data *)keepmem())->prev->next = ((t_data *)keepmem())->next;
	free(((t_data *)keepmem())->cur->content);
	free(((t_data *)keepmem())->cur);
	((t_data *)keepmem())->cur = ((t_data *)keepmem())->next;
	return ("SUCCESS");
}

unsigned char		evkey_delete(unsigned int flag)
{
	((t_data *)keepmem())->cur = ((t_data *)keepmem())->elem;
	if (((t_data *)keepmem())->elem != NULL)
		((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	while (((t_data *)keepmem())->elem->next)
		if (((t_data *)keepmem())->elem->select == 1 && ++flag)
		{
			if (relinker() == NULL)
				return (0);
			((t_data *)keepmem())->y--;
		}
		else
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
	if (((t_data *)keepmem())->elem->select == 1 && ++flag)
		if (relinker() == NULL || --((t_data *)keepmem())->y == -1)
			return (0);
	if (!flag && (relinker_cur() == NULL || --((t_data *)keepmem())->y == -1))
		return (0);
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->cur;
	((t_data *)keepmem())->cy = 0;
	init_select();
	if (((t_data *)keepmem())->elem != NULL)
		((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	cursor(1);
	return (1);
}
