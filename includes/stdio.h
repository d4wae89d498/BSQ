/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdio.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/19 15:36:46 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 16:15:47 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STDIO_H
# define STDIO_H

void	ft_putstr(char *str);

char	*ft_read_input(char delimiter, int fd);

char	*ft_read_file(char *file_path);
#endif
