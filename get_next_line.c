/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:21:40 by nduijf        #+#    #+#                 */
/*   Updated: 2020/11/24 18:04:54 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fildes.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line)
{

}
int main(void)
{
	char *ptr;
	int fd;

	ptr = (char *)malloc(sizeof(char) * 20);
	fd = open("testfile.txt", O_RDONLY);
}