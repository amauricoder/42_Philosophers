/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:41 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/04 14:11:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Treat the case of only 1 philosopher.
 * He will never be able to eat, then he will just pacefully die.
 * @param arg Is casted to t_philo with the structure of the philosophers.
*/
void	*lonely_dinner(void *arg)
{
	size_t	current_time;
	t_philo	*philo;

	philo = (t_philo *)arg;
	current_time = get_time() - philo->main->start_time;
	pthread_mutex_lock(philo->left_fork->fork);
	printf("%zu %i has taken a fork\n", current_time, philo->id);
	return (NULL);
}

/**
 * @brief Checks if the simulation is stopped.
 * @return 1 if the simulation is stopped, 0 if not.
*/
int	stop_sim(t_philo *philo)
{
	pthread_mutex_lock(philo->main->full_mutex);
	if (philo->main->stop_simulation)
	{
		pthread_mutex_unlock(philo->main->full_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->main->full_mutex);
	return (0);
}

int	even_philo_take_fork(t_philo *philo, size_t current_time)
{
	pthread_mutex_lock(philo->left_fork->fork);
	current_time = get_time() - philo->main->start_time;
	if (stop_sim(philo))
		return (EXIT_FAILURE);
	printf("%zu %i has taken a fork\n", current_time,
		philo->id);
	pthread_mutex_lock(philo->right_fork->fork);
	current_time = get_time() - philo->main->start_time;
	if (stop_sim(philo))
		return (EXIT_FAILURE);
	printf("%zu %i has taken a fork\n", current_time,
		philo->id);
	return (EXIT_SUCCESS);
}

int odd_philo_take_fork(t_philo *philo, size_t current_time)
{
	pthread_mutex_lock(philo->right_fork->fork);
	current_time = get_time() - philo->main->start_time;
	if (stop_sim(philo))
		return (EXIT_FAILURE);
	printf("%zu %i has taken a fork\n", current_time,
		philo->id);
	pthread_mutex_lock(philo->left_fork->fork);
	current_time = get_time() - philo->main->start_time;
	if (stop_sim(philo))
		return (EXIT_FAILURE);
	printf("%zu %i has taken a fork\n", current_time,
		philo->id);
	return (EXIT_SUCCESS);
}
