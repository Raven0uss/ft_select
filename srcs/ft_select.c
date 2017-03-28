/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:48:17 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/27 12:37:31 by sbelazou         ###   ########.fr       */
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

void		ft_select(t_list **lst, struct termios *term, t_winsize *ws)
{
	t_list	*elem;
	char	*buff;

	buff = ft_strnew(3);
	elem = *lst;
	while ((int)buff[0] != 10 && (int)buff[0] != 4)
	{
		ft_bzero((void *)buff, sizeof(buff));
		read(0, buff, 3);
		aff_tc(buff);
		if ((int)buff[0] == 27)
			if (event_key_arrow(buff, ws, lst, elem) == NULL)
				break ;
		if ((int)buff[0] == 127)
			ft_putendl("BackSpace");
	}
	free(buff);
}
