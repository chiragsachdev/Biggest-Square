/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:17:04 by blerdwor          #+#    #+#             */
/*   Updated: 2019/08/01 18:24:17 by csachdev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int		ft_min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
	return (0);
}

void	ft_create_dpmap(void)
{
	int i;
	int j;

	i = -1;
	g_dp_map = (int **)malloc(sizeof(int *) * (g_rows + 1));
	while (++i < g_rows + 1)
	{
		g_dp_map[i] = (int *)malloc(sizeof(int) * (g_cols + 1));
		j = -1;
		while (++j < g_cols + 1)
		{
			if (i == 0 || j == 0)
				g_dp_map[i][j] = 0;
			else
				g_dp_map[i][j] = g_d_map[i - 1][j - 1];
		}
	}
	free(g_d_map);
}

void	ft_fill_dpmap(void)
{
	int i;
	int j;

	i = 0;
	while (++i <= g_rows)
	{
		j = 0;
		while (++j <= g_cols)
		{
			if (g_dp_map[i][j] == 0)
				continue;
			else
				g_dp_map[i][j] = ft_min(g_dp_map[i - 1][j],
				g_dp_map[i][j - 1], g_dp_map[i - 1][j - 1]) + 1;
		}
	}
}

int		ft_get_max(void)
{
	int max;
	int i;
	int j;

	max = 0;
	i = 0;
	while (++i <= g_rows)
	{
		j = 0;
		while (++j <= g_cols)
		{
			if (g_dp_map[i][j] > max)
				max = g_dp_map[i][j];
		}
	}
	return (max);
}

int		*ft_find_first_max(int max)
{
	int *n;
	int i;
	int j;
	int flag;

	flag = 1;
	n = (int *)malloc(8);
	j = 0;
	while (++j <= g_cols && flag == 1)
	{
		i = 0;
		while (++i <= g_rows)
		{
			if (g_dp_map[i][j] == max)
			{
				n[0] = j - 1;
				n[1] = i - 1;
				flag = 0;
				break ;
			}
		}
	}
	return (n);
}
