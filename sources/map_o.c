/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_o.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 23:36:56 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:40:14 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/map.h"
#include "./../includes/map_utils.h"
#include "./../includes/string.h"

void		set_map(t_map *map, char c, char d, char e)
{
	map->empty = c;
	map->obstacle = d;
	map->full = e;
}

int			ft_fill_map(char *map_buffer, t_map *map)
{
	int	i;
	int	number_size;
	int	number;
	int	y;

	number_size = 0;
	number = 0;
	map->side = 0;
	i = -1;
	while (map_buffer[++i] && ft_is_number(map_buffer[i]))
	{
		number += map_buffer[i] - '0';
		if (ft_is_number(map_buffer[i + 1]))
			number *= 10;
		number_size += 1;
	}
	if (number_size == 0 || map_buffer[i + 3] != '\n')
		return (0);
	y = i + 3;
	while (map_buffer[++y] != '\n')
		map->side += 1;
	set_map(map, map_buffer[i], map_buffer[i + 1], map_buffer[i + 2]);
	map->size = number;
	return (1);
}
