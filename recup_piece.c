/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 02:26:46 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/30 07:10:58 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 21

int		file_error(void)
{
	putstr("error");
	return (0);
}

int		check(int argc, char **argv)
{
	char	**tab[26][26];
	size_t	ret;
	int		fd;
	char	buf[BUF_SIZE + 1];

		if (argc != 2)
		return 0;
	fd = open(argv[1],O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (buf[ret] != '\n')
			return (file_error());
		
	}
