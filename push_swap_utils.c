/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:36:44 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 00:18:17 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long int	resul;
	int			positive;

	positive = 1;
	resul = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		positive = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		resul = resul * 10 + (*str - 48);
		if ((resul > 2147483648) && (positive == -1))
			return (-1);
		if ((resul > 2147483647) && (positive == 1))
			return (-1);
		str++;
	}
	return (positive * resul);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
}
