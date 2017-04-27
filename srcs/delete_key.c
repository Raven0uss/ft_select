/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/27 11:26:43 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list		*refresh_man(t_data *ws, t_list **lst, t_list *elem, char **av)
{
	int		size;

	size = ft_sizetab(av);
	ft_lstdel(lst, ft_freestr);
	*lst = lst_creator(av, size);
	while (--size)
		free(av[size]);
	free(av[size]);
	free(av);
	ws->cy = 0;
	elem = *lst;
	init_select(elem, ws);
	elem = ptrto_frst(elem);
	return (elem);
}

void		freetab(char **av, int size)
{
	while (--size)
		free(av[size]);
	free(av[size]);
	free(av);
}

//Proteger si il y a 0 select OU supprimer le curseur uniquement si 0 select
t_list		*evkey_delete(t_data *ws, t_list **lst, t_list *elem)
{
	char		**av;
	unsigned int	i;
	unsigned int	flag;

	i = 0;
	flag = 0;
	elem = ptrto_frst(elem);
	if (!(av = malloc(sizeof(char *) * (ws->y + 2))))
		return (NULL);
	av[i++] = ft_strdup("ft_select");
	while (elem->next)
    {
		if (elem->select == 1)
		{
			flag++;
			ws->y--;
		}
		else
			av[i++] = ft_strdup(elem->content);
		elem = elem->next;
    }
	if (elem->select == 1)
	{
		flag++;
		ws->y--;
	}
	else
		av[i++] = ft_strdup(elem->content);
	av[i] = NULL;
	if (!flag)
	{
		elem = ptrto_frst(elem);
		freetab(av, ft_sizetab(av));
		ws->cy = 0;
		init_select(elem, ws);
		cursor(elem, ws, 1);
		return (elem);
	}
	if (i == 1)
		return (NULL);
	elem = refresh_man(ws, lst, elem, av);
	cursor(elem, ws, 1);
	return (elem);
}
