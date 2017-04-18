/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:39:14 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/18 18:45:25 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	sigwft(int x)
{
	(void)x;
}

static void	sigcft(int x)
{
	(void)x;
}

void		sigft(t_data *ws, t_list *elem)
{
	void	*sigw;
	void	*sigc;

	sigw = &sigwft;
	sigc = &sigcft;
	signal(SIGWINCH, sigw);
	signal(SIGCONT, sigc);
	//tputs
}
