/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:35:14 by mskeleto          #+#    #+#             */
/*   Updated: 2021/10/07 00:03:45 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (ft_check_arg(argv) == 1)
		ft_error();
	else
	{
		a = ft_parser(argc, argv);
		b = (t_stack *)malloc((argc) * sizeof(t_stack));
		ft_null(b, argc - 1);
		ft_go_to_swap_party(a, b, argc - 1);
	}
	return (0);
}
