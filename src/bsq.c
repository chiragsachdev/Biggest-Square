/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:40:07 by csachdev          #+#    #+#             */
/*   Updated: 2019/08/12 16:46:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_solution(int *location, int max)
{
	int		i;
	int		j;

	i = location[1] - max;
	while (++i <= location[1])
	{
		j = location[0] - max;
		while (++j <= location[0])
			g_c_map[i][j] = g_tofill;
	}
	ft_put_char_matrix();
}

void	ft_find_bsq(char *buff)
{
	int		max;
	int		*location;
	int		flag;

	location = (int *)malloc(8);
	buff = ft_assign_vars(buff);
	buff += 4;
	ft_fill_char_map(buff);
	flag = ft_fill_int_map();
	if (flag || ft_empty_exists() == 0)
	{
		ft_putstr("map error\n");
		return ;
	}
	ft_create_dpmap();
	ft_fill_dpmap();
	max = ft_get_max();
	location = ft_find_first_max(max);
	ft_solution(location, max);
}

char	*ft_get_buff_stdip(void)
{
	char	*buff;
	char	ch;
	int		i;
	int		bufsize;
	int		current_size;

	bufsize = 1024;
	current_size = bufsize;
	buff = (char *)malloc(bufsize);
	i = 0;
	while (read(0, &ch, 1))
	{
		buff[i++] = ch;
		if (i == (current_size))
		{
			current_size = bufsize + i;
			buff = (char *)realloc(buff, current_size);
		}
	}
	return (buff);
}

void	ft_iterate(int argc, char **argv)
{
	int		i;
	char	*buff;

	i = 0;
	while (++i < argc)
	{
		buff = ft_read_file(argv[i]);
		ft_find_bsq(buff);
	}
}
