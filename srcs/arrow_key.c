/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/13 20:54:21 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_list	*right(t_data *ws, t_list **lst, t_list *elem)
{
	if (ws->cx != ws->x)
	{
		ws->cx++;
		tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	}
	return (elem);
}

static t_list	*left(t_data *ws, t_list **lst, t_list *elem)
{
	if (ws->cx != 0)
	{
		ws->cx--;
		tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	}
	return (elem);
}

static t_list	*down(t_data *ws, t_list **lst, t_list *elem)
{
	if (ws->cy != ws->y)
	{
		elem = elem->next;
		ws->cy++;
	}
	/*else
	{
		ws->cy = 0;
		}*/
	tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	return (elem);
}

static t_list	*up(t_data *ws, t_list **lst, t_list *elem)
{
	if (ws->cy != 0)
	{
		elem = elem->prev;
		ws->cy--;
	}
	/*else
	{
		ws->cy = ws->y;
		}*/
	tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	return (elem);
}

t_list				*evkey_arrow(char *buff, t_data *ws,
								t_list **lst, t_list *elem)
{
	int	key;

	key = 0;
	if ((int)buff[1] == 0)
		return (NULL);
	else if ((int)buff[1] == 91 && (int)buff[2])
	{
		key = (int)buff[2];
		if (key == 65)
			elem = up(ws, lst, elem);
		else if (key == 66)
			elem = down(ws, lst, elem);
		/*else if (key == 67)
			elem = right(ws, lst, elem);
		else if (key == 68)
		elem = left(ws, lst, elem);*/
		else if (key == 51)
			;//ft_putendl("Delete");
		else
			return (elem);
		return (elem);
	}
	return (NULL);
}
