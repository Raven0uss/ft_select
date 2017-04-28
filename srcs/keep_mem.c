/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 16:51:15 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:11:19 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				*keepmem(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
		if (!(data = (t_data *)malloc(sizeof(*data))))
			return (NULL);
	return (data);
}
