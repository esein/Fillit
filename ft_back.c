/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kineflas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 22:50:47 by kineflas          #+#    #+#             */
/*   Updated: 2016/12/13 11:00:48 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_back(char **tri, int i, char *re)
{
	int x;

	x = 0;
	while (tri[i])
	{
		x = freeresult(tri[i - 1], re);
		if (ft_have_place(tri[i - 1], re, x) == 1)
		{
			while (tri[i] != 0 && ft_have_place(tri[i], re, 0 == 1))
				i++;
			if (tri[i] == 0)
				return (1);
		}
		if (ft_have_place(tri[i - 1], re, x) != 1 && i >= 0)
			i--;
		if (i == 0)
			return (0);
	}
	return (0);
}

char	*ft_solve(char **tetri, int s, char *result)
{
	int i;
	int x;

	s = sqrtab(s * 4);
	result = ft_createtab(s);
	ft_adapttetri(tetri, s);
	i = 0;
	while (tetri[i])
	{
		x = 0;
		if (ft_have_place(tetri[i], result, x))
			i++;
		else
		{
			if (i == 0 || ft_back(tetri, i, result) == 0)
			{
				result = ft_createtab(++s);
				i = 0;
				freeresult(tetri[0], result);
			}
		}
	}
	return (result);
}

int		freeresult(char *tetri, char *result)
{
	int i;
	int s;
	int r;

	i = 0;
	s = 0;
	r = 0;
	while (result[i])
	{
		if (result[i] == tetri[3] && s == 0)
		{
			r = i + 1;
			s++;
		}
		if (result[i] >= tetri[3])
			result[i] = '.';
		i++;
	}
	return (r);
}

char	*ft_createtab(int s)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * (s * s + 1))))
		return (0);
	while (i != s * s)
	{
		tab[i] = '.';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int		sqrtab(int nb)
{
	int		teurcomp;

	teurcomp = 0;
	while (teurcomp * teurcomp != nb && teurcomp * teurcomp < nb)
		teurcomp++;
	return (teurcomp);
}
