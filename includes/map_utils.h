/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_utils.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 21:50:41 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 21:57:40 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H
# include "map.h"

int		ft_is_case(char c, t_map *map);

int		ft_case(char c, t_map *map);

short	**clone(short **cells, t_map *map);

short	min(short a, short b, short c);
#endif
