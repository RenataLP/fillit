/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:53:10 by pnita             #+#    #+#             */
/*   Updated: 2019/06/29 15:53:13 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_connection(char *s)
{
	int	grid;
	int	i;

	grid = 0;
	i = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && s[i + 1] == '#')
				grid++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				grid++;
			if ((i + 5) < 20 && s[i + 5] == '#')
				grid++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				grid++;
		}
		i++;
	}
	return (grid == 6 || grid == 8);
}

int			check_counts(char *s)
{
	int i;
	int grid_count;

	grid_count = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(s[i] == '#' || s[i] == '.'))
				return (0);
			if (s[i] == '#' && ++grid_count > 4)
				return (0);
		}
		else if (s[i] != '\n')
			return (0);
		++i;
	}
	if (grid_count < 4 || !check_connection(s))
		return (0);
	return (1);
}

int			error_print(char *str)
{
	int		i;
	int		j;
	char	*str_new;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if ((str_new = (char *)malloc(sizeof(char) * 21)) == NULL)
			return (0);
		while (j < 20 && str[i])
			str_new[j++] = str[i++];
		str_new[j] = '\0';
		if (j < 19 || !check_counts(str_new) ||
				!((str[i] == '\n' && str[i + 1]) || str[i] == '\0'))
			j = -1;
		free(str_new);
		str_new = NULL;
		if (j == -1)
			return (0);
		if (str[i])
			++i;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		sz;
	char	str[BUFF_SIZE + 1];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || (sz = read(fd, str, BUFF_SIZE)) <= 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		str[sz] = '\0';
		if (sz > 545 || !error_print(str))
			write(1, "error\n", 6);
		else
			make_lst_and_rec(str);
	}
	else
		write(1, "usage: fillit input_file\n", 25);
	return (0);
}
