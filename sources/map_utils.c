/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 21:52:18 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 21:57:47 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "./../includes/map.h"

int			ft_is_case(char c, t_map *map)
{
	return (c == map->empty || c == map->obstacle);
}

int			ft_case(char c, t_map *map)
{
	if (!ft_is_case(c, map))
		return (-1);
	else
		return (c == map->empty);
}

short		**clone(short **cells, t_map *map)
{
	short		**cells_out;
	int			i;
	int			j;

	i = 0;
	cells_out = malloc(map->size * sizeof(short*));
	while (i < map->size)
	{
		cells_out[i] = malloc(map->size * sizeof(short));
		j = 0;
		while (j < map->size)
		{
			cells_out[i][j] = cells[i][j];
			j += 1;
		}
		i += 1;
	}
	return (cells_out);
}

short		min(short a, short b, short c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}
