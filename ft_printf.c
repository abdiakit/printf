/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdiakit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:08:12 by abdiakit          #+#    #+#             */
/*   Updated: 2024/04/03 16:04:05 by abdiakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *format, void *args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_char((char)args);
	else if (*format == 's')
		i += ft_print_string((char *)args);
	else if (*format == 'p')
		i += ft_print_ptr((unsigned long)args);
	else if (*format == 'd' || *format == 'i')
		i += print_int((int)args);
	else if (*format == 'u')
		i += ft_print_unsig((unsigned int)args);
	else if (*format == 'x')
		i += ft_print_hex((unsigned int)args);
	else if (*format == 'X')
		i += ft_print_hex_upp((unsigned int)args);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	len;

	len = 0;
	va_start (args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				len += check_type(format, va_arg(args, void *));
			else if (*format == '%')
				len += ft_char('%');
		}
		else
			len += ft_char(*format);
		format++;
	}
	return (len);
}
