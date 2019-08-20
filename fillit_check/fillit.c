/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:23:42 by pnita             #+#    #+#             */
/*   Updated: 2019/05/24 16:23:46 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			rec(int side, t_lst *lst)
{
	int		x;
	int		y;

	y = 0;
	if (!lst)
		return (1);
	while (y < side)
	{
		x = 0;
		while (x < side)
		{
			if (g_map[y][x] == '.' && fill(side, lst, x, y))
			{
				if (rec(side, lst->next))
					return (1);
				else
					clean(lst, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

void		search_solution(t_lst *lst, int lst_number)
{
	int		side;
	t_lst	*tmp;

	side = ft_sqrt(4 * lst_number);
	while (1)
	{
		map_creator(side);
		tmp = lst;
		if (rec(side, tmp))
			break ;
		map_delete();
		++side;
	}
	display_map(side);
	map_delete();
}

void		make_lst_in_zikl(char **str, t_kor *kor, t_lst **lst, int *lst_num)
{
	t_lst		*tmp_lst;
	static char	bukv = 'A';

	while (**str != '\n')
	{
		if (**str == '#')
		{
			if (kor->y0 == -1)
			{
				kor->x0 = kor->x;
				kor->y0 = kor->y;
				tmp_lst = lst_push_back(lst, bukv++);
				++(*lst_num);
			}
			else
			{
				tmp_lst->x[kor->i] = kor->x - kor->x0;
				tmp_lst->y[kor->i] = kor->y - kor->y0;
				++kor->i;
			}
		}
		++(*str);
		++kor->x;
	}
}

void		kor_zero(t_kor *kor)
{
	kor->y = 0;
	kor->y0 = -1;
	kor->i = 0;
}

void		make_lst_and_rec(char *str)
{
	t_kor	kor;
	t_lst	*lst;
	int		lst_num;

	lst = NULL;
	lst_num = 0;
	kor_zero(&kor);
	while (*str)
	{
		kor.x = 0;
		make_lst_in_zikl(&str, &kor, &lst, &lst_num);
		++str;
		if (kor.y == 3)
		{
			kor_zero(&kor);
			++str;
		}
		else
			++kor.y;
	}
	search_solution(lst, lst_num);
	lst_delete(lst);
}
