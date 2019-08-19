/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hmarlin <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 19:27:02 by hmarlin      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 19:59:05 by hmarlin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void	show_b(super *totostruct)
{
	printf("%i %i", totostruct->a, totostruct->b);
}

int		main()
{
	super	*toto;

	toto = malloc(sizeof(super));

	toto->a = 42;
	toto->b = 55;

	show_b(toto);
	free(toto);
}
