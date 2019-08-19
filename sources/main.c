/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 13:25:24 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 15:48:25 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./../includes/string.h"
#include "./../includes/stdio.h"

const char	*g_default_map = "./maps/00.txt";

int		main(int argc, char **argv)
{
	char	*map_path;

	map_path = 0;
	// no argument => ask for a map
	if (argc == 1)
	{
		map_path = ft_read_input(10, STDIN_FILENO);	
	}
	// givn argument is a map path
	else if (argc == 2)
	{
		map_path = ft_strdup(argv[1]);
	}
	else
	{
		write(1, "Error - Invalid argument numbers.\n", 34);
		return (1);
	}
	free(map_path);
}
