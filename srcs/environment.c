/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:30:43 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/18 14:38:23 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void				env_init(char **envp)
{
	unsigned int	i;

	i = 0;
	while (envp[i])
		if (ft_strncmp(envp[i], "TERM=", 5))
		{
			envp[i] = "TERM=xterm-256color\0";
			return ;
		}
		else
			i++;
	envp[i] = "TERM=xterm-256color\0";
	envp[i++] = NULL;
}
