/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:43 by nduijf        #+#    #+#                 */
/*   Updated: 2020/12/08 14:24:36 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlend(const char *str, char c);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char *s1, char *s2, int lens2);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, char *src);
int		ft_modstr(char *s, char c);
void	*ft_memset(void *dest, int val, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);


#endif
