/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 11:53:38 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(char*))
{
	if (del && alst)
	{
		if (*alst)
		{
			if ((*alst)->content)
				(del)((*alst)->content);
			free(*alst);
		}
		*alst = NULL;
	}
}
