/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/05/03 18:17:12 by sbelazou         ###   ########.fr       */
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
		if (((t_data *)keepmem())->cx ==
			((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col)
		{
			((t_data *)keepmem())->elem =\
				ptrto_frst(((t_data *)keepmem())->elem);
			((t_data *)keepmem())->cx = 0;
			((t_data *)keepmem())->cy = 0;
		}
		else
		{
			((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
			((t_data *)keepmem())->cy = 0;
			((t_data *)keepmem())->cx += ((t_data *)keepmem())->lencol;
		}
	}
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
				((t_data *)keepmem())->cy), 1, tc_out);
	cursor(1);
}

static void			move_to_col(unsigned char dir)
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
  else if (dir == 2)
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

static void			left(void)
{
  cursor(0);
  if (((t_data *)keepmem())->cx == 0)
    {
      if (((t_data *)keepmem())->cy > ((t_data *)keepmem())->ylast - 1)
	{
	  up();
	  return ;
	}
      else if (((t_data *)keepmem())->cy == 0)
	{
	  ((t_data *)keepmem())->elem = ptrto_last(((t_data *)keepmem())->elem);
	  ((t_data *)keepmem())->cy = ((t_data *)keepmem())->ylast - 1;
	  ((t_data *)keepmem())->cx = ((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col;
	  }
      else
	{
	  ((t_data *)keepmem())->cx = ((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col;
	  ((t_data *)keepmem())->cy--;
	  move_to_col(1);
	}
    }
  else
    {
      ((t_data *)keepmem())->cx -= ((t_data *)keepmem())->lencol;
      move_to_col(3);
    }
  tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
	      ((t_data *)keepmem())->cy), 1, tc_out);
  cursor(1);
}

static void			right(void)
{
  cursor(0);
  if (((t_data *)keepmem())->cx == ((t_data *)keepmem())->lencol * (((t_data *)keepmem())->nb_col - 1))
    {
      if (((t_data *)keepmem())->cy > ((t_data *)keepmem())->ylast - 1)
	{
	  down();
	  return ;
	}
      else
	{
	  ((t_data *)keepmem())->cx += ((t_data *)keepmem())->lencol;
	  move_to_col(2);
	}
    }
  else if (((t_data *)keepmem())->cx == ((t_data *)keepmem())->lencol * ((t_data *)keepmem())->nb_col)
    {
      if (((t_data *)keepmem())->cy == ((t_data *)keepmem())->ylast - 1)
	{
	  ((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	  ((t_data *)keepmem())->cy = 0;
	  ((t_data *)keepmem())->cx = 0;
	}
      else
      {
      ((t_data *)keepmem())->cx = 0;
      ((t_data *)keepmem())->cy++;
      move_to_col(0);
      }
    }
  else
    {
      ((t_data *)keepmem())->cx += ((t_data *)keepmem())->lencol;
      move_to_col(2);
    }
  tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
	      ((t_data *)keepmem())->cy), 1, tc_out);
  cursor(1);
}

void			up(void)
{
	cursor(0);
	if (((t_data *)keepmem())->cy != 0 && ((t_data *)keepmem())->elem->prev)
	{
		((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->prev;
		((t_data *)keepmem())->cy--;
	}
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

unsigned char	evkey_arrow(char *buff)
{
	signed char	key;

	if ((signed char)buff[1] && (signed char)buff[2])
	{
		key = (signed char)buff[2];
		key == 65 ? up() : (void)key;
		key == 66 ? down() : (void)key;
		key == 67 ? right() : (void)key;
		key == 68 ? left() : (void)key;
		if (key == 51 && !evkey_delete())
			return (0);
		else if (key == 70)
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
		return (1);
	}
	return (0);
}
