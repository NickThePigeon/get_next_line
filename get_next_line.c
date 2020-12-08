/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:40 by nduijf        #+#    #+#                 */
/*   Updated: 2020/12/08 17:10:45 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFERSIZE 1

static char		*ft_add_res(char *oldres, char *buf)
{
	int i[2];
	int res_len;
	int buf_res_len;
	char *newres;

	res_len = 0;
	if (oldres)
		res_len = ft_strlen(oldres);
	buf_res_len = ft_strlen(buf) - ft_strlend(buf, '\n');
	i[0] = 0;
	newres = (char *)ft_calloc(res_len + buf_res_len + 1, sizeof(char));
	while (i[0] < res_len)
	{
		newres[i[0]] = oldres[i[0]];
		i[0]++;
	}
	i[1] = ft_strlend(buf, '\n');
	while (buf_res_len > 0)
	{
		newres[i[0]] = buf[i[1] + 1];
		i[0]++;
		i[1]++;
		buf_res_len--;
	}
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
			*line = ft_strdup(res); 
			res = ft_memset(res, '\0', ft_strlen(res));
		}
	}
	while (ret > 0)
	{
		ret = (read(fd, buf, BUFFERSIZE));
		buf[ret] = '\0';
		len = ft_strlend(buf, '\n');
		*line = ft_strjoin(*line, buf, len);
		if (buf[len])
		{
			res = ft_add_res(res,buf);
			i++;
		}
		if (i > 0)
			return (1);
	}
	return (-1);
}
// int main(int argc, char **argv)
// {
// 	char *line;
// 	int fd;
// 	int ret;
// 	(void)argc;
// 	int i = 0;

// 	fd = open(argv[1], O_RDONLY);


// 	ret = 1;
// 	while (ret > 0)
// 	{
// 		line = (char *)malloc(sizeof(*line) * 1);
// 		ret = get_next_line(fd, &line);
// 		printf("line --> %s\n", line);
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }