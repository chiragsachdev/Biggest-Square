/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:10:40 by csachdev          #+#    #+#             */
/*   Updated: 2019/08/01 21:45:43 by csachdev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char *argv[])
{
	char *buff;

	if (argc == 2)
	{
		buff = ft_read_file(argv[1]);
		ft_check_error(buff) ? ft_putstr("map error\n") : ft_find_bsq(buff);
	}
	else if (argc == 1)
	{
		buff = ft_get_buff_stdip();
		ft_check_error(buff) ? ft_putstr("map error\n") : ft_find_bsq(buff);
	}
	else
	{
		ft_iterate(argc, argv);
	}
	return (0);
}
