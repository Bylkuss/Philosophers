/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:07:40 by loadjou           #+#    #+#             */
/*   Updated: 2022/12/16 20:34:01 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/* ************************************************************************** */
/*									<MACROS>								  */
/* ************************************************************************** */

# define NEGNUMS "Error! no parameter can be < 1\n"
# define MAXPHIL "Too many philos! Don't try to fu my process I set it to 200\n"

/* ************************************************************************** */
/*									</MACROS>								  */
/* ************************************************************************** */
/* ************************************************************************** */
/*									</STRUCTS>								  */
/* ************************************************************************** */
typedef struct s_philos
{
	pthread_t		thread;
	size_t			id;
	size_t			times_ate;
	size_t			time_to_die;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	struct s_table	*table;
	int				*alive;
}					t_philos;

typedef struct s_table
{
	size_t			n_thread;
	size_t			philos_nb;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			repeat_time;
	time_t			time_begin;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	is_dead;
	pthread_t		check_death;
	int				alive;
	struct s_philos	*philos;
}					t_table;

/* ************************************************************************** */
/*									</STRUCTS>								  */
/* ************************************************************************** */
/* ************************************************************************** */
/*								<PROTOTYPES>								  */
/* ************************************************************************** */

/*	utils.c	*/
long				ft_atol(char *str);
int					only_digits(char **argv);
void			    free_structs(t_table *tab);
/*	logs.c	*/
void				print_data(t_table *tab);
/*	main.c	*/
void				check_provided_values(t_table *tab);
void*				routine(void *args);
/*	philo.c	*/
void			    destroy_threads(t_table *tab);
void			    join_threads(t_table *tab);
void			    init_threads(t_table *tab);
void				init_mutex(t_table *tab);
/*	philo.c	*/
void*				routine(void *args);
/* ************************************************************************** */
/*									</PROTOTYPES>							  */
/* ************************************************************************** */
#endif