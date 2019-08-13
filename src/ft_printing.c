/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:53:26 by csachdev          #+#    #+#             */
/*   Updated: 2019/07/31 15:46:20 by csachdev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_put_char_matrix(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_cols)
			ft_putchar(g_c_map[i][j]);
		ft_putchar('\n');
	}
}

void	ft_put_int_matrix(void)
{
	int		i;
	int		j;

	i = 0;
	while (++i < g_rows + 1)
	{
		j = 0;
		while (++j < g_cols + 1)
			ft_putnbr(g_dp_map[i][j]);
		ft_putchar('\n');
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
