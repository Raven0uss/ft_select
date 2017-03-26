/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:05:35 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 12:39:59 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(char const *content)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
		new->content = ft_strdup((char *)content);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
