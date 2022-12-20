/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:44:29 by loadjou           #+#    #+#             */
/*   Updated: 2022/12/16 21:07:04 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *check_death(void *args)
{
    (void) args;
    return 0;
}

void    init_mutex(t_table *tab)
{
    size_t i;
    
    tab->forks = malloc(sizeof(pthread_mutex_t) * tab->philos_nb);
    while (i < tab->philos_nb)
    {
        pthread_mutex_init(&tab->forks[i], NULL);
        i++;
    }       
    pthread_mutex_init(&tab->msg, NULL);
    pthread_mutex_init(&tab->is_dead, NULL);
}


void    init_threads(t_table *tab)
{
    size_t i = 0;
    while(i < tab->philos_nb)
    {
        tab->philos[i].id = i + 1;
        pthread_create(&tab->philos[i].thread, NULL, &routine, (void *)&tab->philos[i]);
        i++;
    }
    // pthread_create(&tab->check_death, &check_death, (void *)tab, NULL);
}

void    join_threads(t_table *tab)
{
    size_t i = 0;
    while(i < tab->philos_nb)
    {
        pthread_join(tab->philos[i].thread, NULL);
        i++;
    }
    // pthread_join(tab->check_death, (void *) &tab);
}

void    destroy_threads(t_table *tab)
{
    size_t i = 0;
    while(i < tab->philos_nb)
    {
        pthread_mutex_destroy(&tab->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&tab->msg);
    pthread_mutex_destroy(&tab->is_dead);

}