/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kineflas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 23:20:27 by kineflas          #+#    #+#             */
/*   Updated: 2016/12/13 11:49:33 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		s;
	char	*result;

	s = 0;
	i = 0;
	result = 0;
	if (argc != 2)
	{
		write(1, "usage: ./fillit file_to_resolv\n", 31);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	s = ft_ckecketri(fd, s, i);
	if (s == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	result = ft_solve(ft_savetetri(fd, s, i), s, result);
	printres(result);
	return (0);
}
