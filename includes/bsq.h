/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csachdev <csachdev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:49:35 by csachdev          #+#    #+#             */
/*   Updated: 2019/08/01 18:24:20 by csachdev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *buff);
void	ft_put_char_matrix(void);
void	ft_put_int_matrix(void);
int		ft_get_filesize(char *fname);
char	*ft_read_file(char *fname);
char	*ft_assign_vars(char *str);
void	ft_fill_char_map(char *buff);
int		ft_fill_int_map(void);
void	ft_putnbr(int n);
void	ft_create_dpmap(void);
int		ft_min(int a, int b, int c);
void	ft_fill_dpmap(void);
int		ft_get_max(void);
int		*ft_find_first_max(int max);
void	ft_find_bsq(char *buff);
void	ft_solution(int *location, int max);
char	*ft_get_buff_stdip(void);
void	ft_iterate(int argc, char **argv);
int		ft_check_error(char *buff);
int		ft_check_contents(char *buff, int r, int c, char e, char o);
int		ft_empty_exists();
int		ft_or(int a, int b);

int		g_rows;
int		g_cols;
char	g_empty;
char	g_obstacle;
char	g_tofill;
char	**g_c_map;
int		**g_d_map;
int		**g_dp_map;
#endif
