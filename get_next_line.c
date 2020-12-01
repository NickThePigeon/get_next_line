/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:40 by nduijf        #+#    #+#                 */
/*   Updated: 2020/12/01 18:27:32 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFERSIZE 10

int		get_next_line(int fd, char **line)
{
	int ret;
	int i;
	int j;
	char buf[BUFFERSIZE + 1];
	static char *temp;
	int len;

	i = 0;
	j = 0;
	len = 0;
	buf[BUFFERSIZE] = '\0';
	while (read(fd, buf, BUFFERSIZE))
	{
		len = ft_strlend(buf, '\n');
		// printf("len =%d\n", len);
		if (temp)
			*line = temp;
		*line = ft_strjoin(line[0], buf, len);
		printf("dit is buf > %s--\n", buf);
		// temp = ft_strjoin(temp, &buf[len], ft_strlen(buf) - len);
		if (buf[len])
		{
			printf("test1\n");
			temp = strdup(&buf[len + 1]);
			// if (buf[i] ==  '\n')
			// {
			// 	printf("test2\n");
			// 	temp = strdup(&buf[i + 1]);
			// 	printf("dit is temp >%s\n", temp);
			// 	break ;
			// }
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

	fd = open(argv[1], O_RDONLY);

	line = (char *)malloc(sizeof(*line) * 1);
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
	free(line);
	line = (char *)malloc(sizeof(*line) * 1);
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
	free(line);
	line = (char *)malloc(sizeof(*line) * 1);
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
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