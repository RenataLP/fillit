/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:59:43 by pnita             #+#    #+#             */
/*   Updated: 2019/06/29 15:59:45 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int n)
{
	int	i;

	if (n < 0)
		return (-1);
	i = 0;
	while (i * i < n)
		++i;
	return (i);
}

void		display_map(int side)
{
	int i;

	i = 0;
	while (g_map[i])
	{
		write(1, g_map[i], side);
		write(1, "\n", 1);
		++i;
	}
}

void		map_creator(int n)
{
	int		i;
	int		j;

	if (!(g_map = (char**)malloc(sizeof(char*) * (n + 1))))
		return ;
	i = 0;
	while (i < n)
	{
		j = 0;
		if (!(g_map[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return ;
		while (j < n)
		{
			g_map[i][j] = '.';
			++j;
		}
		g_map[i][j] = '\0';
		++i;
	}
	g_map[i] = NULL;
}

void		map_delete(void)
{
	int i;

	i = 0;
	while (g_map[i])
	{
		free(g_map[i]);
		g_map[i] = NULL;
		++i;
	}
	free(g_map);
	g_map = NULL;
}
