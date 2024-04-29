/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:13:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/29 12:11:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	has_taken_a_fork(t_philo *philo, size_t current_time);
static void	is_eating(t_philo *philo, size_t current_time);
static void	is_sleeping(t_philo *philo, size_t current_time);
static void	is_thinking(t_philo *philo, size_t current_time);

void	*dinner_routine(void *arg)
{
	t_philo	*philo;
	size_t	current_time;

	current_time = 0;
	philo = (t_philo *)arg;
	preparing_table(philo);
	while (1)
	{
		pthread_mutex_lock(philo->main->full_mutex);
		if (philo->main->qt_philo_full == philo->main->philoandfork_qt)
		{
			pthread_mutex_unlock(philo->main->full_mutex);
			break;
		}	
		pthread_mutex_unlock(philo->main->full_mutex);
		has_taken_a_fork(philo, current_time);
		is_eating(philo, current_time);
		is_sleeping(philo, current_time);
		is_thinking(philo, current_time);
	}
	return (NULL);
}

static void	has_taken_a_fork(t_philo *philo, size_t current_time)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
		pthread_mutex_lock(philo->right_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
		pthread_mutex_lock(philo->left_fork->fork);
		current_time = get_time() - philo->main->start_time;
		printf("%zu %i has taken a fork\n", current_time,
			philo->id);
	}
}

static void	is_eating(t_philo *philo, size_t current_time)
{
	current_time = get_time() - philo->main->start_time;
	pthread_mutex_lock(philo->main->full_mutex);
	philo->last_meal_time = current_time;
	philo->main->die_timeto += philo->last_meal_time;
	//printf(ORANGE"%i die_timeto is eating\n"RESET, philo->main->die_timeto);
	pthread_mutex_unlock(philo->main->full_mutex);
	printf("%zu %i is eating\n", current_time, philo->id);
	philo->meals_qt ++;
	usleep(philo->main->eat_timeto);
	pthread_mutex_lock(philo->main->full_mutex);
	if (philo->meals_qt == philo->main->musteat_times)
	{
		philo->is_full ++;
		philo->main->qt_philo_full ++;
		printf(RED"Philo %i is full! and ate %i times\n"RESET, philo->id, philo->meals_qt);
	}
	pthread_mutex_unlock(philo->main->full_mutex);
	pthread_mutex_unlock(philo->left_fork->fork);
	pthread_mutex_unlock(philo->right_fork->fork);
}

static void	is_sleeping(t_philo *philo, size_t current_time)
{
	
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i is sleeping\n", current_time, philo->id);
	usleep(philo->main->sleep_timeto);
}

static void	is_thinking(t_philo *philo, size_t current_time)
{
	current_time = get_time() - philo->main->start_time;
	printf("%zu %i is thinking\n", current_time, philo->id);
}
