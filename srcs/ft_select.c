/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:48:17 by sbelazou          #+#    #+#             */
/*   Updated: 2017/07/04 15:13:32 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		ret_select(void)
{
	signed char	flag;

	flag = 0;
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	while (((t_data *)keepmem())->elem->next)
	{
		if (((t_data *)keepmem())->elem->select == 1)
		{
			if (flag > 0)
				ft_putchar_fd(' ', 1);
			ft_putstr(((t_data *)keepmem())->elem->content);
			flag = 1;
		}
		((t_data *)keepmem())->elem = ((t_data *)keepmem())->elem->next;
	}
	if (((t_data *)keepmem())->elem->select == 1)
	{
		if (flag > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr(((t_data *)keepmem())->elem->content);
		flag = 1;
	}
	if (flag)
		ft_putchar('\n');
}

void			init_select(void)
{
	tputs(tgetstr("cl", NULL), 1, tc_out);
	tputs(tgetstr("vi", NULL), 1, tc_out);
	tputs(tgetstr("ms", NULL), 1, tc_out);
	((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
	ft_aff_lst(((t_data *)keepmem())->elem);
	tputs(tgetstr("ho", NULL), 1, tc_out);
}

static void		cursor_flw(void)
{
	if (((t_data *)keepmem())->elem->select)
	{
		tputs(tgetstr("mr", NULL), 1, tc_out);
		ft_putstr_fd(((t_data *)keepmem())->elem->content,
					((t_data *)keepmem())->fd);
		tputs(tgetstr("me", NULL), 1, tc_out);
	}
	else
		ft_putstr_fd(((t_data *)keepmem())->elem->content,
					((t_data *)keepmem())->fd);
}

void			cursor(unsigned char mode)
{
	if (mode)
	{
		tputs(tgetstr("us", NULL), 1, tc_out);
		if (((t_data *)keepmem())->elem->select)
		{
			tputs(tgetstr("mr", NULL), 1, tc_out);
			ft_putstr_fd(((t_data *)keepmem())->elem->content,
						((t_data *)keepmem())->fd);
			tputs(tgetstr("me", NULL), 1, tc_out);
		}
		else
			ft_putstr_fd(((t_data *)keepmem())->elem->content,
						((t_data *)keepmem())->fd);
		tputs(tgetstr("ue", NULL), 1, tc_out);
	}
	else
		cursor_flw();
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
				((t_data *)keepmem())->cy), 1, tc_out);
}

void			ft_select(void)
{
	char		*buff;

	buff = ft_strnew(3);
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->lst;
	init_select();
	cursor(1);
	while ((int)buff[0] != 13 && (int)buff[0] != 4)
	{
		sigft();
		ft_bzero((void *)buff, sizeof(buff));
		read(0, buff, 3);
		if (((int)buff[0] == 27 && !evkey_arrow(buff))
			|| ((int)buff[0] == 127 && !evkey_delete(0)))
			break ;
		if ((int)buff[0] == 32)
			evkey_select(buff);
		if ((int)buff[0] == 102)
			evkey_finder();
		if ((int)buff[0] == 10)
		{
			ret_select();
			break ;
		}
	}
	free(buff);
}
