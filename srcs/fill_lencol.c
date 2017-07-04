/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lencol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 11:25:04 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 11:40:39 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		fill_lencol(void)
{
	t_list	*tmp;

	((t_data *)keepmem())->lencol = 0;
	tmp = ((t_data *)keepmem())->lst;
	tmp = ptrto_frst(tmp);
	while (tmp->next)
	{
		if (((t_data *)keepmem())->lencol <
			(int)ft_strlen(tmp->content))
			((t_data *)keepmem())->lencol =\
				(int)ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	if (tmp->content && ((t_data *)keepmem())->lencol <
		(int)ft_strlen(tmp->content))
		((t_data *)keepmem())->lencol = (int)ft_strlen(tmp->content);
	((t_data *)keepmem())->lencol += 2;
}
