/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:09:31 by csachdev          #+#    #+#             */
/*   Updated: 2019/08/01 22:37:08 by csachdev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '-')
	{
		ft_putchar('-');
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (int)(str[i] - '0');
		i++;
	}
	return (num);
}
