/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdiakit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:03:05 by abdiakit          #+#    #+#             */
/*   Updated: 2024/04/02 12:23:58 by abdiakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_string(unsigned int n)
{
	static char	str[11];
	long		nb;
	int			i;

	nb = n;
	i = len(nb);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
	return (str);
}

static void	ft_putnbr(unsigned int n, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_string(n);
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_print_unsig(unsigned int nbr)
{
	int	i;

	i = len(nbr);
	ft_putnbr(nbr, 1);
	return (i);
}
