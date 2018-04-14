/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:18:16 by gcadiou           #+#    #+#             */
/*   Updated: 2016/12/07 01:53:05 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int		file_error(char *str)
{
	ft_putendl(str);
	return (0);
}

int		check_file(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	size_t	i;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (file_error("open error"));
	ret = (read(fd, buf, BUF_SIZE));
	if(!(((ret + 1) % 21 == 0) || (ret + 1) / 21 > 26))
		return (file_error("error"));
	return (1);
}
