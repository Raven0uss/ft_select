/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/05/03 18:24:46 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	read_find(const int fd, char **str)
{
	char	*buff;
	int		ret;

	ret = 0;
	if (!(buff = malloc(sizeof(char) * 255)))
		return (-1);
	if ((ret = read(((t_data *)keepmem())->fd, buff, 255)) < 0)
		return (-1);
	if (ret != 0)
		buff[ret - 1] = 0;
	*str = buff;
	return (0);
}

static void	finder(char *str)
{
	while (((t_data *)keepmem())->elem->next)
	{
		down();
		if (ft_strstr(((t_data *)keepmem())->elem->content, str) != NULL)
		{
			((t_data *)keepmem())->ky = ((t_data *)keepmem())->cy;
			((t_data *)keepmem())->kx = ((t_data *)keepmem())->cx;
			((t_data *)keepmem())->tmp = ((t_data *)keepmem())->elem;
			return ;
		}
	}
	((t_data *)keepmem())->cy = ((t_data *)keepmem())->ky;
	((t_data *)keepmem())->cx = ((t_data *)keepmem())->kx;
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->tmp;
	while (((t_data *)keepmem())->elem->prev)
	{
		up();
		if (ft_strstr(((t_data *)keepmem())->elem->content, str) != NULL)
		{
			((t_data *)keepmem())->ky = ((t_data *)keepmem())->cy;
			((t_data *)keepmem())->kx = ((t_data *)keepmem())->cx;
			((t_data *)keepmem())->tmp = ((t_data *)keepmem())->elem;
			return ;
		}
	}
}

static void	load_finder(void)
{
	char	*str;

	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, tc_out);
	ft_aff_lst(((t_data *)keepmem())->elem);
	tputs(tgoto(tgetstr("cm", NULL), 0, ((t_data *)keepmem())->wy), 1, tc_out);
	tputs(tgetstr("mr", NULL), 1, tc_out);
	ft_putstr_fd("ft_select|Search :", ((t_data *)keepmem())->fd);
	tputs(tgetstr("me", NULL), 1, tc_out);
	tputs(tgetstr("ve", NULL), 1, tc_out);
	ft_putchar_fd(' ', ((t_data *)keepmem())->fd);
	tcgetattr(0, ((t_data *)keepmem())->term);
	((t_data *)keepmem())->term->c_lflag |= ICANON;
	((t_data *)keepmem())->term->c_lflag |= ECHO;
	tcsetattr(0, 0, ((t_data *)keepmem())->term);
	if (read_find(((t_data *)keepmem())->fd, &str) == -1)
	  return ;
	((t_data *)keepmem())->cy = ((t_data *)keepmem())->ky;
	((t_data *)keepmem())->cx = ((t_data *)keepmem())->kx;
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->tmp;
	if (str[0])
		finder(str);
	free(str);
}

void		evkey_finder(char *buff)
{
	((t_data *)keepmem())->kx = ((t_data *)keepmem())->cx;
	((t_data *)keepmem())->ky = ((t_data *)keepmem())->cy;
	((t_data *)keepmem())->tmp = ((t_data *)keepmem())->elem;
	load_finder();
	tc_init(((t_data *)keepmem())->term);
	tputs(tgetstr("cl", NULL), 1, tc_out);
	ft_aff_lst(((t_data *)keepmem())->elem);
	tputs(tgetstr("vi", NULL), 1, tc_out);
	((t_data *)keepmem())->cx = ((t_data *)keepmem())->kx;
	((t_data *)keepmem())->cy = ((t_data *)keepmem())->ky;
	((t_data *)keepmem())->elem = ((t_data *)keepmem())->tmp;
	tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx,
				((t_data *)keepmem())->cy), 1, tc_out);
	cursor(1);
}
