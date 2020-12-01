/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:40 by nduijf        #+#    #+#                 */
/*   Updated: 2020/12/01 17:41:35 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFERSIZE 1

int		get_next_line(int fd, char **line)
{
	int ret;
	int i;
	int j;
	char buf[BUFFERSIZE + 2];
	static char *temp;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (read(fd, buf, BUFFERSIZE))
	{
		buf[BUFFERSIZE + 1] = '\0';
		len = ft_strlend(buf, '\n');
		if (temp)
		*line = ft_strdup(temp);
		*line = ft_strjoin(line[0], buf, len);
	
		while (buf[i])
		{
			if (buf[i] ==  '\n')
			{
				temp = strdup(&buf[i + 1]);
				break ;
			}
			i++;
		}
		if (i > len)
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