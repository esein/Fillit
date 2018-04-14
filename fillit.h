/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 02:21:14 by gcadiou           #+#    #+#             */
/*   Updated: 2016/12/13 10:38:24 by kineflas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_len(char *str);
int		ft_form(char *buf);
int		ft_ckecketri(int fd, int s, int i);
char	**ft_savetetri(int fd, int s, int i);
char	*ft_createtab(int s);
int		sqrtab(int nb);
int		ft_place(char *tetri, char **tab);
void	ft_adapttetri(char **tetri, int s);
char	*ft_solve(char **tetri, int s, char *result);
int		ft_have_place(char *tetri, char *result, int s);
void	ft_place_it(char *tetri, char *result, int x);
int		verifpos(char x, char *tetri, char *res);
int		ft_back(char **tetri, int i, char *result);
int		freeresult(char *tetri, char *result);
void	printres(char *result);
int		ft_back(char **tetri, int i, char *result);

#endif
