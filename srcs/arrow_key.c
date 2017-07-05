/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/05 11:44:53 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		move_to_col2(unsigned char dir, int nb)
{
	if (dir == 2)
	{
		nb = ((t_data *)keepmem())->wy - 2;
		while (nb >= 0 && ((t_data *)keepmem())->elem->next)
		{
			nb--;
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
		}
	}
	else if (dir == 3)
	{
		nb = (((t_data *)keepmem())->wy - 2);
		while (nb >= 0 && ((t_data *)keepmem())->elem->prev)
		{
			nb--;
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->prev;
		}
	}
}

void			move_to_col(unsigned char dir)
{
	int			nb;

	nb = ((t_data *)keepmem())->cy;
	if (dir == 0)
	{
		((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
		while (nb != 0 && ((t_data *)keepmem())->elem->next)
		{
			nb--;
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
		}
	}
	else if (dir == 1)
	{
		nb = (((t_data *)keepmem())->ylast - 1) - ((t_data *)keepmem())->cy - 1;
		((t_data *)keepmem())->elem = ptrto_last(((t_data *)keepmem())->elem);
		while (nb >= 0 && ((t_data *)keepmem())->elem->prev)
		{
			nb--;
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->prev;
		}
	}
	move_to_col2(dir, nb);
}

unsigned char	evkey_arrow(char *buff)
{
	signed char	key;

	if ((signed char)buff[1] && (signed char)buff[2])
	{
		key = (signed char)buff[2];
		key == 65 ? up() : (void)key;
		key == 66 ? down() : (void)key;
		key == 67 ? down() : (void)key;
		key == 68 ? up() : (void)key;
		if (key == 51 && !evkey_delete(0))
			return (0);
		else
			home_end(key);
		return (1);
	}
	return (0);
}
