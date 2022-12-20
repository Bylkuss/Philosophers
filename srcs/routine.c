/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:47:05 by loadjou           #+#    #+#             */
/*   Updated: 2022/12/16 21:08:07 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine(void *args)
{
	t_philos *philo;
    // t_table *table;
    // table = (t_table *)args;
    // table->philo_nb = 1;
	philo = (t_philos *)args;
	// tab = args;
    printf("Message from thread nb %ld\n", philo->id);
    usleep(2);
    return (0);
}
