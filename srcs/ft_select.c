/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:48:17 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:39:51 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	ret_select()
{
	signed char		flag;

	flag = 0;
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	while (((t_data *)keepmem())->elem->next)
    {
      if (((t_data *)keepmem())->elem->select == 1 && ++flag)
		{
			if (flag > 1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(((t_data *)keepmem())->elem->content, 1);
		}
      ((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
    }
	if (((t_data *)keepmem())->elem->select == 1 && ++flag)
    {
		if (flag > 1)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(((t_data *)keepmem())->elem->content, 1);
    }
	if (flag)
		ft_putchar_fd('\n', 1);
}

void		aff_tc(char *buff)
{
	ft_putnbr((int)buff[0]);
	ft_putchar(' ');
	ft_putnbr((int)buff[1]);
	ft_putchar(' ');
	ft_putnbr((int)buff[2]);
	ft_putchar('\n');
}

void		init_select()
{
	tputs(tgetstr("cl", NULL), 1, tc_out);
	tputs(tgetstr("vi", NULL), 1, tc_out);
	tputs(tgetstr("ms", NULL), 1, tc_out);
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	ft_aff_lst(((t_data *)keepmem())->elem);
	tputs(tgetstr("ho", NULL), 1, tc_out);
}

void		cursor(unsigned char mode)
{
		if (mode)
		{
			tputs(tgetstr("us", NULL), 1, tc_out);
			if (((t_data *)keepmem())->elem->select)
			{
				tputs(tgetstr("mr", NULL), 1, tc_out);
				ft_putstr_fd(((t_data *)keepmem())->elem->content, ((t_data *)keepmem())->fd);
				tputs(tgetstr("me", NULL), 1, tc_out);
			}
			else
			  ft_putstr_fd(((t_data *)keepmem())->elem->content, ((t_data *)keepmem())->fd);
			tputs(tgetstr("ue", NULL), 1, tc_out);
		}
		else
		{
		  if (((t_data *)keepmem())->elem->select)
			{
				tputs(tgetstr("mr", NULL), 1, tc_out);
				ft_putstr_fd(((t_data *)keepmem())->elem->content, ((t_data *)keepmem())->fd);
				tputs(tgetstr("me", NULL), 1, tc_out);
			}
			else
			  ft_putstr_fd(((t_data *)keepmem())->elem->content, ((t_data *)keepmem())->fd);
		}
		tputs(tgoto(tgetstr("cm", NULL), 0, ((t_data *)keepmem())->cy), 1, tc_out);
}

void		ft_select()
{
	char	*buff;

	buff = ft_strnew(3);
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->lst;
	init_select();
	cursor(1);
	while ((int)buff[0] != 10 && (int)buff[0] != 4)
	{
		sigft();
		ft_bzero((void *)buff, sizeof(buff));
		read(0, buff, 3);
		//aff_tc(buff);
		if ((int)buff[0] == 27 && !evkey_arrow(buff))
				break ;
		if ((int)buff[0] == 32)
		  evkey_select(buff);
		if ((int)buff[0] == 127 && !evkey_delete())
				break ;
		if ((int)buff[0] == 13)
		  {
			ret_select();
			break ;
		  }
	}
	free(buff);
}
