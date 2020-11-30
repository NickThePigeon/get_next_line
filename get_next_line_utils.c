/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:34 by nduijf        #+#    #+#                 */
/*   Updated: 2020/11/30 20:45:47 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!newstr)
		return (0);
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	int				i;
	unsigned int	lenght;

	if (!s)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	lenght = len + start;
	if (start <= ft_strlen(s))
	{
		while (start < lenght)
		{
			newstr[i] = s[start];
			i++;
			start++;
		}
	}
	newstr[i] = '\0';
	return (newstr);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) * sizeof(char)) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		newstr[i] = s2[k];
		i++;
		k++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	if (c == 0)
		return ((char*)&str[i]);
	else
		return (0);
}
