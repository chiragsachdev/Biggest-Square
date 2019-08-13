/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:35:46 by csachdev          #+#    #+#             */
/*   Updated: 2019/08/01 21:42:18 by csachdev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_error(char *buff)
{
	int		rows;
	int		cols;
	char	empty;
	char	obs;
	
	rows = ft_atoi(buff);
	if (rows == 0)
		return (1);
	while (*buff >= '0' && *buff <= '9')
		buff++;
	empty = buff[0];
	obs = buff[1];
	if (buff[3] != '\n')
		return (0);
	cols = 4;
	while (buff[cols] != '\n')
		cols++;
	cols -= 4;
	return (ft_check_contents(buff + 4, rows, cols, empty, obs)) ? (1) : (0);
}

int		ft_check_contents(char *buff, int r, int c, char e, char o)
{
	int		i;
	int		j;
	int		flag;

	flag = 1;
	i = -1;
	while (++i <= r && flag == 1)
	{
		j = -1;
		while (++j < c)
		{
			if (!(buff[i * (c + 1) + j] == e || buff[i * (c + 1) + j] == o))
			{
				flag = 0;
				return (0);
			}
		}
		if (buff[i * (c + 1) + j] != '\n')
		{
			break ;
			return (1);
		}
	}
	return (1);
}

int		ft_empty_exists()
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_cols)
		{
			if(g_c_map[i][j] == g_empty)
				return (1);
		}
	}
	return  (0);
}

int		ft_or(int a, int b)
{
	if (a == 0 && b == 0)
		return 0;
	else 
		return (1);
}
