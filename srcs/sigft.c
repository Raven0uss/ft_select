/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:39:14 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/26 10:54:15 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	sigwft()
{
	char	sig[2];

	sig[0] = -62; //to_precise
	sig[1] = 0;
	ioctl(0, TIOCSTI, sig);
}

static void	sigcft()
{
	char	sig[2];

	sig[0] = -62; //to_precise
	sig[1] = 0;
	ioctl(0, TIOCSTI, sig);
	sig[0] = 10; //to_precise
	ioctl(0, TIOCSTI, sig);
}

void		sigft()
{
	void	*sigw;
	void	*sigc;

	sigw = &sigwft;
	sigc = &sigcft;
	signal(SIGWINCH, sigw);
	signal(SIGCONT, sigc);
}
