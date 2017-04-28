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

static t_list	*right(t_data *ws, t_list *elem)
{
	if (ws->cx != ws->x)
	{
		ws->cx++;
		tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	}
	return (elem);
}

static t_list	*left(t_data *ws, t_list *elem)
{
	if (ws->cx != 0)
	{
		ws->cx--;
		tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	}
	return (elem);
}

t_list			*down(t_data *ws, t_list *elem)
{
	cursor(elem, ws, 0);
	if (ws->cy != ws->y && elem->next)
	{
		elem = elem->next;
		ws->cy++;
	}
	else
	{
		elem = ptrto_frst(elem);
		ws->cy = 0;
       	}
	tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	cursor(elem, ws, 1);
	return (elem);
}

t_list			*up(t_data *ws, t_list *elem)
{
	cursor(elem, ws, 0);
	if (ws->cy != 0 && elem->prev)
	{
		elem = elem->prev;
		ws->cy--;
	}
	else
	{
		elem = ptrto_last(elem);
		ws->cy = ws->y;
	}
	tputs(tgoto(tgetstr("cm", NULL), ws->cx, ws->cy), 1, tc_out);
	cursor(elem, ws, 1);
	return (elem);
}

t_list			*evkey_arrow(char *buff, t_data *ws, t_list *elem)
{
	int			key;

	key = 0;
	if ((int)buff[1] == 0)
		return (NULL);
	else if ((int)buff[1] == 91 && (int)buff[2])
	{
		key = (int)buff[2];
		if (key == 65 || key == 67)
			elem = up(ws, elem);
		else if (key == 66 || key == 68)
			elem = down(ws, elem);
		else if (key == 51 && (elem = evkey_delete(ws, elem)) == NULL)
			return (NULL);
		else if (key == 70)
		{
			ws->cy = ws->y;
			cursor(elem, ws, 0);
			elem = ptrto_last(elem);
			cursor(elem, ws, 1);
		}
		else if (key == 72)
		{
			ws->cy = 0;
			cursor(elem, ws, 0);
			elem = ptrto_frst(elem);
			cursor(elem, ws, 1);
		}
		else
			return (elem);
		return (elem);
	}
	return (NULL);
}
