/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kineflas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:23:12 by kineflas          #+#    #+#             */
/*   Updated: 2016/12/14 02:54:09 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_form(char *buf)
{
	int s;
	int c;

	s = 0;
	c = 0;
	while (s < 20)
	{
		if (buf[s] == '#')
		{
			if (buf[s + 1] == '#')
				c++;
			if (buf[s - 1] == '#')
				c++;
			if (buf[s - 5] == '#')
				c++;
			if (buf[s + 5] == '#')
				c++;
		}
		s++;
	}
	if (c >= 6)
		return (0);
	return (1);
}

int		ft_ckecketri(int fd, int s, int a)
{
	int		i;
	int		pt;
	int		diez;
	char	b[21];

	b[20] = '\n';
	while ((i = read(fd, b, 21)))
	{
		a = i;
		i = 0;
		pt = 0;
		diez = 0;
		while (i != 20)
		{
			pt += (b[i] == '.') ? +1 : 0;
			diez += (b[i++] == '#') ? +1 : 0;
		}
		s++;
		if (diez != 4 || pt != 12 || b[20] != '\n' || ft_form(b) || b[4] != '\n'
				|| b[9] != '\n' || b[14] != '\n' || b[19] != '\n')
			return (0);
	}
	s += (a != 20) ? -s : 0;
	return (s);
}

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_save(char *buf, char **tetri, int v, int s)
{
	int		i;
	char	l;
	char	n;

	i = 0;
	n = 0;
	l = 0;
	while (v < 3)
	{
		l++;
		while (buf[i] != '#' && buf[i])
			i++;
		i++;
		while (buf[i] != '#' && buf[i])
		{
			l += (buf[i] != '\n') ? 1 : -4;
			n += (buf[i++] == '\n') ? 1 : 0;
		}
		tetri[s][v + 4] = n;
		tetri[s][v++] = l;
	}
}

char	**ft_savetetri(int fd, int s, int i)
{
	char	buf[21];
	char	**tetri;
	int		v;
	char	letter;

	letter = 'A';
	if (!(tetri = malloc(sizeof(char *) * (s + 1))))
		return (0);
	while (i != s)
		tetri[i++] = malloc(sizeof(char) * 8);
	s = 0;
	while (read(fd, buf, 21))
	{
		v = 0;
		ft_save(buf, tetri, v, s);
		tetri[s][3] = letter;
		letter++;
		tetri[s++][7] = '\0';
	}
	tetri[s] = 0;
	return (tetri);
}
