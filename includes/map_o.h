/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_o.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 23:38:01 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 23:38:57 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_O_H
# define MAP_O_H
# include "map.h"

void		set_map(t_map *map, char c, char d, char e);

int			ft_fill_map(char *map_buffer, t_map *map);

#endif
