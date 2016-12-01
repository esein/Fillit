/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 02:26:46 by gcadiou           #+#    #+#             */
/*   Updated: 2016/12/01 09:53:52 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

#define BUF_SIZE 21
#define L_SIZE 10
#define I_SIZE 5

static void	*file_error(char c, char **tab)
{
	ft_memdel((void **)tab);
	ft_putchar(c);
	ft_putendl("error");
	return (0);
}

char		**check_file(int fd)
{
	char	**tab;
	size_t	ret;
	char	buf[BUF_SIZE + 1];
	size_t	l = 0;
	size_t	i= 0;
	size_t	count = 0;

	tab = ft_mal_double_tab(tab, L_SIZE, I_SIZE);
	while (count < L_SIZE)
	{
		ft_memset(tab[count], '0', I_SIZE);
		count++;
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == 20)
		{
			if((ret = read(fd, buf, BUF_SIZE)))
				return (file_error('2', tab));
			count = 0;
		}
		else
			if (buf[ret-1] != '\n' || ret != 21)
				return (file_error('1', tab));
		while (l < 5)
		{
			i = 0;
			while (i < 4)
			{
				tab[l][i] = buf[i];
				i++;
			}
			if (buf[i] != '\n')
				return file_error('3',tab);
			tab[l][i] = buf[i];
			l++;
		}
	}
	if (count)
		return (file_error('4',tab));
	return (tab);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**tab;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file_test");
		return 0;
	}
	fd = open(argv[1], O_RDONLY);
	if (!(tab = check_file(fd)))
			return (0);
	ft_print_double_tab(tab, L_SIZE, I_SIZE);
}
