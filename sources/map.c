/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c	                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:37:14 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 20:23:23 by hmarlin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./../includes/map.h"
#include "./../includes/square.h"
#include "./../includes/stdio.h"
#include "./../includes/string.h"

int	ft_fill_map(char *map_buffer, t_map *map)
{
	int	exit_code;
	int	i;
	int	number_size;
	int	number;

	exit_code = 0;
	number_size = 0;
	number = 0;
	i = 0;
	while (map_buffer[i] && ft_is_number(map_buffer[i]))
	{
		number += map_buffer[i] - '0';
		if (ft_is_number(map_buffer[i + 1]))
			number *= 10;
		number_size += 1;
		i += 1;
	}
	if (number_size == 0)
		return (0);
	if(map_buffer[i + 3] != '\n')
		return (0);
	map->size = number;
	map->empty = map_buffer[i];
	map->obstacle = map_buffer[i + 1];
	map->full = map_buffer[i + 2];
	map->biggest_index = -1;
	return (1);
}

int		ft_is_case(char c, t_map *map)
{
	return (c == map->empty ||c  == map->obstacle);
}

int		ft_case(char c, t_map *map)
{
	if (!ft_is_case(c, map))
		return (-1);
	else
		return (c == map->empty);
}

int		reccursive_sqr_findr(short **cells, int begin_x, int begin_y, int x, int y, t_map *map)
{
	char	c;
	int	size;

	size = 0;
	if (x >= map->size || y >= map->size || y < 0 || x < 0)
		return (size);
	else
	{
		c = cells[y][x];
		if (c < 1)
		{
			// can we go right ?

			// can we got bottom ?

			// can we go left ?
			return (size);
		}
		else 
		{
			return (++size + reccursive_sqr_findr(cells, begin_x, begin_y, x, y,  map));
		}
	}
}

int		ft_display_map(char *map_buffer, t_map *map)
{
	int	i;	
	int	c;
	short	map_cells[map->size][map->size];
	int	x;
	int	y;

	y = 0;
	x = 0;
	i = 0;
	if (!map_buffer)
	{
		return (0);
	} 
	else if (!map_buffer[i + 1])
	{
		c = ft_case(map_buffer[i], map);
		if (c == -1)
			return (0);
		else
			map_cells[y][x] = c;
			
	}
	else
	{
		while (map_buffer[i])
		{
			if ((x == map->size - 1) && map_buffer[i] == '\n')
			{
				x = 0;
				y += 1;
			}
			else if (x > map->size)
			 	return (0);
			else 
			{	
				c = ft_case(map_buffer[i], map);
				if (c >= 0)
					map_cells[y][x++] = c;
				else
					return (1);
			}
		}
	}
	return (0);
}
