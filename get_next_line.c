/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:40 by nduijf        #+#    #+#                 */
/*   Updated: 2020/12/04 10:57:00 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFERSIZE 1000

static char		*ft_add_res(char *oldres, char *buf)
{
	int i;
	int res_len;
	int buf_res_len;
	char *newres;

	res_len = 0;
	buf_res_len = 0;
	if (oldres)
		res_len = ft_strlen(oldres);
	buf_res_len = ft_strlen(buf) - ft_strlend(buf, '\n');
	i = 0;
	newres = (char *)malloc(sizeof(char) * res_len + buf_res_len + 1);
	while (i < res_len)
	{
		newres[i] = oldres[i];
		i++;
	}
	int k = ft_strlend(buf, '\n');
	while (buf_res_len > 0)
	{
		newres[i] = buf[k + 1];
		i++;
		k++;
		buf_res_len--;
	}
	newres[i] = '\0';
	return (newres);
}

static char		*ft_strduplen(const char *str, int len)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!newstr)
		return (0);
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static char		*ft_return_line(char *line, char *res)
{
	int i;
	int len;

	len = ft_strlend(res, '\n');
	if (len == ft_strlen(res))
		return (0);
	line = ft_strduplen(res, len);
	return (line);
	
}


int		get_next_line(int fd, char **line)
{
	int i;
	char buf[BUFFERSIZE + 1];
	static char *res;
	int len;
	int ret;

	ret = 1;
	i = 0;
	buf[BUFFERSIZE] = '\0';
	if (res)
	{
		if (ft_return_line(*line, res) != 0)
		{
			*line = ft_return_line(*line, res);
			return (ft_modstr(res, '\n'));
		}
		else
		{
			*line = strdup(res); 
			res = ft_memset(res, '\0', ft_strlen(res));
		}
	}
	while (ret > 0)
	{
		ret = (read(fd, buf, BUFFERSIZE));
		buf[ret] = '\0';
		len = ft_strlend(buf, '\n');
		*line = ft_strjoin(line[0], buf, len);
		if (buf[len])
		{
			res = ft_add_res(res,buf);
			i++;
		}
		if (i > 0)
			return (1);
	}
	return (0);
}
int main(int argc, char **argv)
{
	char *line;
	int fd;
	int ret;
	(void)argc;
	int i = 0;

	fd = open(argv[1], O_RDONLY);


	while (i < 22)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		ret = get_next_line(fd, &line);
		printf("line --> %s\n", line);
		free(line);
		i++;
	}
	return (0);
}