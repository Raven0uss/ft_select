/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_lb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/05 11:43:37 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		home_end(signed char key)
{
	if (key == 70)
	{
		((t_data *)keepmem())->cy = ((t_data *)keepmem())->ylast - 1;
		((t_data *)keepmem())->cx =\
			((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col;
		cursor(0);
		((t_data *)keepmem())->elem =\
			ptrto_last(((t_data *)keepmem())->elem);
		cursor(1);
	}
	else if (key == 72)
	{
		((t_data *)keepmem())->cy = 0;
		((t_data *)keepmem())->cx = 0;
		cursor(0);
		((t_data *)keepmem())->elem =\
			ptrto_frst(((t_data *)keepmem())->elem);
		cursor(1);
	}
}
