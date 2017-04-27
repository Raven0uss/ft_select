/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 11:20:35 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/27 16:16:52 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list				*ptrto_frst(t_list *elem)
{
  while (elem->prev != NULL)
    elem = elem->prev;
  return (elem);
}

t_list				*ptrto_last(t_list *elem)
{
  while (elem->next != NULL)
    elem = elem->next;
  return (elem);
}

void				ft_aff_lst(t_list *lst, t_data *ws)
{
	t_list			*tmp;

	tmp = lst;
	tmp = ptrto_frst(tmp);
	while (tmp->next != NULL)
	{
		if (tmp->content != NULL)
			ft_putendl(tmp->content);
		tmp = tmp->next;
	}
	if (tmp->content != NULL)
		ft_putendl(tmp->content);
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