/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 11:20:35 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 12:26:02 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_list				*ptrto_frst(t_list *elem)
{
  while (elem->prev != NULL)
    elem = elem->prev;
  return (elem);
}

t_list				*ptrto_last(t_list *elem)
{
  while (elem->next != NULL)
    elem = elem->next;
  return (elem);
}

void				fill_lencol()
{
  t_list		*tmp;

  ((t_data *)keepmem())->lencol = 0;
  tmp = ((t_data *)keepmem())->lst;
  tmp = ptrto_frst(tmp);
  while (tmp->next)
    {
      if (((t_data *)keepmem())->lencol < (unsigned int)ft_strlen(tmp->content))
	((t_data *)keepmem())->lencol = (unsigned int)ft_strlen(tmp->content);
      tmp = tmp->next;
    }
  if (tmp->content && ((t_data *)keepmem())->lencol < (unsigned int)ft_strlen(tmp->content))
    ((t_data *)keepmem())->lencol = (unsigned int)ft_strlen(tmp->content);
  ((t_data *)keepmem())->lencol += 2;
}

void				ft_aff_lst(t_list *lst)
{
  t_list			*tmp;
  unsigned int			padd;
  
  tmp = lst;
  tmp = ptrto_frst(tmp);
  fill_lencol();
  padd = 0;
  ((t_data *)keepmem())->cy = 1;
  ((t_data *)keepmem())->nb_col = 0;
  while (tmp->next != NULL)
    {
      if ((unsigned int)((t_data *)keepmem())->cy == ((t_data *)keepmem())->wy - 1)
	{
	  ((t_data *)keepmem())->cy = 0;
	  padd += ((t_data *)keepmem())->lencol;
	  ((t_data *)keepmem())->nb_col++;
	}
      if (tmp->content != NULL)
	{
	  if (tmp->select)
	    tputs(tgetstr("mr", NULL), 1, tc_out);
	  ft_putendl_fd(tmp->content, ((t_data *)keepmem())->fd);
	  if (tmp->select)
	    tputs(tgetstr("me", NULL), 1, tc_out);
	}
      tputs(tgoto(tgetstr("cm", NULL), padd, ((t_data *)keepmem())->cy), 1, tc_out);
      ((t_data *)keepmem())->cy++;
      tmp = tmp->next;
    }
  if (tmp->content != NULL)
    {
      if (tmp->select)
	tputs(tgetstr("mr", NULL), 1, tc_out);
      ft_putendl_fd(tmp->content, ((t_data *)keepmem())->fd);
      if (tmp->select)
	tputs(tgetstr("me", NULL), 1, tc_out);
    }
  ((t_data *)keepmem())->elem = ptrto_frst(((t_data *)keepmem())->elem);
  ((t_data *)keepmem())->ylast = ((t_data *)keepmem())->cy;
  ((t_data *)keepmem())->cy = 0;
}

t_list				*lst_creator(char **av, int ac)
{
	t_list			*new;
	unsigned int	i;

	i = 1;
	if (ac == 1)
		return (new = ft_lstnew(NULL));
	new = ft_lstnew(av[i++]);
	while (av[i])
		ft_lstadd(&new, ft_lstnew(av[i++]), 1);
	return (new);
}
