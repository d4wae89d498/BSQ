/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 13:25:24 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 16:15:30 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./../includes/string.h"
#include "./../includes/stdio.h"

char	*g_default_map = "./maps/00.txt";

int		parse_map(char *map_path)
{
	char	*map_file_buffer;

	map_file_buffer = ft_read_file(map_path);
	if (map_file_buffer > 0)
	{
		ft_putstr(map_file_buffer);
		free(map_file_buffer);
		return (0);
	}
	else
	{
		write(1, "Error - Unable to find given map file [", 39);
		ft_putstr(map_path);
		write(1, "]\n", 2);
		return (1);
	}
	free(map_path);
}

int		main(int argc, char **argv)
{
	char	*map_path;
	int		success;

	map_path = 0;
	if (argc == 1)
	{
		write(1, "Please enter your map path [press x for default: ", 49);
		ft_putstr(g_default_map);
		write(1, "]\n", 2);
		map_path = ft_read_input(10, STDIN_FILENO);
		if (*map_path == 'x' && map_path[1] == '\0')
		{
			free(map_path);
			map_path = ft_strdup(g_default_map);
		}
	}
	else if (argc == 2)
		map_path = ft_strdup(argv[1]);
	else
	{
		write(1, "Error - Invalid argument numbers.\n", 34);
		return (1);
	}
	success = parse_map(map_path);
	return (success);
}
