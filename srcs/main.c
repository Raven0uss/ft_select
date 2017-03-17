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

/*
On appelle la fonction tgetstr qui va remplis un char * avec les différentes
instructions à réaliser pour réaliser notre demande. Ici il s'agit de "cl".

if ((str = tgetstr("cl", NULL)) == NULL)
	return (-1);

On utilise tputs pour réaliser les instructions contenues dans notre char *res.
Cette fonction prend en dernier paramètre un pointeur sur fonction.
On doit donc lui donner le nom d'une fonction prototypé ainsi :
int my_outc(int c). et qui contiendra pour tout code : ft_putchar(c);

tputs(res, 0, my_outc);

res = xtgetstr("cm", &area);

On utilise la fonction tgoto, qui va retourner une série d'instructions
afin de déplacer le curseur jusqu'à l'endroit voulu.

tputs(tgoto(res, pos_x, pos_y), 1, my_outc);
On a placé le curseur à la position (x, y).
Si nous voulons juste déplacer le curseur d’un vers la droite,
il faudrait connaitre la position originale du curseur et ajouter 1 a pos_x.
Il existe une autre façon de faire, plus simple, qui ne nécessite pas de connaitre
la position du curseur : on utilise « nd » avec tgetstr.
*/

static int			display()
{
	char			buff[3];
	unsigned int	flag;

	flag = 1;
	while (flag)
	{
		read(0, buff, 3);
		if (buff[0] == 27) // Case 0 == c'est une fleche
			ft_putendl("It's an arrow input.");
		else if (buff[0] == 4) //Ctrl + D
			flag--;
	}
	ft_putendl("Exiting with Ctrl-D");
	return (0);
}

int					main(int ac, char **av, char **envp)
{
	char			*name;
	struct termios	term;

	ft_putendl("Loading termcaps...");
	if (!(name = getenv("TERM")))
	{
		ft_putendl("Error with getenv.");
		return (-1);
	}
	if (!(tgetent(NULL, (const char *)name)))
	{
		ft_putendl("Error with tgetent.");
		return (-1);
	}
	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl("Error with tcgetattr.");
		return (-1);
	}
	term.c_lflag &= ~(ICANON); //Terminal mode canonique - interactif
	// Le terminal reagit des qu'une touche est enfoncee, sans ENTER
	ft_putendl("Canonic mode is OK.");
	term.c_lflag &= ~(ECHO); // Handler touche active
	ft_putendl("Handler mode is OK.");
	term.c_cc[VMIN] = 1; // 1 touche
	term.c_cc[VTIME] = 0; //VTIME retour de read delai n = 0
	if (tcsetattr(0, TCSADRAIN, &term) == -1) // Applique les change;ent sur fd 0
	{
		//TCSADRAIN change occurs after all output written to fd has been transmitted
		//TCSANOW change now
		ft_putendl("Error with tcsetattr.");
		return (-1);
	}
	ft_putendl("Termcaps init is OK.");
	display();
	return (0);
}
