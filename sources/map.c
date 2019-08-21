/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fdumas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 19:16:26 by fdumas       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 21:58:16 by mfaussur    ###    #+. /#+    ###.fr     */
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
#include "./../includes/map_utils.h"

int			ft_fill_map(char *map_buffer, t_map *map)
{
	int	i;
	int	number_size;
	int	number;

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
	if (map_buffer[i + 3] != '\n')
		return (0);
	map->size = number;
	map->empty = map_buffer[i];
	map->obstacle = map_buffer[i + 1];
	map->full = map_buffer[i + 2];
	map->biggest_index = -1;
	return (1);
}

t_square	*find_sq(short **cells, t_map *map)
{
	t_square	*sq;
	int			i;
	int			j;

	j = 0;
	sq = ft_create_square(0, 0, 0);
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

short		**ft_init_cells(char *map_buffer, t_map *map)
{
	int			i;
	short		**map_cells;
	int			x;
	int			y;

	map_cells = malloc(sizeof(short*) * map->size);
	y = -1;
	while (y < map->size)
		map_cells[y++] = malloc(sizeof(short) * map->size);
	y = 0;
	x = 0;
	i = 0;
	while (map_buffer[++i] != '\n')
		;
	while (map_buffer[++i] && y < map->size)
	{
		if (x > map->size - 1 && ++y)
			x = 0;
		else
			map_cells[y][x++] = map_buffer[i] == map->empty;
	}
	return (map_cells);
}

int			ft_display_map(char *map_buffer, t_map *map)
{
	int			i;
	short		**map_cells;
	short		**map_clone;
	int			j;
	t_square	*out;

	map_cells = ft_init_cells(map_buffer, map);
	map_clone = clone(map_cells, map);
	out = find_sq(map_clone, map);
	printf("largest square was: %i x=%i y=%i \n", out->l, out->x, out->y);
	i = 0;
	while (i < map->size)
	{
		j = -1;
		while (++j < map->size)
			if (i >= out->y && j >= out->x
					&& i <= (out->y + out->l) && j <= (out->x + out->l))
				ft_putchar(map->full);
			else
				ft_putchar(map_cells[i][j] ? map->empty : map->obstacle);
		i += 1;
		write(1, "\n", 1);
	}
	return (1);
}
