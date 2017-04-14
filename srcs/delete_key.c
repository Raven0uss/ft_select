* ************************************************************************** */
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
  elem = ptrto_frst;
  while (elem->next)
    {
      if (elem->select == 1)
	{
	  elem = ft_lstdelone(lst, elem);
	}
      else
	elem = elem->next;
    }
  if (elem->select == 1)
    elem = ft_lstdelone(lst, elem);
  elem = ptrto_frst(elem);  
  return (elem);
}
