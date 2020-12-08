/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:34 by nduijf        #+#    #+#                 */
/*   Updated: 2020/12/08 17:08:14 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *ptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	ptr = malloc(nitems * size);
	if (ptr)
		ft_bzero(ptr, nitems * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

int	ft_strlend(const char *str, char c)
{
	int n;

	n = 0;
	while (str[n] != '\0' && str[n] != c)
	{
		n++;
	}
	return (n);
}

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

int		ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void		*ft_memset(void *dest, int val, size_t len)
{
	unsigned char *ptr;

	ptr = dest;
	while (len > 0)
	{
		*ptr = val;
		ptr++;
		len--;
	}
	return (dest);
}

int		ft_modstr(char *s, char c)
{
	int i;
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ft_strcpy(s, s + i + 1);
			return (1);
		}
		i++;
	}
	s[0] = '\0';
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int lens2)
{
	int		i;
	int		k;
	char	*newstr;

/* 	if (!s2)
		return (NULL); */
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
	while (k < lens2)
	{
		newstr[i] = s2[k];
		i++;
		k++;
	}
	free(s1);
	newstr[i] = '\0';
	return (newstr);
}
