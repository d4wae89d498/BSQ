/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   square.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:00:01 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 20:13:57 by hmarlin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

typedef struct	s_square
{
	int			x;
	int			y;
	int			l;
}				t_square;

t_square		*ft_create_square(int x, int y, int l);

#endif
