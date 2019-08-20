/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   square.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ffaivre <ffaivre@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:55:26 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 20:21:54 by hmarlin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/square.h"
#include <stdlib.h>

t_square	*ft_create_square(int x, int y, int l)
{
	t_square *pointeur;

	pointeur = malloc(sizeof(t_square));
	pointeur->x = x;
	pointeur->y = y;
	pointeur->l = l;
	return (pointeur);
}
