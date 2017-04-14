/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:48:17 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/13 19:22:38 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		aff_tc(char *buff)
{
	ft_putnbr((int)buff[0]);
	ft_putchar(' ');
	ft_putnbr((int)buff[1]);
	ft_putchar(' ');
	ft_putnbr((int)buff[2]);
	ft_putchar('\n');
}

void			init_select(t_list *elem, struct termios *term, t_data *ws)
{
	tputs(tgetstr("cl", NULL), 1, tc_out);
	//tputs(tgetstr("vi", NULL), 1, tc_out);
	tputs(tgetstr("ms", NULL), 1, tc_out);
	ft_aff_lst(elem);
	//tputs(tgetstr("ue", NULL), 1, tc_out);
	tputs(tgetstr("ho", NULL), 1, tc_out);
}

void		ft_select(t_list **lst, struct termios *term, t_data *ws)
{
	t_list	*elem;
	char	*buff;

	buff = ft_strnew(3);
	elem = *lst;
	init_select(elem, term, ws);
	while ((int)buff[0] != 10 && (int)buff[0] != 4)
	{
		ft_bzero((void *)buff, sizeof(buff));
		read(0, buff, 3);
		//aff_tc(buff);
		if ((int)buff[0] == 27)
			if ((elem = evkey_arrow(buff, ws, lst, elem)) == NULL)
				break ;
		if ((int)buff[0] == 32) //Space
			if ((elem = evkey_select(buff, ws, lst, elem)) == NULL)
				break ;
		if ((int)buff[0] == 127) //Backspace
		  ;//if (evkey_delete(buff, ws, lst, elem) == NULL)
		// break;
	}
	free(buff);
}










