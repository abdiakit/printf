/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdiakit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:18:11 by abdiakit          #+#    #+#             */
/*   Updated: 2024/04/03 16:03:20 by abdiakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

int		ft_print_unsig(unsigned int nbr);
int		ft_print_string(char *str);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_hex(unsigned int nb);
int		ft_print_hex_upp(unsigned int nb);
int		print_int(int n);
int		ft_char(char c);
char	*ft_strchr(const char *str, int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *format, ...);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
