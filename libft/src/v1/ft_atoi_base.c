/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:32:05 by fvon-de           #+#    #+#             */
/*   Updated: 2025/03/09 19:53:14 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign_and_offset(const char *str, int *sign);
static int	get_digit_value(char c, const char *base, int base_len);

int	ft_atoi_base(const char *str, const char *base)
{
	int	result;
	int	sign;
	int	base_len;
	int	i;
	int	digit;

	if (!str || !base || ft_strlen(base) < 2)
		return (0);
	result = 0;
	i = get_sign_and_offset(str, &sign);
	base_len = ft_strlen(base);
	while (str[i] != '\0')
	{
		digit = get_digit_value(str[i], base, base_len);
		if (digit == -1)
			return (0);
		result = result * base_len + digit;
		i++;
	}
	return (result * sign);
}

static int	get_sign_and_offset(const char *str, int *sign)
{
	if (str[0] == '-')
	{
		*sign = -1;
		return (1);
	}
	else if (str[0] == '+')
	{
		*sign = 1;
		return (1);
	}
	*sign = 1;
	return (0);
}

static int	get_digit_value(char c, const char *base, int base_len)
{
	int	j;
	int	lowered_c;

	j = 0;
	lowered_c = ft_tolower(c);
	while (j < base_len)
	{
		if (lowered_c == ft_tolower(base[j]))
		{
			return (j);
		}
		j++;
	}
	return (-1);
}
