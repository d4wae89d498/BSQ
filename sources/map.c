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
	return (c == map->empty || c  == map->obstacle);
}

int		ft_case(char c, t_map *map)
{
	if (!ft_is_case(c, map))
		return (-1);
	else
		return (c == map->empty);
}

int		reccursive_sqr_findr(short **cells, int begin_x, int begin_y, int x, int y, t_map *map, int deep, int mvt)
{
	int	rec_res;

	if (deep >= map->size || x >= map->size || x - begin_x >= deep || y - begin_y >= deep  ||  y >= map->size || y < 0 || x < 0 || !cells[y][x])
		return (0);
	else if (mvt == 0)
	{
		rec_res = reccursive_sqr_findr(cells, begin_x, begin_y, x + 1, y,  map, deep, 0);
		if (rec_res)
			return (1 + rec_res);
		else
		{
			rec_res = reccursive_sqr_findr(cells, begin_x, begin_y, x, y - 1, map, deep, 1);
			if (rec_res)
				return (rec_res + 1);
		}
	}
	else if (mvt == 1) 
	{
		rec_res = reccursive_sqr_findr(cells, begin_x, begin_y, x, y + 1,  map, deep, 1);
		if (rec_res)
			return (1 + rec_res);
		else
		{
			rec_res = reccursive_sqr_findr(cells, begin_x, begin_y, x - 1, y, map, deep, 2);
			if (rec_res)
				return (1  +  rec_res);
		}
	}
	else if (mvt == 2) 
	{
		rec_res = reccursive_sqr_findr(cells, begin_x, begin_y, x - 1, y,  map, deep, 2);
		if (rec_res)
			return (1 + rec_res);
		else
		{
			rec_res = reccursive_sqr_findr(cells, begin_x, begin_y, begin_x, begin_y,  map, deep + 1, 0);
			return (rec_res + 1);
		}
	}
	return (0);
}

int		ft_display_map(char *map_buffer, t_map *map)
{
	int	i;	
	int	c;
	short	**map_cells;
	//short	map_cells[map->size][map->size];
	int	x;
	int	y;
	map_cells = malloc(sizeof(short*) * map->size);
	y = 0;
	while ( y < map->size)
		map_cells[y++] = malloc(sizeof(short) * map->size);
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
		while(map_buffer[++i] != '\n')
			;
		while (map_buffer[++i] && y < map->size)
		{
			if ((x >  map->size - 1))
			{
				x = 0;
				y += 1;
			}
			else 
			{	
				map_cells[y][x] = ft_case(map_buffer[i], map);
				x += 1;
			}
		}
	}
	
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			printf("%i\n", reccursive_sqr_findr(map_cells, x, y, x, y, map, 1, 0) / 3);
			x += 1;
		}
		printf("\n");
		y += 1;
	}
	return (1);
}
