/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:07:15 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 11:52:03 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(char*))
{
	if (del && alst)
	{
		while (*alst)
		{
			if ((*alst)->content)
				(del)((*alst)->content);
			free(*alst);
			(*alst) = (*alst)->next;
		}
		*alst = NULL;
	}
}
