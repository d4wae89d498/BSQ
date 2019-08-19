/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 15:48:42 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 15:48:44 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 15:41:43 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 15:43:02 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char				*ft_strdup(char *str)
{
	unsigned int	len;
	char			*out;

	len = -1;
	while (*(str + ++len))
		;
	out = malloc(len + 1);
	while (*str)
		*out++ = *str++;
	*out = '\0';
	return (out - len);
}

int					ft_is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char				*ft_trim_begin(char *str)
{
	str -= 1;
	while (*++str && ft_is_space(*str))
		;
	return (str);
}

int					ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

unsigned long long	ft_atoi(char *nbr)
{
	unsigned long long	out;

	out = 0;
	nbr = ft_trim_begin(nbr) - 1;
	while (*++nbr && ft_is_number(*nbr))
		out = (out + *nbr - '0') * (ft_is_number(*(nbr + 1)) ? 10 : 1);
	return (out);
}
