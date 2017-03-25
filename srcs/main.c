/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:57:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/17 14:02:11 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			tc_out(int c)
{
  ft_putchar((char)c);
  return (0);
}

static void		tc_end(struct termios *term)
{
  term->c_lflag |= ICANON;
  term->c_lflag |= ECHO;
  tcsetattr(0, 0, term);
  tputs(tgetstr("me", NULL), 1, tc_out);
  tputs(tgetstr("cl", NULL), 1, tc_out);
  tputs(tgetstr("ve", NULL), 1, tc_out);
}

static int		tc_init(struct termios *term)
{
  char			buff[128];
  
  if (tgetent(buff, getenv("TERM")) < 1)
    return (0);
  tcgetattr(0, term);
  term->c_lflag &= ~(ICANON);
  term->c_lflag &= ~(ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  tcsetattr(0, 0, term);
  return (1);
}

int			main(int ac, char **av)
{
  struct termios	term;

  if (!tc_init(&term))
    return (-1);
  tc_end(&term);
  return (0);
}
