/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:06:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 11:53:38 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 		*ft_lstdelone(t_list *elem)
{
  t_list	*previous;
  t_list	*nextone;

  if (elem->prev != NULL)
      previous = elem->prev;
  else
    previous = NULL;
  if (elem->next != NULL)
      nextone = elem->next;
  else
    nextone = NULL;
  free(elem->content);
  free(elem);
  previous->next = nextone;
  nextone->prev = previous;
  if (previous != NULL)
    return (previous);
  else
    return (nextone);
}
