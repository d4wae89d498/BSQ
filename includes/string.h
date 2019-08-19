/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 15:43:14 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 15:45:11 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

char					*ft_strdup(char *str);

int						ft_is_space(char c);

char					*ft_trim_begin(char *str);

int						ft_is_number(char c);

unsigned long long		ft_atoi(char *nbr);

#endif
