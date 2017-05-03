/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:01:42 by sbelazou          #+#    #+#             */
/*   Updated: 2017/05/03 17:54:29 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	uon_line()
{
  if (((t_data *)keepmem())->elem->select == 0)
	{
		tputs(tgetstr("mr", NULL), 1, tc_out);
		ft_putstr_fd(((t_data *)keepmem())->elem->content,
				((t_data *)keepmem())->fd);
		tputs(tgetstr("me", NULL), 1, tc_out);
		((t_data *)keepmem())->elem->select = 1;
	}
	else
	{
	  ((t_data *)keepmem())->elem->select = 0;
	  ft_putstr_fd(((t_data *)keepmem())->elem->content,
			((t_data *)keepmem())->fd);
	}
  tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
		((t_data *)keepmem())->cy), 1, tc_out);
}

void	evkey_select(char *buff)
{
	if ((int)buff[1] == 0)
		uon_line();
	else
	  return ;
	down();
	cursor(1);
}
