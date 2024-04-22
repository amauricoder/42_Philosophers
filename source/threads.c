/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:59:44 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/22 10:29:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    start_threads(t_data *data)
{
    int i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		data->ph[i].id = i + 1;
		if (pthread_create(data->ph[i].thread, NULL,
			&start_routine, &data->ph[i]) != 0)
			errormsg_and_exit("Error\nError creating threads", EXIT_FAILURE);
		i ++;
	}
}

void    *start_routine(void *arg)
{
	t_philo *philo;
	size_t current_time;

	philo = (t_philo *)arg;
	printf("Philosopher %i\n", philo->id);
	while (1)
	{
		current_time = get_time() - philo->main->start_time;
		//solve deadlock issue here
		//mutex
		pthread_mutex_lock(philo->left_fork);
		printf("%zu %i Has taken a fork\n", current_time, philo->id);

		pthread_mutex_lock(philo->right_fork);
		printf("%zu %i Has taken a fork\n", current_time, philo->id);

		printf("%zu %i Is eating\n", current_time, philo->id);
		usleep(5000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		//mutex unlock
		//mutex unlock
		//printf("Is sleeping\n");
		//printf("Is thinking\n");
		//printf("died\n");
	}
	return (NULL);
}

//timestamp_in_ms X has taken a fork
//timestamp_in_ms X is eating
//timestamp_in_ms X is sleeping
//timestamp_in_ms X is thinking
//timestamp_in_ms X died