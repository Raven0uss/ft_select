/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:13:19 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/28 17:01:28 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		evkey_finder(char *buff)
{
  t_list	*tmp;
  int		kx;
  int		ky;
  char		*str;

  kx =  ((t_data *)keepmem())->cx;
  ky =  ((t_data *)keepmem())->cy;
  tmp =  ((t_data *)keepmem())->elem;
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, tc_out);
  ft_aff_lst(((t_data *)keepmem())->elem);
  tputs(tgoto(tgetstr("cm", NULL), 0, ((t_data *)keepmem())->wy), 1, tc_out);
  tputs(tgetstr("mr", NULL), 1, tc_out);
  ft_putstr_fd("ft_select|Search :", ((t_data *)keepmem())->fd);
  tputs(tgetstr("me", NULL), 1, tc_out);
  tputs(tgetstr("ve", NULL), 1, tc_out);
  ft_putchar_fd(' ', ((t_data *)keepmem())->fd);
  ((t_data *)keepmem())->term->c_lflag |= ICANON;
  ((t_data *)keepmem())->term->c_lflag |= ECHO;
  tcsetattr(0, 0, ((t_data *)keepmem())->term);
  get_next_line(((t_data *)keepmem())->fd, &str) == -1 ? exit(-1) : (void)str;
  tc_init(((t_data *)keepmem())->term);
  tputs(tgetstr("cl", NULL), 1, tc_out);
  ft_aff_lst(((t_data *)keepmem())->elem);
  tputs(tgetstr("vi", NULL), 1, tc_out);
  ((t_data *)keepmem())->cx = kx;
  ((t_data *)keepmem())->cy = ky;
  ((t_data *)keepmem())->elem = tmp;
  tputs(tgoto(tgetstr("cm", NULL), ((t_data *)keepmem())->cx, ((t_data *)keepmem())->cy), 1, tc_out);
  cursor(1);
  free(str);
}
