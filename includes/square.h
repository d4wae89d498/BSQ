/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   square.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:00:01 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 18:34:44 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

typedef struct	s_square
{
	int		x; 		// position colone du caree 
	int		y;		// position ligne du caree
	int		l;		// longuerre / largeure du caree
}				t_square;

t_square	*ft_create_square(int x, int y, int l);

#endif
