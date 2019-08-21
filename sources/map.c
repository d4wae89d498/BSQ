/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fdumas <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 19:16:26 by fdumas       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:24:12 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
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
	int	y;

	number_size = 0;
	number = 0;
	map->side = 0;
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
	y = i + 3;
	while (map_buffer[++y] != '\n')
		map->side += 1;
	printf("\n");
	map->size = number;
	map->empty = map_buffer[i];
	map->obstacle = map_buffer[i + 1];
	map->full = map_buffer[i + 2];
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

void		init_me(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
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
	init_me(&i, &y, &x);
	while (map_buffer[++i] != '\n')
		;
	while (map_buffer[++i] && y < map->size)
	{
		if (x > map->side - 1 && ++y)
			if (map_buffer[i] != '\n')
				return (0);
			else
				x = 0;
		else if (map_buffer[i] != map->empty && map_buffer[i] != map->obstacle)
			return (0);
		else
			map_cells[y][x++] = map_buffer[i] == map->empty;
	}
	return (map_cells);
}

void		free_me(t_map *map, short **cells1, short **cells2)
{
	int		i;

	i = 0;
	while (i < map->size)
		free(cells1[i++]);
	free(cells1);
	i = 0;
	while (i < map->size)
		free(cells2[i++]);
	free(cells2);
}

int			ft_display_map(char *map_buffer, t_map *map)
{
	int			i;
	short		**map_cells;
	short		**map_clone;
	int			j;
	t_square	*out;

	map_cells = ft_init_cells(map_buffer, map);
	if (!map_cells)
		return (0);
	map_clone = clone(map_cells, map);
	out = find_sq(map_clone, map);
	i = -1;
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->side)
			if (i >= out->y && j >= out->x
					&& i <= (out->y + out->l) && j <= (out->x + out->l))
				ft_putchar(map->full);
			else
				ft_putchar(map_cells[i][j] ? map->empty : map->obstacle);
		write(1, "\n", 1);
	}
	free_me(map, map_cells, map_clone);
	return (1);
}
