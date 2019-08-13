/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:52:56 by csachdev          #+#    #+#             */
/*   Updated: 2019/08/12 17:12:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_read_file(char *fname)
{
	int		i;
	int		fp;
	int		bufsize;
	int		current_size;
	char	*buff;

	i = 0;
	bufsize = 1024;
	current_size = bufsize;
	buff = (char *)malloc(bufsize);
	fp = open(fname, O_RDONLY);
	while (read(fp, &buff[i], 1))
	{
		i++;
		if (i == (current_size))
		{
			current_size = bufsize + i;
			buff = (char *)realloc(buff, current_size);
		}
	}
	close(fp);
	return (buff);
}

char	*ft_assign_vars(char *str)
{
	int		i;
	char	*buff;

	buff = str;
	g_rows = ft_atoi(buff);
	while (*buff >= '0' && *buff <= '9')
		buff++;
	g_empty = buff[0];
	g_obstacle = buff[1];
	g_tofill = buff[2];
	i = 4;
	while (buff[i] != '\n')
		i++;
	g_cols = i - 4;
	return (buff);
}

void	ft_fill_char_map(char *buff)
{
	int		i;
	int		j;
	int		ctr;

	ctr = -1;
	i = -1;
	j = -1;
	g_c_map = (char **)malloc(g_rows * sizeof(char *));
	while (++i < g_rows)
		g_c_map[i] = (char *)malloc(g_cols);
	i = 0;
	while (buff[++ctr])
	{
		if (buff[ctr] == '\n')
		{
			i++;
			j = -1;
			continue ;
		}
		g_c_map[i][++j] = buff[ctr];
	}
}

int		ft_fill_int_map(void)
{
	int		i;
	int		j;

	i = -1;
	g_d_map = (int **)malloc(sizeof(int *) * g_rows);
	while (++i < g_rows)
		g_d_map[i] = (int *)malloc(sizeof(int) * g_cols);
	i = -1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_cols)
		{
			if (g_c_map[i][j] == g_empty)
				g_d_map[i][j] = 1;
			else if (g_c_map[i][j] == g_obstacle)
				g_d_map[i][j] = 0;
			else
				return (1);
		}
	}
	return (0);
}
