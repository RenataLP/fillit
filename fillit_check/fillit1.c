/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:57:03 by pnita             #+#    #+#             */
/*   Updated: 2019/06/29 15:57:05 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst		*lst_new(char bukv)
{
	t_lst		*a;

	if (!(a = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	a->bukv = bukv;
	a->next = NULL;
	return (a);
}

t_lst		*lst_push_back(t_lst **lst, char bukv)
{
	t_lst	*a;

	if (!lst || !(*lst))
	{
		(*lst) = lst_new(bukv);
		return ((*lst));
	}
	a = (*lst);
	while (a->next)
		a = a->next;
	a->next = lst_new(bukv);
	return (a->next);
}

void		lst_delete(t_lst *lst)
{
	t_lst *el;

	el = lst->next;
	while (el)
	{
		free(lst);
		lst = el;
		el = el->next;
	}
	free(lst);
	lst = NULL;
}

int			fill(int side, t_lst *tmp, int x, int y)
{
	int m_x[3];
	int m_y[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		m_x[i] = x + tmp->x[i];
		m_y[i] = y + tmp->y[i];
		if (m_x[i] < 0 || m_y[i] >= side || g_map[m_y[i]][m_x[i]] != '.')
			return (0);
		++i;
	}
	i = 0;
	while (i < 3)
	{
		g_map[m_y[i]][m_x[i]] = tmp->bukv;
		++i;
	}
	g_map[y][x] = tmp->bukv;
	return (1);
}

void		clean(t_lst *tmp, int x, int y)
{
	int	m_x[3];
	int	m_y[3];
	int	i;

	g_map[y][x] = '.';
	i = 0;
	while (i < 3)
	{
		m_x[i] = x + tmp->x[i];
		m_y[i] = y + tmp->y[i];
		g_map[m_y[i]][m_x[i]] = '.';
		i++;
	}
}
