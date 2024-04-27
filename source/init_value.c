/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:48:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/25 16:34:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Init struct  and philo struct with initial data,
 * init mutexes and atributes the left/right fork ptr to the equivalent mutex.
 * @return A struct with data filled.
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->argc_qt = argc;
	data->philoandfork_qt = ft_atoi(argv[1]);
	data->die_timeto = ft_atoi(argv[2]) * 1000;
	data->eat_timeto = ft_atoi(argv[3]) * 1000;
	data->sleep_timeto = ft_atoi(argv[4]) * 1000;
	data->is_someone_dead = 0;
	data->qt_philo_full = 0;
	data->table_is_ready = 0;
	if (argc > 5)
		data->musteat_times = ft_atoi(argv[5]);
	data->start_time = get_time();
	alloc_and_init_mutex(data->philoandfork_qt, data);
	data->ph = malloc(sizeof(t_philo) * data->philoandfork_qt);
	if (!data->ph)
		return ;
	init_philo(data);
}

void	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++ i < data->philoandfork_qt)
	{
		data->ph[i].main = data;
		data->ph[i].left_fork = NULL;
		data->ph[i].right_fork = NULL;
		data->ph[i].id = 0;
		data->ph[i].meals_qt = 0;
		data->ph[i].is_full = 0;
		data->ph[i].last_meal_time = 0;
		data->ph[i].thread = malloc(sizeof(pthread_t));
		if (!data->ph[i].thread)
			return ;
	}
}

/**
* @brief Allocate memory for the treaton the main struct.
* @param qt Quantity of space necessary to alloc.
*/
pthread_t	*alloc_thread(int qt)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * qt);
	if (!thread)
		return (NULL);
	return (thread);
}

/**
 * @brief Alloc space for mutexes and init every mutex individually.
 * @param qt Quantity of space necessary to alloc.
*/
void	alloc_and_init_mutex(int qt, t_data *data)
{
	int	i;

	data->all_forks = malloc(sizeof(t_fork) * qt);
	if (!data->all_forks)
		return ;
	i = 0;
	while (i < qt)
	{
		data->all_forks[i].fork_id = i + 1;
		data->all_forks[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!data->all_forks[i].fork)
			return ;
		pthread_mutex_init(data->all_forks[i].fork, NULL);
		i ++;
	}
	data->table_mutex = malloc(sizeof(pthread_mutex_t));
	data->full_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->table_mutex, NULL);
	pthread_mutex_init(data->full_mutex, NULL);
}

/**
 * @brief Gives the pointers of the left and right fork of the philo struct
 * to the corresponding mutex
 * @param data Main struct.
*/
int	attribute_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		data->ph[i].left_fork = &data->all_forks[i];
		data->ph[i].right_fork = &data->all_forks[i - 1];
		if (i == 0)
			data->ph[i].right_fork
				= &data->all_forks[data->philoandfork_qt - 1];
		if (!data->ph[i].right_fork || !data->ph[i].left_fork)
			return (errormsg_and_exit("Error\nAtr Forks!",
					EXIT_FAILURE));
		i ++;
	}
	return (EXIT_SUCCESS);
}
