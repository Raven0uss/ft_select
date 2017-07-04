/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 12:06:35 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			down(void)
{
	cursor(0);
	if (((t_data *)keepmem())->cy != (((t_data *)keepmem())->wy - 2) &&
		((t_data *)keepmem())->elem->next)
	{
		((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
		((t_data *)keepmem())->cy++;
	}
	else
	{
		((t_data *)keepmem())->cy = 0;
		((t_data *)keepmem())->cx += ((t_data *)keepmem())->lencol;
		if (((t_data *)keepmem())->cx - ((t_data *)keepmem())->lencol ==
			((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col)
		{
			((t_data *)keepmem())->elem =\
				ptrto_frst(((t_data *)keepmem())->elem);
			((t_data *)keepmem())->cx = 0;
		}
		else
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
	}
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
				((t_data *)keepmem())->cy), 1, tc_out);
	cursor(1);
}

void			up(void)
{
	cursor(0);
	if (((t_data *)keepmem())->cy != 0 && ((t_data *)keepmem())->elem->prev &&
		--((t_data *)keepmem())->cy != -42)
		((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->prev;
	else
	{
		if (((t_data *)keepmem())->cx == 0)
		{
			((t_data *)keepmem())->elem =\
				ptrto_last(((t_data *)keepmem())->elem);
			((t_data *)keepmem())->cx =\
				((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col;
			((t_data *)keepmem())->cy = ((t_data *)keepmem())->ylast - 1;
		}
		else
		{
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->prev;
			((t_data *)keepmem())->cx -= ((t_data *)keepmem())->lencol;
			((t_data *)keepmem())->cy = ((t_data *)keepmem())->wy - 2;
		}
	}
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
				((t_data *)keepmem())->cy), 1, tc_out);
	cursor(1);
}
