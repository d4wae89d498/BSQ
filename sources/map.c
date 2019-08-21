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

short		**clone(short **cells, t_map *map)
{
	short 	**cells_out;
	int	i;
	int	j;

	i = 0;
	cells_out = malloc(map->size * sizeof(short*));
	while (i < map->size)
	{
		cells_out[i] = malloc(map->size * sizeof(short));
		j = 0;
		while (j < map->size)
		{
			cells_out[i][j]= cells[i][j];
			j += 1;
		}
		i += 1;
	}
	return cells_out;
}

short		min(short a, short b, short c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	return c;
}

t_square 	*find_sq(short **cells, t_map *map)
{

	t_square	*sq;
	int		i;
	int		j;

	j = 0;
	sq = ft_create_square(0,0,0);;
	while (j < map->size)
	{
		i = -1;
		while (cells[j][++i] != 0)
		{
			if (i == 0 || j == 0)
				continue ;
			else if (cells[j][i] != 0)
			{
				cells[j][i] = 1 + min(cells[j][i - 1],
						cells[j - 1][i], cells[j - 1][i - 1]);
				if (cells[j][i] > sq->l)
					sq = ft_create_square(i, j, cells[j][i]);
			}
		}
		j++;
	}
	return (sq);
}

int		ft_display_map(char *map_buffer, t_map *map)
{
	int		i;	
	int		c;
	short		**map_cells;
	short		**map_clone;
	t_square	*out;
	int		x;
	int		y;

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
				map_cells[y][x] = map_buffer[i] == map->empty;
				x += 1;
			}
		}
	}
	map_clone = clone(map_cells, map);
	out = find_sq(map_clone, map);
	printf("largest square was: %i x=%i y=%i \n", out->l, out->x, out->y);

	i = 0;
	int j;
	while (i < map->size)
	{
		j = -1;
		while (++j < map->size)
			if (i >= out->y && j >= out->x && i <= (out->y + out->l) && j <= (out->x + out->l))
				ft_putchar(map->full);
			else
				ft_putchar(map_cells[i][j] ? map->empty : map->obstacle);
		i += 1;
		write(1, "\n", 1);
	}
	return (1);
}
