/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/23 16:38:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int		start_threads(t_data *data)
{
    int i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		data->ph[i].id = i + 1;
		if (pthread_create(data->ph[i].thread, NULL,
			&start_routine, &data->ph[i]) != 0)
			return (errormsg_and_exit("Error\nError creating threads",
				EXIT_FAILURE));
		i ++;
	}
	return (EXIT_SUCCESS);
}

void    *start_routine(void *arg)
{
	t_philo *philo;
	size_t current_time;

	philo = (t_philo *)arg;
	int i = 0;

	while (i < 3)
	{
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork->fork);
			current_time = get_time() - philo->main->start_time;
			printf("%zu %i Has taken the fork %i\n", current_time, 
				philo->id, philo->left_fork->fork_id);
			pthread_mutex_lock(philo->right_fork->fork);
			current_time = get_time() - philo->main->start_time;
			printf("%zu %i Has taken a fork %i\n", current_time, 
				philo->id, philo->right_fork->fork_id);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork->fork);
			current_time = get_time() - philo->main->start_time;
			printf("%zu %i Has taken a fork %i\n", current_time, 
				philo->id, philo->right_fork->fork_id);
			pthread_mutex_lock(philo->left_fork->fork);
			current_time = get_time() - philo->main->start_time;
			printf("%zu %i Has taken the fork %i\n", current_time, philo->id, 
				philo->left_fork->fork_id);
		}
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i Is eating\n", current_time, philo->id);
		usleep(philo->main->eat_timeto);

		pthread_mutex_unlock(philo->left_fork->fork);
		pthread_mutex_unlock(philo->right_fork->fork);

		current_time = get_time() - philo->main->start_time;
		printf("%zu %i Is sleeping\n", current_time, philo->id);
		usleep(philo->main->sleep_timeto);
		

		i ++;
	}
	return (NULL);
}

//timestamp_in_ms X has taken a fork
//timestamp_in_ms X is eating
//timestamp_in_ms X is sleeping
//timestamp_in_ms X is thinking
//timestamp_in_ms X died