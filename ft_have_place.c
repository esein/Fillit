/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_have_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kineflas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:58:46 by kineflas          #+#    #+#             */
/*   Updated: 2016/12/13 11:02:23 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_have_place(char *tri, char *res, int x)
{
	int l;

	l = 0;
	while (res[l])
	{
		if (res[l] == tri[3])
			return (1);
		l++;
	}
	while (res[x])
	{
		while (res[x] != '.' && res[x])
			x++;
		if (res[x + tri[0] + (tri[4] * sqrtab(ft_len(res)))] == '.'
				&& res[x + tri[1] + (tri[5] * sqrtab(ft_len(res)))] == '.'
				&& res[x + tri[2] + (tri[6] * sqrtab(ft_len(res)))] == '.'
				&& verifpos(x, tri, res) == 1)
		{
			ft_place_it(tri, res, x);
			return (1);
		}
		x++;
	}
	return (0);
}

void	ft_place_it(char *tri, char *res, int x)
{
	res[x] = tri[3];
	res[x + tri[0] + (tri[4] * sqrtab(ft_len(res)))] = tri[3];
	res[x + tri[1] + (tri[5] * sqrtab(ft_len(res)))] = tri[3];
	res[x + tri[2] + (tri[6] * sqrtab(ft_len(res)))] = tri[3];
}

int		verifpos(char x, char *tetri, char *res)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = 0;
	while (i != 3)
	{
		while (x >= sqrtab(ft_len(res)))
			x = x - sqrtab(ft_len(res));
		if (tetri[i] + x >= sqrtab(ft_len(res)) || tetri[i] + x < 0)
			return (0);
		i++;
	}
	return (1);
}

void	printres(char *result)
{
	int r;
	int c;

	r = 0;
	c = 0;
	while (result[r])
	{
		write(1, &result[r], 1);
		r++;
		c++;
		if (c == (sqrtab(ft_len(result))))
		{
			write(1, "\n", 1);
			c = 0;
		}
	}
}

void	ft_adapttetri(char **tetri, int s)
{
	int i;
	int x;

	i = 0;
	while (tetri[i])
	{
		x = 0;
		while (x < 3)
		{
			if (tetri[i][x] >= 4 && tetri[i][x] <= 7)
				tetri[i][x] = (tetri[i][x] + s) - 4;
			else if (tetri[i][x] >= 8 && tetri[i][x] < 12)
				tetri[i][x] = (tetri[i][x] + 2 * s) - 8;
			else if (tetri[i][x] == 12)
				tetri[i][x] = (tetri[i][x] + 3 * s) - 12;
			x++;
		}
		i++;
	}
}
