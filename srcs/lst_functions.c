/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 11:20:35 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 14:37:43 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list				*ptrto_frst(t_list *elem)
{
	while (elem != NULL && elem->prev != NULL)
		elem = elem->prev;
	return (elem);
}

t_list				*ptrto_last(t_list *elem)
{
	while (elem != NULL && elem->next != NULL)
		elem = elem->next;
	return (elem);
}

static t_list		*aff_continue(t_list *tmp, unsigned int padd)
{
	while (tmp->next != NULL)
	{
		if ((int)((t_data *)keepmem())->cy ==
			((t_data *)keepmem())->wy - 1)
		{
			((t_data *)keepmem())->cy = 0;
			padd += ((t_data *)keepmem())->lencol;
			((t_data *)keepmem())->nb_col++;
		}
		if (tmp->content != NULL)
		{
			if (tmp->select)
				tputs(tgetstr("mr", NULL), 1, tc_out);
			ft_putendl_fd(tmp->content, ((t_data *)keepmem())->fd);
			if (tmp->select)
				tputs(tgetstr("me", NULL), 1, tc_out);
		}
		tputs(tgoto(tgetstr("cm", NULL), padd,
					((t_data *)keepmem())->cy), 1, tc_out);
		((t_data *)keepmem())->cy++;
		tmp = tmp->next;
	}
	return (tmp);
}

void				ft_aff_lst(t_list *lst)
{
	t_list			*tmp;

	tmp = lst;
	tmp = ptrto_frst(tmp);
	fill_lencol();
	((t_data *)keepmem())->cy = 1;
	((t_data *)keepmem())->nb_col = 0;
	tmp = aff_continue(tmp, 0);
	if (tmp->content != NULL)
	{
		if (tmp->select)
			tputs(tgetstr("mr", NULL), 1, tc_out);
		ft_putendl_fd(tmp->content, ((t_data *)keepmem())->fd);
		if (tmp->select)
			tputs(tgetstr("me", NULL), 1, tc_out);
	}
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	((t_data *)keepmem())->ylast = ((t_data *)keepmem())->cy;
	((t_data *)keepmem())->cy = 0;
}

t_list				*lst_creator(char **av, int ac)
{
	t_list			*new;
	unsigned int	i;

	i = 1;
	if (ac == 1)
		return (new = ft_lstnew(NULL));
	new = ft_lstnew(av[i++]);
	while (av[i])
		ft_lstadd(&new, ft_lstnew(av[i++]), 1);
	return (new);
}
