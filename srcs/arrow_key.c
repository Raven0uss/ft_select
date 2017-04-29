/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:01:28 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			down()
{
	cursor(0);
	if (((t_data *)keepmem())->cy != ((t_data *)keepmem())->y && ((t_data *)keepmem())->elem->next)
	{
	  ((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
	  ((t_data *)keepmem())->cy++;
	}
	else
	{
	  ((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	  ((t_data *)keepmem())->cy = 0;
       	}
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx, ((t_data *)keepmem())->cy), 1, tc_out);
	cursor(1);
}

void			up()
{
	cursor(0);
	if (((t_data *)keepmem())->cy != 0 && ((t_data *)keepmem())->elem->prev)
	{
	  ((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->prev;
	  ((t_data *)keepmem())->cy--;
	}
	else
	{
	  ((t_data *)keepmem())->elem = ptrto_last(((t_data *)keepmem())->elem);
	  ((t_data *)keepmem())->cy = ((t_data *)keepmem())->y;
	}
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx, ((t_data *)keepmem())->cy), 1, tc_out);
	cursor(1);
}

unsigned char			evkey_arrow(char *buff)
{
	signed char	       	key;

	key = 0;
	if ((signed char)buff[1] && (signed char)buff[2])
	{
		key = (signed char)buff[2];
		if (key == 65 || key == 67)
		  up();
		else if (key == 66 || key == 68)
		  down();
		else if (key == 51 && !evkey_delete())
			return (0);
		else if (key == 70)
		{
		  ((t_data *)keepmem())->cy = ((t_data *)keepmem())->y;
			cursor(0);
			((t_data *)keepmem())->elem = ptrto_last(((t_data *)keepmem())->elem);
			cursor(1);
		}
		else if (key == 72)
		{
		  ((t_data *)keepmem())->cy = 0;
			cursor(0);
			((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
			cursor(1);
		}
		return (1);
	}
	  return (0);
}
