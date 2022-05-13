/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:17:40 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/06 19:28:31 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strdgt(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_isint(char *str)
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
	return (0);
}

int	ft_isdouble(char **argv, char *str, int index)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ((ft_atoi(str) == ft_atoi(argv[i])) && (i != index))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strdgt(argv[i]) == 1 || ft_strlen(argv[i]) == 0)
			return (1);
		if (ft_isint(argv[i]) == -1)
			return (1);
		if (ft_isdouble(argv, argv[i], i) == -1)
			return (1);
		i++;
	}
	return (0);
}
