/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 11:20:35 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/13 20:20:17 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				ft_aff_lst(t_list *lst)
{
	t_list			*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
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
