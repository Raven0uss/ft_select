/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 11:16:11 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		right_continue(void)
{
	if (((t_data *)keepmem())->cx == ((t_data *)keepmem())->lencol *\
		((t_data *)keepmem())->nb_col)
	{
		((t_data *)keepmem())->cx = 0;
		((t_data *)keepmem())->cy++;
		if (((t_data *)keepmem())->cy == ((t_data *)keepmem())->ylast - 1)
		{
			((t_data *)keepmem())->elem =\
				ptrto_frst(((t_data *)keepmem())->elem);
			((t_data *)keepmem())->cy = 0;
		}
		else
			move_to_col(0);
	}
	else
	{
		((t_data *)keepmem())->cx += ((t_data *)keepmem())->lencol;
		move_to_col(2);
	}
}

int			left_begin(void)
{
	if (((t_data *)keepmem())->cy > ((t_data *)keepmem())->ylast - 1)
	{
		up();
		return (1);
	}
	else if (((t_data *)keepmem())->cy == 0)
	{
		((t_data *)keepmem())->elem = ptrto_last(((t_data *)keepmem())->elem);
		((t_data *)keepmem())->cy = ((t_data *)keepmem())->ylast - 1;
		((t_data *)keepmem())->cx = ((t_data *)keepmem())->lencol\
			* ((t_data *)keepmem())->nb_col;
	}
	else
	{
		((t_data *)keepmem())->cx = ((t_data *)keepmem())->lencol *\
			((t_data *)keepmem())->nb_col;
		((t_data *)keepmem())->cy--;
		move_to_col(1);
	}
	return (0);
}

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
