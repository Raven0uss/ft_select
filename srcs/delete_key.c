/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 11:53:38 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list		*evkey_delete(t_data *ws, t_list **lst, t_list *elem)
{
  int		nb;

  nb = 0;
  elem = ptrto_frst(elem);
  while (elem->next)
    {
      if (elem->select == 1)
	{
	  nb++;
	  elem = ft_lstdelone(elem);
	}
      else
	elem = elem->next;
    }
  if (elem->select == 1)
    elem = ft_lstdelone(elem);
  elem = ptrto_frst(elem);
  ws->y -= nb;
  ws->cy = 0;
  init_select(elem, ws);
  return (elem);
}
