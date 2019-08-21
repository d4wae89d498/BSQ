/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/20 18:03:51 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 22:13:36 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "square.h"

typedef struct	s_map
{
	int			size;
	char		empty;
	char		full;
	char		obstacle;
}				t_map;

int				ft_fill_map(char *map_buffer, t_map *map);

t_square		*find_sq(short **cells, t_map *map);

short			**ft_init_cells(char *map_buffer, t_map *map);

void			free_me(t_map *map, short **cells1, short **cells2);

int				ft_display_map(char *map_buffer, t_map *map);
#endif
