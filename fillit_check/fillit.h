/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:45:37 by pnita             #+#    #+#             */
/*   Updated: 2019/06/03 19:45:40 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_lst
{
	char			bukv;
	int				x[3];
	int				y[3];
	struct s_lst	*next;
}					t_lst;

typedef struct		s_kor
{
	int				x0;
	int				y0;
	int				x;
	int				y;
	int				i;
}					t_kor;

char				**g_map;

int					error_print(char *str);
int					check_counts(char *s);
int					check_connection(char *s);
void				make_lst_and_rec(char *str);
void				kor_zero(t_kor *kor);
void				make_lst_in_zikl(char **str,
t_kor *kor, t_lst **lst, int *lst_num);
void				search_solution(t_lst *lst, int lst_number);
int					rec(int side, t_lst *lst);
void				clean(t_lst *tmp, int x, int y);
int					fill(int side, t_lst *tmp, int x, int y);
void				lst_delete(t_lst *lst);
t_lst				*lst_push_back(t_lst **lst, char bukv);
t_lst				*lst_new(char bukv);
void				map_delete(void);
void				map_creator(int n);
void				display_map(int side);
int					ft_sqrt(int n);

#endif
