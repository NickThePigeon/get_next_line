/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:40 by nduijf        #+#    #+#                 */
/*   Updated: 2020/11/30 20:58:30 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFERSIZE 30

static int		ft_line_len(char *str)
{
	int i;

	i = 0;
	while (str)
	{
		if (str[i] == 10)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int ret;
	int i;
	static char buf[BUFFERSIZE + 1];

	i = 0;
	while (read(fd, buf, BUFFERSIZE))
	{
		while (i < BUFFERSIZE)
		{
			if (buf[i] == '\n')
		}
		*line = ft_strjoin(*line, buf);
	}
	*line[ft_line_len(*line) + 1] = '\0';
	return (0);

}
int main(int argc, char **argv)
{
	char *line;
	int fd;
	int ret;
	(void)argc;

	fd = open(argv[1], O_RDONLY);

	line = (char *)malloc(sizeof(*line) * 1);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
/* 	line = (char *)malloc(sizeof(*line) * 1);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	line = (char *)malloc(sizeof(*line) * 1);
	ret = get_next_line(fd, &line);
	printf("%s\n", line); */
	return (0);
}