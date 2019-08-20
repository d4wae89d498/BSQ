/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:03:51 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 20:19:28 by hmarlin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "square.h"

typedef struct	s_map
{
	int			l;
	char		empty;
	char		full;
	char		biggest_square;

	t_square	**squares;
}				t_map;

t_map			*ft_fill_map(char *map_buffer);
t_square		*ft_find_biggest_square(t_map *map);
void			ft_display_map(t_map	*map, t_square *biggest_square);

#endif
