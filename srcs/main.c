/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:15:20 by loadjou           #+#    #+#             */
/*   Updated: 2022/12/16 20:59:20 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

#define NC "\e[0m"
#define YELLOW "\e[1;33m"

void	init_vars(char **argv, t_table *tab)
{
	tab->philos_nb = ft_atol(argv[1]);
	if (tab->philos_nb)
	{
		tab->philos = malloc(sizeof(t_philos) * tab->philos_nb);
		if (!tab->philos)
			exit(0);
		if (tab->philos_nb > 200)
		{
			printf("%s", MAXPHIL);
			tab->philos_nb = 200;
		}
	}
	tab->philos->time_to_die = ft_atol(argv[2]);
	tab->time_to_eat = ft_atol(argv[3]);
	tab->time_to_sleep = ft_atol(argv[4]);
	tab->repeat_time = INT_MAX;
	tab->alive = 1;
	if (argv[5])
	{
		tab->repeat_time = ft_atol(argv[5]);
	}
	print_data(tab);
	check_provided_values(tab);
}

void	check_provided_values(t_table *tab)
{
	if (tab->philos_nb < 1 || tab->philos->time_to_die < 1
		|| tab->time_to_eat < 1 || tab->time_to_sleep < 1
		|| tab->repeat_time < 1)
		write(2, NEGNUMS, sizeof(NEGNUMS));
}

static void	exec_program(t_table *tab)
{
	init_threads(tab);
	join_threads(tab);
}

int	main(int argc, char **argv)
{
	t_table	tab;

	if (argc <= 6 && argc >= 5)
	{
		if (only_digits(&argv[1]) == 0)
		{
			printf("Args format not accepted!\n");
			return (0);
		}
		init_vars(argv, &tab);
		exec_program(&tab);
		free(tab.philos);
	}
	else
		printf("Please insert args as follow: [int] [int] [int] [int] [int (optional)]\n");
	return (0);
}
