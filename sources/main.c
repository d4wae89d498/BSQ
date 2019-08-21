/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 13:25:24 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 19:29:51 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./../includes/string.h"
#include "./../includes/stdio.h"
#include "./../includes/map.h"
#include <stdio.h>

int		parse_map(char *map_path)
{
	char		*map_file_buffer;
	t_map		map;
	int		exit_code;

	exit_code = 0;
	map_file_buffer = ft_read_file(map_path);
	free(map_path);
	if (map_file_buffer > 0)
	{
		if(!ft_fill_map(map_file_buffer, &map) && ++exit_code)
			write(1, "map error\n", 10);
		if (!exit_code)
			if (!ft_display_map(map_file_buffer, &map) && ++exit_code)
				write(1, "map error\n", 10);
		free(map_file_buffer);
	}
	else
	{
		write(1, "map error\n", 10);
		exit_code = 1;
	}
	return (exit_code);
}

int		main(int argc, char **argv)
{
	char		*map_path;
	int		exit_code;
	int		i;

	exit_code = 0;
	map_path = 0;
	if (argc == 1)
	{
		map_path = ft_read_input(10, STDIN_FILENO);
		exit_code = exit_code || parse_map(map_path);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map_path = ft_strdup(argv[i]);
			exit_code = exit_code || parse_map(map_path);
			i += 1;
		}
	}
	return (exit_code);
}
