/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:11:11 by fvon-de           #+#    #+#             */
/*   Updated: 2025/04/07 17:19:11 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_fd_var(char *str, int *len, int fd);
static void	ft_putnum_fd_var(long long num, int base, int *len, int fd);
static void	ft_vdprintf(int fd, const char *fmt, va_list ap, int *len);

// Write a string to the given file descriptor
static void	ft_putchar_fd_var(char *str, int *len, int fd)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(fd, str++, 1);
}

// Write a number in the given base to the file descriptor
static void	ft_putnum_fd_var(long long num, int base, int *len, int fd)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num < 0)
	{
		*len += write(fd, "-", 1);
		num = -num;
	}
	if (num >= base)
		ft_putnum_fd_var(num / base, base, len, fd);
	*len += write(fd, &hex[num % base], 1);
}

// Core variadic logic to parse format string and write to fd
static void	ft_vdprintf(int fd, const char *fmt, va_list ap, int *len)
{
	while (*fmt)
	{
		if (*fmt == '%' && (*(fmt + 1) == 's'
				|| *(fmt + 1) == 'd' || *(fmt + 1) == 'x'))
		{
			fmt++;
			if (*fmt == 's')
				ft_putchar_fd_var(va_arg(ap, char *), len, fd);
			else if (*fmt == 'd')
				ft_putnum_fd_var(va_arg(ap, int), 10, len, fd);
			else if (*fmt == 'x')
				ft_putnum_fd_var(va_arg(ap, unsigned int), 16, len, fd);
		}
		else
			*len += write(fd, fmt, 1);
		fmt++;
	}
}

// Public function: printf-style output to any file descriptor
int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	ft_vdprintf(fd, fmt, ap, &len);
	va_end(ap);
	return (len);
}
